//
// SystemHealth.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Nov 30 02:02:55 2015 Louis Audibert
// Last update Mon Dec 21 01:33:39 2015 Louis Audibert
//

#include <SystemHealth.hh>

SystemHealth::SystemHealth()
{
  _component = new ComponentHealth();
}

SystemHealth::~SystemHealth()
{
}

bool	SystemHealth::update(int health)
{
  dynamic_cast<ComponentHealth*>(_component)->setLife(health);
  return(true);
}
