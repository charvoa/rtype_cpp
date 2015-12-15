//
// EntityManager.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Tue Dec  1 01:14:04 2015 Louis Audibert
//

#include <EntityManager.hh>

EntityManager::EntityManager()
{
  _id = 0;
}

EntityManager::~EntityManager()
{
  std::cout << "EntityManager Destroyed" << std::endl;
}

int	EntityManager::createEntity(E_EntityType type)
{
  AEntity *newEntity = _entityFactory.createEntity(_id);
  newEntity->setType(type);
  _entities.push_back(newEntity);
  return (_id);
}

int	EntityManager::createEntity(E_EntityType type,  Client &client)
{
  AEntity *newEntity = _playerFactory.createPlayer(_id, client);
  newEntity->setType(type);
  _entities.push_back(newEntity);
  return (_id);
}

int	EntityManager::createEntity(E_EntityType type, AEntity *parent)
{
  AEntity *newEntity = _entityFactory.createEntity(_id, type);
  newEntity->setType(type);
  newEntity->setParent(parent);
  _entities.push_back(newEntity);
  return (_id);
}

int	EntityManager::createEntitiesFromFolder( std::string &filename, E_EntityType type)
{
  AEntity *newEntity = _entityFactory.createEntity(filename, _id);
  newEntity->setType(type);
  _entities.push_back(newEntity);
  return (_id);
}

void	EntityManager::removeEntity(AEntity *entity)
{
  this->_entities.remove(entity);
}

void	EntityManager::removeEntityById(int id)
{
  // int	i = 0;
  // for (std::list<AEntity*>::iterator it = _entities.begin(); it != _entities.end(); ++it)
  //   {
  //     if (id == (*it)->getId())
  // 	{
  // 	  _entities.erase(_entities.begin()+i);
  // 	  std::cout << "Entity removed" << std::endl;
  // 	  break;
  // 	}
  //     i++;
  //   }
}

std::list<AEntity*>  EntityManager::getEntities()
{
  return (_entities);
}

AEntity	*EntityManager::getEntityById(int id)
{
  for (std::list<AEntity*>::iterator it = _entities.begin(); it != _entities.end(); ++it)
    {
      if (id == (*it)->getId())
	return (*it);
    }
  return (NULL);
}

std::list<AEntity*>  EntityManager::getEntitiesByType(E_EntityType type)
{
  std::list<AEntity*> entitiesByType;
  for (std::list<AEntity*>::iterator it = _entities.begin(); it != _entities.end(); ++it)
    {
      if ((*it)->getType() == type)
	entitiesByType.push_back(*it);
    }
  return (entitiesByType);
}

std::list<AEntity*>  EntityManager::getAmmoEntities()
{
  std::list<AEntity*> Ammos;
  E_EntityType type;

  type = E_INVALID;
  for (std::list<AEntity*>::iterator it = _entities.begin(); it != _entities.end(); ++it)
    {
      type = (*it)->getType();
      if (type == E_RIFLE || type == E_MISSILE || type == E_LASER)
	Ammos.push_back(*it);
    }
  return (Ammos);
}
