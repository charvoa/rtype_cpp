//
// Missile.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sat Nov 28 05:53:48 2015 Louis Audibert
// Last update Thu Dec  3 05:19:41 2015 Louis Audibert
//

#include <Missile.hh>

Missile::Missile()
{
  _dmg = 50;
}

Missile::~Missile()
{
  std::cout << "Missile Component Destroyed" << std::endl;
}

int	Missile::getDamages() const
{
  return (_dmg);
}
