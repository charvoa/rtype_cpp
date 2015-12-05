//
// Client.cpp for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Dec  1 14:22:49 2015 Nicolas Charvoz
// Last update Thu Dec  3 05:08:46 2015 Louis Audibert
//

#include <Client.hh>

Client::Client() {}

Client::~Client() {}

ISocket *Client::getSocket() const {
  return _socket;
}
