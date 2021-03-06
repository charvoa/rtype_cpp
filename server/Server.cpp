//
// Server.cpp for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Mon Nov 30 15:35:42 2015 Nicolas Charvoz
//

#ifdef _WIN32
# include <NetworkWin.hpp>
#else
# include <Network.hpp>
#endif

#include <Server.hh>

Server::Server()
{
  _port = 40000;
  this->_network = new Network();
}

Server::~Server() {}

void Server::init(int port)
{
  std::cout << "Server :: Init" << std::endl;
  this->_network->init(port, ANetwork::TCP_MODE);
  this->_network->bind();
  this->_network->listen(24);
  this->_commandManager.addFunction(C_HANDSHAKE, &Server::handshake);
  this->_commandManager.addFunction(C_CREATE_ROOM, &Server::createRoom);
  this->_commandManager.addFunction(C_JOIN_ROOM, &Server::joinRoom);
  this->_commandManager.addFunction(C_LAUNCH_GAME, &Server::createGame);
  this->_commandManager.addFunction(C_PLAYER_LEFT, &Server::playerLeftRoom);
  this->_commandManager.addFunction(C_CHANGE_SETTINGS, &Server::changeRoomSettings);
  this->_botManager = new BotManager("../libs/");
  this->_roomManager.setBotManager(this->_botManager->getBotList());
  this->_monitoring.start(this);
  // std::list<Bot*> toto = this->_botManager->getBotList();
  // for (std::list<Bot*>::iterator it = toto.begin();
  //      it != toto.end(); ++it) {
  //   std::cout << ">> " << ((*it)->_sprite) << std::endl;
  // }
}

void Server::run()
{
  Client	*client;
  void		*data;

  std::cout << "Server :: Run" << std::endl;
  while (1)
    {
      client = new Client(this->_network->select());
      if (!(data = client->getSocket()->read(sizeof(ANetwork::t_frame)))) { //Client Disconnected
	this->_network->unlistenSocket(client->getSocket());
	try {
	  _gameManager.getGameByClient(client)->deletePlayer(client);
	} catch (const std::exception &e)
	  {
	    std::cout << e.what() << std::endl;
	    try{
	      _roomManager.getRoomByClient(client).deletePlayer(client);
	    }
	    catch(const std::exception &ee){
	      std::cout << ee.what() << std::endl;
	    }
	  }
	continue;
      }
      ANetwork::t_frame *frame = reinterpret_cast<ANetwork::t_frame*>(data);
      if (frame->idRequest < 110)
	this->_commandManager.executeCommand(*(reinterpret_cast<ANetwork::t_frame*>(data)),
					   client, this);
    }
}

void sendMessage(std::list<Client *> &c ,unsigned char type)
{
   for (std::list<Client *>::iterator it = c.begin();
	 it != c.end() ; ++it)
      {
	ANetwork::t_frame frame = CreateRequest::create(type,
							CRC::calcCRC(""), 0, "");
	(*it)->getSocket()->write(reinterpret_cast<void*>(&frame),
				  sizeof(ANetwork::t_frame));
      }
}

void *newGameThread(void *data)
{
  Server::serializeThread *s = reinterpret_cast<Server::serializeThread*>(data);

  Server *me = s->server;

  Parameters *p = me->_roomManager.getRoombyId(s->frame.data).getParameters();
  std::list<Client *> c = me->_roomManager.getRoombyId(s->frame.data).getAllPlayers();

  std::stringstream ss;

  if ((me->_gameManager.createGame(*p, c, s->frame.data, s->port,
				   me->_botManager->getBotList())))
    {
      sendMessage(c, (unsigned char)S_GAME_LAUNCHED);
      for (std::list<Client *>::iterator it = c.begin();
	   it != c.end() ; ++it)
	{
	  ss << me->_port;
	  ss << ";";
	  ss << (*it)->getSocket()->getFd();
	  ANetwork::t_frame frameToSend = CreateRequest::create((unsigned char)
								S_INIT_UDP,
								CRC::calcCRC(ss.str().c_str()),
								ss.str().size(),
								ss.str().c_str());
	  (*it)->getSocket()->write(reinterpret_cast<void*>(&frameToSend),
				    sizeof(ANetwork::t_frame));
	  ss.str("");
	  ss.clear();
	}
      me->_roomManager.deleteRoom(s->frame.data);
      me->_gameManager.getGameById(s->frame.data).run();
    }
  else
    {
      sendMessage(c, (unsigned char)S_GAME_NOT_LAUNCHED);
    }

  return data;
}

bool Server::createGame(ANetwork::t_frame frame, void *data)
{
  Server::serializeThread *s = new Server::serializeThread;

  s->server = this;
  s->client = reinterpret_cast<Client*>(data);
  s->frame = frame;
  s->port = _port++;


  // TELL CLIENT WHO HE IS FOR UDP
  std::list<Client *> c = _roomManager.getRoombyId(s->frame.data).getAllPlayers();

  ThreadFactory *tF = new ThreadFactory;
  std::unique_ptr<AThread> t1(tF->createThread());

  t1->attach(&newGameThread, reinterpret_cast<void*>(s));
  t1->run();
  // t1->join();

  return true;
}

bool Server::createRoom(ANetwork::t_frame frame, void *data)
{
  (void) frame;
  Client	*client = reinterpret_cast<Client *>(data);
  _roomManager.createNewRoom(client);

  return true;
}

bool	Server::joinRoom(ANetwork::t_frame frame, void *data)
{
   Client	*client = reinterpret_cast<Client *>(data);

   try {
   _roomManager.getRoombyId(frame.data).addPlayer(client);
   }catch(const std::exception &e)
     {
       std::string sendData = e.what();
       ANetwork::t_frame frameToSend = CreateRequest::create(S_JOIN_ERROR, CRC::calcCRC(sendData), 0, sendData);
       client->getSocket()->write(reinterpret_cast<void *>(&frameToSend), sizeof(ANetwork::t_frame));
       std::cout << e.what() << std::endl;
     }
   return true;
}

bool	Server::handshake(ANetwork::t_frame frame, void *data)
{
  (void) frame;
  (void) data;
  return true;
}

bool	Server::playerLeftRoom(ANetwork::t_frame frame, void *data)
{
  Client	*client = reinterpret_cast<Client *>(data);

  Room	room = _roomManager.getRoombyId(frame.data);
  if (room.getAllPlayers().size() == 1)
    _roomManager.deleteRoom(frame.data);
  else
    {
      room.deletePlayer(client);
    }
  return true;
}

bool Server::changeRoomSettings(ANetwork::t_frame frame, void *data)
{
  Client	*client = reinterpret_cast<Client *>(data);
  try
    {
      Room room = _roomManager.getRoomByClient(client);
      Parameters param;
      E_Difficulty	difficulty = (E_Difficulty)std::atoi(frame.data);
      param.setDifficulty(difficulty);
      room.setParameters(param);
      std::list<Client*> clients = room.getAllPlayers();
      ANetwork::t_frame frameToSend = CreateRequest::create(S_ROOM_SETTINGS_CHANGED,CRC::calcCRC(frame.data),0,frame.data);
      for(std::list<Client*>::iterator it = clients.begin();it != clients.end(); ++it)
	{
	  (*it)->getSocket()->write(reinterpret_cast<void*>(&frameToSend),sizeof(ANetwork::t_frame));
	}
    } catch(const std::exception &e)
    {
      std::cout << e.what() << std::endl;
    }
  return true;
}
