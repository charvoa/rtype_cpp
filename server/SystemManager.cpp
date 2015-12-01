//
// SystemManager.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Nov 30 02:32:03 2015 Louis Audibert
// Last update Mon Nov 30 08:01:57 2015 Louis Audibert
//

#include "SystemManager.hh"

SystemManager::SystemManager()
{

}

SystemManager::~SystemManager()
{
  std::cout << "SystemManager Destroyed." << std::endl;
}

ASystem *SystemManager::getSystemByComponent(E_COMPONENT type)
{
  for (std::vector<ASystem*>::iterator it = _systems.begin(); it != _systems.end(); ++it)
    {
      if ((dynamic_cast<SystemGun*>(*it)) && (type == E_MISSILE || type == E_RIFLE || type == E_LASER))
	return (*it);
      else if ((dynamic_cast<SystemPos*>(*it)) && type == E_POSITION)
	return (*it);
      else if ((dynamic_cast<SystemHealth*>(*it)) && type == E_HEALTH)
	return (*it);
    }
  return (NULL);
}

void	SystemManager::addSystemByType(E_COMPONENT type)
{
  if (!(getSystemByComponent(type)))
    {
      switch (type)
	{
	case E_POSITION:
	  _systems.push_back(new SystemPos());
	  break;
	case E_HEALTH:
	  _systems.push_back(new SystemHealth());
	  break;
	default:
	  _systems.push_back(new SystemGun(type));
	  break;
	}
    }
}
