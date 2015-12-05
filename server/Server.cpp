//
// Server.cpp for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Mon Nov 30 15:35:42 2015 Nicolas Charvoz
// Last update Sat Dec  5 10:44:45 2015 Joris Bertomeu
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
  this->_network->create(4252, AF_INET, std::string(""));
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
