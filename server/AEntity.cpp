//
// AEntity.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Nov 30 06:37:32 2015 Louis Audibert
// Last update Sat Dec 19 09:13:48 2015 Louis Audibert
//

#include <AEntity.hh>

AEntity::AEntity(int id) : _id(id)
{
  _systemManager = new SystemManager();
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
  if (_systemManager->getSystemByComponent(C_POSITION))
    dynamic_cast<SystemPos*>(_systemManager->getSystemByComponent(C_POSITION))->update(x, y);
  else
    return (false);
  return (true);
}

bool	AEntity::update(int health)
{
  if (_systemManager->getSystemByComponent(C_HEALTH))
    dynamic_cast<SystemHealth*>(_systemManager->getSystemByComponent(C_HEALTH))->update(health);
  else
    return (false);
  return (true);
}

bool	AEntity::update(std::list<Case*> hitbox)
{
  if (_systemManager->getSystemByComponent(C_HITBOX))
    dynamic_cast<SystemHitbox*>(_systemManager->getSystemByComponent(C_HITBOX))->update(hitbox);
  else
    return (false);
  return (true);
}

void	AEntity::addSystem(E_Component type)
{
  _systemManager->addSystemByType(type);
}

void	AEntity::removeSystem(E_Component type)
{
  _systemManager->removeSystemByType(type);
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

void	AEntity::setId(int id)
{
  _id = id;
}

SystemManager	*AEntity::getSystemManager()
{
  return (_systemManager);
}

void		AEntity::refreshSystemManager()
{
  SystemManager *newSystem = new SystemManager(_systemManager);
  _systemManager = newSystem;
}

bool		AEntity::checkColision(AEntity *entity)
{
  (void) entity;
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

std::list<Case*>	AEntity::refreshHitbox()
{
  std::list<Case*> hitbox;
  Case	*myCase;
  int	i = 0;

  myCase = (Case*)std::malloc(sizeof(Case));

  while (i < 10)
    {
      myCase->x = reinterpret_cast<ComponentPosition*>(_systemManager->getSystemByComponent(C_POSITION)->getComponent())->getX();
      myCase->y = reinterpret_cast<ComponentPosition*>(_systemManager->getSystemByComponent(C_POSITION)->getComponent())->getY() + i;
      hitbox.push_back(myCase);
      i++;
    }
  i = 1;
  while (i < 10)
    {
      myCase->x = reinterpret_cast<ComponentPosition*>(_systemManager->getSystemByComponent(C_POSITION)->getComponent())->getX();
      myCase->y = reinterpret_cast<ComponentPosition*>(_systemManager->getSystemByComponent(C_POSITION)->getComponent())->getY() - i;
      hitbox.push_back(myCase);
      i++;
    }
  std::cout << "Hitbox ready" << std::endl;
  return (hitbox);
}
