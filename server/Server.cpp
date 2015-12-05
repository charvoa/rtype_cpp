//
// Server.cpp for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Mon Nov 30 15:35:42 2015 Nicolas Charvoz
// Last update Sat Dec  5 12:31:32 2015 Joris Bertomeu
//

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
  this->_network->listen(10);
}

void Server::run()
{
  Socket	*client;

  std::cout << "Server :: Run" << std::endl;
  while (1) {
    client = dynamic_cast<Socket*>(this->_network->accept());
    std::cout << (char*) client->read(4096) << std::endl;
  }
}

bool Server::createGame() {
  return true;
}

bool Server::createRoom() {
  return true;
}
