//
// Laser.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sat Nov 28 05:53:48 2015 Louis Audibert
// Last update Sat Nov 28 05:55:56 2015 Louis Audibert
//

#include "Laser.hh"

Laser::Laser()
{
  _dmg = 100;
}

Laser::~Laser()
{
  std::cout << "Laser Component Destroyed" << std::endl;
}

int	Laser::getDamages() const
{
  return (_dmg);
}
