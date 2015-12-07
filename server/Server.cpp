//
// Server.cpp for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Mon Nov 30 15:35:42 2015 Nicolas Charvoz
// Last update Mon Dec  7 07:48:30 2015 Antoine Garcia
//

#include <Network.hpp>
#include <Server.hh>

Server::Server()
{
  this->_network = new Network();
}

Server::~Server() {}

void Server::init()
{
  std::cout << "Server :: Init" << std::endl;
  this->_network->init(4253, ANetwork::TCP_MODE);
  this->_network->bind();
  this->_network->listen(24);
  this->_commandManager.addFunction(C_CREATEROOM, &Server::createRoom);
  this->_commandManager.addFunction(C_JOINROOM, &Server::joinRoom);
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

bool Server::createGame(ANetwork::t_frame frame, void *data) {
  (void) frame;
  (void) data;
  return true;
}

bool Server::createRoom(ANetwork::t_frame frame, void *data) {
  Client	&client = *reinterpret_cast<Client *>(data);

  (void) frame;
  _roomManager.createNewRoom(client);
  return true;
}

bool	Server::joinRoom(ANetwork::t_frame frame, void *data)
{
   Client	&client = *reinterpret_cast<Client *>(data);

   _roomManager.getRoombyId(frame.data).addPlayer(client);
   return true;
}
