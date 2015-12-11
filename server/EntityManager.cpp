//
// EntityManager.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Tue Dec  1 01:14:04 2015 Louis Audibert
// Last update Fri Dec 11 17:36:58 2015 Joris Bertomeu
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

bool	EntityManager::createEntity(E_EntityType type)
{
  AEntity *newEntity = _entityFactory.createEntity(_id);
  newEntity->setType(type);
  _entities.push_back(newEntity);
  _entities.push_back(_entityFactory.createEntity(_id));
  return (true);
}

bool	EntityManager::createEntity(E_EntityType type, const Client &client)
{
  AEntity *newEntity = _playerFactory.createPlayer(_id, client);
  newEntity->setType(type);
  _entities.push_back(newEntity);
  return (true);
}

bool	EntityManager::createEntitiesFromFolder(const std::string &filename, E_EntityType type)
{
  AEntity *newEntity = _entityFactory.createEntity(filename, _id);
  newEntity->setType(type);
  _entities.push_back(newEntity);
  //_entities.push_back(_entityFactory.createEntity(filename, _id));
  return (true);
}

void	EntityManager::removeEntity(AEntity &entity)
{
  int	i = 0;
  for (std::vector<AEntity*>::iterator it = _entities.begin(); it != _entities.end(); ++it)
    {
      if (entity.getId() == (*it)->getId())
	{
	  _entities.erase(_entities.begin()+i);
	  std::cout << "Entity removed" << std::endl;
	  break;
	}
      i++;
    }
}

void	EntityManager::removeEntityById(int id)
{
  int	i = 0;
  for (std::vector<AEntity*>::iterator it = _entities.begin(); it != _entities.end(); ++it)
    {
      if (id == (*it)->getId())
	{
	  _entities.erase(_entities.begin()+i);
	  std::cout << "Entity removed" << std::endl;
	  break;
	}
      i++;
    }
}

AEntity	*EntityManager::getEntityById(int id)
{
  for (std::vector<AEntity*>::iterator it = _entities.begin(); it != _entities.end(); ++it)
    {
      if (id == (*it)->getId())
	return (*it);
    }
  return (NULL);
}

std::vector<AEntity*> EntityManager::getEntitiesByType(E_EntityType type)
{
  std::vector<AEntity*> entitiesByType;
  for (std::vector<AEntity*>::iterator it = _entities.begin(); it != _entities.end(); ++it)
    {
      if ((*it)->getType() == type)
	entitiesByType.push_back(*it);
    }
  return (entitiesByType);
}

void	EntityManager::update()
{

}
