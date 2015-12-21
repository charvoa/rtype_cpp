//
// SystemManager.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Nov 30 02:32:03 2015 Louis Audibert
// Last update Mon Dec 21 04:13:59 2015 Louis Audibert
//

#include <SystemManager.hh>
#include <string.h>
#include <cstring>

SystemManager::SystemManager()
{

}

SystemManager::SystemManager(SystemManager *copy)
{
  for (std::list<ASystem*>::const_iterator it = copy->_systems.begin(); it != copy->_systems.end(); ++it)
    {
      if (!(*it))
	break;
      ASystem *tmp = (ASystem*)std::malloc(sizeof(ASystem));
      std::memset(tmp, 0, sizeof(ASystem));
      std::memcpy(tmp, (*it), sizeof(ASystem));
      std::memcpy(tmp->getComponent(), (*it)->getComponent(), sizeof(AComponent));
      _systems.push_back(tmp);
    }
}

SystemManager::~SystemManager()
{
}

ASystem *SystemManager::getSystemByComponent(E_Component type)
{
  for (std::list<ASystem*>::iterator it = _systems.begin(); it != _systems.end(); ++it)
    {
      if ((dynamic_cast<SystemGun*>(*it)) && (type == C_MISSILE || type == C_RIFLE || type == C_LASER))
	return (*it);
      else if ((dynamic_cast<SystemPos*>(*it)) && type == C_POSITION)
	return (*it);
      else if ((dynamic_cast<SystemHealth*>(*it)) && type == C_HEALTH)
	return (*it);
      else if ((dynamic_cast<SystemHitbox*>(*it)) && type == C_HITBOX)
	return (*it);
      else if ((dynamic_cast<SystemShield*>(*it)) && type == C_SHIELD)
	return (*it);
    }
  return (NULL);
}

void	SystemManager::addSystemByType(E_Component type)
{
  if (!(getSystemByComponent(type)))
    {
      switch (type)
	{
	case C_POSITION:
	  _systems.push_back(new SystemPos());
	  break;
	case C_HEALTH:
	  _systems.push_back(new SystemHealth());
	  break;
	case C_HITBOX:
	  _systems.push_back(new SystemHitbox());
	  break;
	case C_SHIELD:
	  _systems.push_back(new SystemShield());
	  break;
	default:
	  _systems.push_back(new SystemGun(type));
	  break;
	}
    }
}

void	SystemManager::removeSystemByType(E_Component type)
{
  for (std::list<ASystem*>::iterator it = _systems.begin(); it != _systems.end(); ++it)
    {
      if (dynamic_cast<SystemGun*>(*it)->getType() == type)
	_systems.erase(it);
    }
}
