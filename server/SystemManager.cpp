//
// SystemManager.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Nov 30 02:32:03 2015 Louis Audibert
// Last update Wed Dec  9 01:36:06 2015 Louis Audibert
//

#include <SystemManager.hh>

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
      std::cout << "we are in the loop of getSystemByComponent" << std::endl;
      if ((dynamic_cast<SystemGun*>(*it)) && (type == E_MISSILE || type == E_RIFLE || type == E_LASER))
	{
	  std::cout << "getSystemByComponent returning SystemGun" << std::endl;
	  return (*it);
	}
      else if ((dynamic_cast<SystemPos*>(*it)) && type == E_POSITION)
	{
	  std::cout << "getSystemByComponent returning SystemPos" << std::endl;
	  return (*it);
	}
      else if ((dynamic_cast<SystemHealth*>(*it)) && type == E_HEALTH)
	{
	  std::cout << "getSystemByComponent returning SystemHealth" << std::endl;
	  return (*it);
	}
    }
  std::cout << "getSystemByComponent returning null" << std::endl;
  return (NULL);
}

void	SystemManager::addSystemByType(E_COMPONENT type)
{
  std::cout << "we are in addSystemByType" << std::endl;
  if (!(getSystemByComponent(type)))
    {
      std::cout << "adding a new system" << std::endl;
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
      std::cout << "new system added." << std::endl;
    }
  std::cout << "we are at the end of addSystemByType" << std::endl;
}
