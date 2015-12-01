//
// Client.cpp for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Dec  1 14:22:49 2015 Nicolas Charvoz
// Last update Tue Dec  1 14:24:35 2015 Nicolas Charvoz
//

#include "Client.hh"

Client::Client() {}

Client::~Client() {}

ANetwork *Client::getNetwork() const {
  return _network;
}
