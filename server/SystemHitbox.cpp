//
// SystemHitbox.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sat Dec 12 11:06:54 2015 Louis Audibert
// Last update Sat Dec 12 11:54:38 2015 Louis Audibert
//

#include <SystemHitbox.hh>

SystemHitbox::SystemHitbox()
{
  std::cout << "new SystemHitbox created" << std::endl;
}

SystemHitbox::~SystemHitbox()
{
  std::cout << "SystemHitbox destroyed" << std::endl;
}

bool	SystemHitbox::update(std::vector<Case*> hitbox)
{
  dynamic_cast<Hitbox*>(_component)->setHitbox(hitbox);
  return (true);
}
