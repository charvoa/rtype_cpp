//
// SystemManager.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Nov 30 02:32:03 2015 Louis Audibert
// Last update Mon Nov 30 05:49:40 2015 Louis Audibert
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

}

void	SystemManager::addSystemByType(E_COMPONENT type)
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
