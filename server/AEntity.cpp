//
// AEntity.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Nov 30 06:37:32 2015 Louis Audibert
// Last update Wed Dec  9 06:51:57 2015 Louis Audibert
//

#include <AEntity.hh>

AEntity::AEntity(int id) : _id(id)
{
  std::cout << "new AEntity created !" << std::endl;
}

AEntity::~AEntity()
{
  std::cout << "AEntity Destroyed" << std::endl;
}

bool	AEntity::update(int x, int y)
{
  if (_systemManager.getSystemByComponent(E_POSITION))
    dynamic_cast<SystemPos*>(_systemManager.getSystemByComponent(E_POSITION))->update(x, y);
  else
    return (false);
  return (true);
}

bool	AEntity::update(int health)
{
  if (_systemManager.getSystemByComponent(E_HEALTH))
    dynamic_cast<SystemHealth*>(_systemManager.getSystemByComponent(E_HEALTH))->update(health);
  else
    return (false);
  return (true);
}

// void	AEntity::update()
// {

// }

void	AEntity::addSystem(E_Component type)
{
  std::cout << "before calling the systemManager.addSystemByType(" << type << ")" << std::endl;
  _systemManager.addSystemByType(type);
  std::cout << "after calling addSystemByType" << std::endl;
}

bool	AEntity::setType(E_EntityType type)
{
  _type = type;
  return (true);
}

E_EntityType	AEntity::getType() const
{
  return (_type);
}

int	AEntity::getId() const
{
  return (_id);
}

SystemManager	*AEntity::getSystemManager()
{
  return (&_systemManager);
}
