//
// AEntity.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Nov 30 06:37:32 2015 Louis Audibert
// Last update Thu Dec  3 05:06:24 2015 Louis Audibert
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

void	AEntity::addSystem(E_COMPONENT type)
{
  _systemManager.addSystemByType(type);
  std::cout << "New System added !" << std::endl;
}

bool	AEntity::setType(E_ENTITYTYPE type)
{
  _type = type;
  return (true);
}

E_ENTITYTYPE	AEntity::getType() const
{
  return (_type);
}

int	AEntity::getId() const
{
  return (_id);
}
