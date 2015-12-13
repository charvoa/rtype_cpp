//
// Rifle.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sat Nov 28 05:53:48 2015 Louis Audibert
// Last update Sun Dec 13 04:49:21 2015 Louis Audibert
//

#include <ComponentRiffle.hh>

ComponentRiffle::ComponentRiffle()
{
  _dmg = 20;
}

ComponentRiffle::~ComponentRiffle()
{
  std::cout << "Rifle Component Destroyed" << std::endl;
}

int	ComponentRiffle::getDamages() const
{
  return (_dmg);
}
