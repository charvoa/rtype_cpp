//
// Server.cpp for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Mon Nov 30 15:35:42 2015 Nicolas Charvoz
// Last update Thu Nov 19 03:22:30 2015 Joris Bertomeu
//

#include "Server.hh"

Server::Server()
{
  this->_network = new Network();
}

Server::~Server() {}

void Server::init()
{
  std::cout << "Server :: Init" << std::endl;
  this->_network->create(12343, AF_INET, std::string(""));
  this->_network->bind();
  this->_network->listen();
}

void Server::run()
{
  Socket	*client;

  std::cout << "Server :: Run" << std::endl;
  client = dynamic_cast<Socket*>(this->_network->accept());

  (void)client;
}

bool Server::createGame() {
  return true;
}

bool Server::createRoom() {
  return true;
}
