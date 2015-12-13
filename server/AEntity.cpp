//
// AEntity.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Nov 30 06:37:32 2015 Louis Audibert
// Last update Sun Dec 13 02:21:51 2015 Louis Audibert
//

#include <AEntity.hh>

AEntity::AEntity(int id) : _id(id)
{
  std::cout << "new AEntity created !" << std::endl;
}

AEntity::AEntity(int id, AEntity *parent)
{
  _id = id;
  _parent = parent;
  std::cout << "new AEntity with a parent created !" << std::endl;
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

bool	AEntity::update(std::vector<Case*> hitbox)
{
  if (_systemManager.getSystemByComponent(E_HITBOX))
    dynamic_cast<SystemHitbox*>(_systemManager.getSystemByComponent(E_HITBOX))->update(hitbox);
  else
    return (false);
  return (true);
}

void	AEntity::addSystem(E_Component type)
{
  _systemManager.addSystemByType(type);
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

bool		AEntity::checkColision(AEntity *entity)
{
  return (true);
}
