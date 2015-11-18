//
// SystemHealth.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Nov 30 02:02:55 2015 Louis Audibert
// Last update Mon Nov 30 06:00:48 2015 Louis Audibert
//

#include "SystemHealth.hh"

SystemHealth::SystemHealth()
{
  _component = new Health();
}

SystemHealth::~SystemHealth()
{
  std::cout << "SystemHealth Destroyed" << std::endl;
}

bool	SystemHealth::update(int health)
{
  dynamic_cast<Health*>(_component)->setLife(health);
  return(true);
}
