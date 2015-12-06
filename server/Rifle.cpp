//
// Rifle.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sat Nov 28 05:53:48 2015 Louis Audibert
// Last update Thu Dec  3 05:28:01 2015 Louis Audibert
//

#include <Rifle.hh>

Rifle::Rifle()
{
  _dmg = 20;
}

Rifle::~Rifle()
{
  std::cout << "Rifle Component Destroyed" << std::endl;
}

int	Rifle::getDamages() const
{
  return (_dmg);
}
