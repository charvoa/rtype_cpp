//
// Player.cpp for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Dec  1 14:29:32 2015 Nicolas Charvoz
//

#include <Player.hh>

Player::Player(int id, const Client &c) : AEntity(id)
{
  _client = c;
  _name = "player" + std::to_string(id);
  addSystem(E_POSITION);
  addSystem(E_HEALTH);
}

Player::~Player() {}

Client &Player::getClient()
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

void Player::setScore(int s)
{
  _score = s;
}
