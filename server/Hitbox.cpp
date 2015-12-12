//
// Hitbox.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sat Dec 12 11:06:08 2015 Louis Audibert
// Last update Sat Dec 12 11:23:26 2015 Louis Audibert
//

#include "Hitbox.hh"

Hitbox::Hitbox()
{
  std::cout << "new Hitbox Component created" << std::endl;
}

Hitbox::~Hitbox()
{
  std::cout << "Hitbox Component destroyed" << std::endl;
}

std::vector<Case*>	Hitbox::getHitbox()
{
  return (_hitbox);
}

void			Hitbox::setHitbox(std::vector<Case*> cases)
{
  _hitbox = cases;
}
