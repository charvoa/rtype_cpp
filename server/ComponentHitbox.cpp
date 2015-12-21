//
// Hitbox.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sat Dec 12 11:06:08 2015 Louis Audibert
// Last update Mon Dec 21 10:26:34 2015 Nicolas Charvoz
//

#include <ComponentHitbox.hh>

ComponentHitbox::ComponentHitbox()
{
  //  std::cout << "new Hitbox Component created" << std::endl;
}

ComponentHitbox::~ComponentHitbox()
{
  //std::cout << "Hitbox Component destroyed" << std::endl;
}

std::list<Case*>	ComponentHitbox::getHitbox()
{
  return (_hitbox);
}

void			ComponentHitbox::setHitbox(std::list<Case*> cases)
{
  _hitbox = cases;
}
