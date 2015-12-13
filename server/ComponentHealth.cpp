//
// Health.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sat Nov 28 05:33:26 2015 Louis Audibert
// Last update Sun Dec 13 05:25:00 2015 Louis Audibert
//

#include <ComponentHealth.hh>

ComponentHealth::ComponentHealth()
{
  _nbLife = 3;
}

ComponentHealth::~ComponentHealth()
{
  std::cout << "Health component Destroyed" << std::endl;
}

unsigned int ComponentHealth::getLife() const
{
  return (_nbLife);
}

void	ComponentHealth::setLife(int life)
{
  _nbLife = life;
}
