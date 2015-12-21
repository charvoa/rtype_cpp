//
// SystemHitbox.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sat Dec 12 11:06:54 2015 Louis Audibert
// Last update Mon Dec 21 10:26:00 2015 Nicolas Charvoz
//

#include <SystemHitbox.hh>

SystemHitbox::SystemHitbox()
{
  _component = new ComponentHitbox();
  //  std::cout << "new SystemHitbox created" << std::endl;
}

SystemHitbox::~SystemHitbox()
{
  //std::cout << "SystemHitbox destroyed" << std::endl;
}

bool	SystemHitbox::update(std::list<Case*> hitbox)
{
  dynamic_cast<ComponentHitbox*>(_component)->setHitbox(hitbox);
  return (true);
}
