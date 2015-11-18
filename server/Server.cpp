//
// Server.cpp for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Mon Nov 30 15:35:42 2015 Nicolas Charvoz
// Last update Wed Nov 18 14:02:58 2015 Joris Bertomeu
//

#include "Server.hh"

Server::Server()
{
  this->_network = new Network();
}

Server::~Server() {}

void Server::init()
{
  this->_network->create(4242, AF_INET, std::string(""));
}

void Server::run() {}

bool Server::createGame() {}

bool Server::createRoom() {}
