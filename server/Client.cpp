//
// Client.cpp for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Dec  1 14:22:49 2015 Nicolas Charvoz
// Last update Mon Dec  7 01:16:18 2015 Antoine Garcia
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
  (void)other;
  return false;
}
