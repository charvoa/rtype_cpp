//
// Player.cpp for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Tue Dec  8 02:13:59 2015 Serge Heitzler
// Last update Tue Dec  8 04:42:43 2015 Serge Heitzler
//

#include "Player.hh"

Player::Player()
{
  _username = "toto";
  _isCurrentClient = true;
  _isReadyToStart = true;
}

Player::~Player()
{
  
}

void			Player::setUsename(std::string &username)
{
  _username = username;
}

void			Player::setCurrentClient(bool is)
{
  _isCurrentClient = is;
}

void			Player::setReadyToStart(bool is)
{
  _isReadyToStart = is;
}

std::string		&Player::getUsername()
{
  return _username;
}

bool			Player::getCurrentClient()
{
  return _isCurrentClient;
}

bool			Player::getReadyToStart()
{
  return _isReadyToStart;
}
