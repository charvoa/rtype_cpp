//
// Player.cpp for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Dec  1 14:29:32 2015 Nicolas Charvoz
// Last update Tue Dec  1 15:25:37 2015 Nicolas Charvoz
//

#include "Player.hh"

// CHANGE ID BY c.getId()

Player::Player(const Client &c) : AEntity(_id)
{
}

Player::~Player() {}

const Client &Player::getClient() const
{
  return _client;
}

const std::string &Player::getUsername() const
{
  return _username;
}

bool Player::isOwner() const
{
  return _isOwner;
}

int Player::getScore() const
{
  return _score;
}
