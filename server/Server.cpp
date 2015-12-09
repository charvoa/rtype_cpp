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
  this->_network = new Network();
}

Server::~Server() {}

void Server::init(int port)
{
  std::cout << "Server :: Init" << std::endl;
  this->_network->init(port, ANetwork::TCP_MODE);
  this->_network->bind();
  this->_network->listen(24);
  this->_commandManager.addFunction(C_CREATEROOM, &Server::createRoom);
  this->_commandManager.addFunction(C_JOINROOM, &Server::joinRoom);
  this->_commandManager.addFunction(C_LAUNCHGAME, &Server::createGame);
  this->_commandManager.addFunction(C_PLAYERLEFT, &Server::playerLeftRoom);
}

void Server::run()
{
  Client	*client;

  std::cout << "Server :: Run" << std::endl;
  while (1)
    {
      client = new Client(this->_network->select());
      this->_commandManager.executeCommand(*(reinterpret_cast<ANetwork::t_frame*>((client->getSocket()->read(sizeof(ANetwork::t_frame))))),
      client, this);
    }
}

void sendMessage(std::vector<Client> &c ,unsigned char type)
{
   for (std::vector<Client>::iterator it = c.begin();
	 it != c.end() ; ++it)
      {
	ANetwork::t_frame frame = CreateRequest::create(type, CRC::calcCRC(""), 0, "");
	(*it).getSocket()->write(reinterpret_cast<void*>(&frame), sizeof(ANetwork::t_frame));
      }
}

void *newGameThread(void *data)
{
  Server::serializeThread *s = reinterpret_cast<Server::serializeThread*>(data);

  std::cout << "Server :: void* newGameThread" << std::endl;

  Server *me = s->server;

  Parameters p = me->_roomManager.getRoombyId(s->frame.data).getParameters();
  std::vector<Client> c = me->_roomManager.getRoombyId(s->frame.data)
    .getAllPlayers();

  if ((me->_gameManager.createGame(p, c, s->frame.data)))
    {
      sendMessage(c, (unsigned char)S_GAME_LAUNCHED);
      me->_gameManager.getGameById(s->frame.data).run();
      me->_roomManager.deleteRoom(s->frame.data);
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

  ThreadFactory *tF = new ThreadFactory;
  std::unique_ptr<AThread> t1(tF->createThread());

  t1->attach(&newGameThread, reinterpret_cast<void*>(s));
  t1->run();
  t1->join();

  return true;
}

bool Server::createRoom(ANetwork::t_frame frame, void *data)
{
  (void) frame;
  Client	&client = *reinterpret_cast<Client *>(data);
  _roomManager.createNewRoom(client);

  return true;
}

bool	Server::joinRoom(ANetwork::t_frame frame, void *data)
{
   Client	&client = *reinterpret_cast<Client *>(data);

   std::cout << "SERVER :: JoinRoom" << std::endl;
   _roomManager.getRoombyId(frame.data).addPlayer(client);
   return true;
}

bool	Server::playerLeftRoom(ANetwork::t_frame frame, void *data)
{
  Client	&client = *reinterpret_cast<Client *>(data);
  Room	room = _roomManager.getRoombyId(frame.data);
  if (room.getAllPlayers().size() == 1)
    _roomManager.deleteRoom(frame.data);
  else
    {
      room.deletePlayer(client);
    }
  return true;
}
