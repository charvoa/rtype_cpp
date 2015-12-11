//
// Client.cpp for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Sat Dec 12 10:33:52 2015 Nicolas Charvoz
// Last update Sat Dec 12 10:33:53 2015 Nicolas Charvoz
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
