//
// Player.cpp for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Dec  1 14:29:32 2015 Nicolas Charvoz
// Last update Thu Dec  3 05:26:52 2015 Louis Audibert
//

#include <Player.hh>

Player::Player(int id, const Client &c) : AEntity(id)
{
  _client = c;
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
