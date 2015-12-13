//
// SystemHealth.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Nov 30 02:02:55 2015 Louis Audibert
// Last update Sun Dec 13 05:18:22 2015 Louis Audibert
//

#include <SystemHealth.hh>

SystemHealth::SystemHealth()
{
  _component = new ComponentHealth();
  std::cout << "new SystemHealth created." << std::endl;
}

SystemHealth::~SystemHealth()
{
  std::cout << "SystemHealth Destroyed" << std::endl;
}

bool	SystemHealth::update(int health)
{
  dynamic_cast<ComponentHealth*>(_component)->setLife(health);
  return(true);
}
