//
// Health.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sat Nov 28 05:33:26 2015 Louis Audibert
// Last update Sat Nov 28 05:47:14 2015 Louis Audibert
//

#include "Health.hh"

Health::Health()
{
  _nbLife = 100;
}

Health::~Health()
{

}

unsigned int Health::getLife() const
{
  return (_nbLife);
}

void	Health::setLife(int life)
{
  _nbLife = life;
}
