//
// Hitbox.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sat Dec 12 11:06:08 2015 Louis Audibert
// Last update Mon Dec 21 01:34:11 2015 Louis Audibert
//

#include <ComponentHitbox.hh>

ComponentHitbox::ComponentHitbox()
{
}

ComponentHitbox::~ComponentHitbox()
{
}

std::list<Case*>	ComponentHitbox::getHitbox()
{
  return (_hitbox);
}

void			ComponentHitbox::setHitbox(std::list<Case*> cases)
{
  _hitbox = cases;
}
