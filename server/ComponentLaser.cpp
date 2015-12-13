//
// Laser.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sat Nov 28 05:53:48 2015 Louis Audibert
// Last update Sun Dec 13 04:54:24 2015 Louis Audibert
//

#include <ComponentLaser.hh>

ComponentLaser::ComponentLaser()
{
  _dmg = 100;
}

ComponentLaser::~ComponentLaser()
{
  std::cout << "Laser Component Destroyed" << std::endl;
}

int	ComponentLaser::getDamages() const
{
  return (_dmg);
}
