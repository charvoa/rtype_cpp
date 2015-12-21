//
// Missile.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sat Nov 28 05:53:48 2015 Louis Audibert
// Last update Mon Dec 21 01:26:50 2015 Louis Audibert
//

#include <ComponentMissile.hh>

ComponentMissile::ComponentMissile()
{
  _dmg = 50;
}

ComponentMissile::~ComponentMissile()
{
}

int	ComponentMissile::getDamages() const
{
  return (_dmg);
}
