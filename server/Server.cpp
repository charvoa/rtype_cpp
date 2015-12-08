//
// Server.cpp for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Mon Nov 30 15:35:42 2015 Nicolas Charvoz
// Last update Tue Dec  8 15:20:00 2015 Nicolas Charvoz
//

#include <Network.hpp>
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
}

void Server::run()
{
  Client	*client;

  std::cout << "Server :: Run" << std::endl;
  while (1)
    {
      client = new Client(dynamic_cast<Socket*>(this->_network->select()));
      this->_commandManager.executeCommand(*(reinterpret_cast<ANetwork::t_frame*>((client->getSocket()->read(sizeof(ANetwork::t_frame))))),
					   client, this);
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
  std::string str(me->_roomManager.getRoombyId(s->frame.data).getId());

  me->_gameManager.createGame(p, c, str);

  me->_roomManager.deleteRoom(str);
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

   _roomManager.getRoombyId(frame.data).addPlayer(client);
   return true;
}
