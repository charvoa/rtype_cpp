//
// AEntity.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Nov 30 06:37:32 2015 Louis Audibert
// Last update Wed Dec 16 05:35:55 2015 Louis Audibert
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

bool	AEntity::update(int x, int y)
{
  if (_systemManager.getSystemByComponent(C_POSITION))
    dynamic_cast<SystemPos*>(_systemManager.getSystemByComponent(C_POSITION))->update(x, y);
  else
    return (false);
  return (true);
}

bool	AEntity::update(int health)
{
  if (_systemManager.getSystemByComponent(C_HEALTH))
    dynamic_cast<SystemHealth*>(_systemManager.getSystemByComponent(C_HEALTH))->update(health);
  else
    return (false);
  return (true);
}

bool	AEntity::update(std::list<Case*> hitbox)
{
  if (_systemManager.getSystemByComponent(C_HITBOX))
    dynamic_cast<SystemHitbox*>(_systemManager.getSystemByComponent(C_HITBOX))->update(hitbox);
  else
    return (false);
  return (true);
}

void	AEntity::addSystem(E_Component type)
{
  _systemManager.addSystemByType(type);
}

void	AEntity::removeSystem(E_Component type)
{
  _systemManager.removeSystemByType(type);
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

const	std::string &AEntity::getName() const
{
  return (_name);
}

bool	AEntity::setParent(AEntity *parent)
{
  _parent = parent;
  return (true);
}
