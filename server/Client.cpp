//
// Client.cpp for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Dec  1 14:22:49 2015 Nicolas Charvoz
// Last update Wed Dec  9 05:30:57 2015 Antoine Garcia
//

#include <Client.hh>

Client::Client() {}

Client::Client(ISocket *socket):_socket(socket)
{}

Client::~Client() {}

ISocket *Client::getSocket() const {
  return _socket;
}

bool Client::operator==(const Client &other) const
{
  if (this->getSocket()->getFd() == other.getSocket()->getFd())
    return true;
  else
    return false;
}
