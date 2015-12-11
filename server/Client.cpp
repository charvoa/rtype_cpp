//
// Client.cpp for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Dec  1 14:22:49 2015 Nicolas Charvoz
// Last update Thu Dec 10 21:22:56 2015 Nicolas Charvoz
//

#include <Client.hh>

Client::Client() {}

Client::Client(ISocket *socket): _socket(socket)
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

bool Client::operator!=(const Client &other) const
{
  return (!(*this == other));
}
