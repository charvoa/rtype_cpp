//
// Health.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sat Nov 28 05:33:26 2015 Louis Audibert
// Last update Mon Nov 30 01:35:09 2015 Louis Audibert
//

#include "Health.hh"

Health::Health()
{
  _nbLife = 100;
}

Health::~Health()
{
  std::cout << "Health component Destroyed" << std::endl;
}

unsigned int Health::getLife() const
{
  return (_nbLife);
}

void	Health::setLife(int life)
{
  _nbLife = life;
}
