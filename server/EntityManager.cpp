//
// EntityManager.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Tue Dec  1 01:14:04 2015 Louis Audibert
// Last update Tue Dec  1 02:55:46 2015 Louis Audibert
//

#include "EntityManager.hh"

EntityManager::EntityManager()
{

}

EntityManager::~EntityManager()
{
  std::cout << "EntityManager Destroyed" << std::endl;
}

bool	EntityManager::createEntity()
{
  _entities.push_back(_entityFactory.createEntity());
  return (true);
}

bool	EntityManager::createEntitiesFromFolder(const std::string &filename)
{
  _entities.push_back(_entityFactory.createEntity(filename));
  return (true);
}

void	EntityManager::removeEntity(AEntity &entity)
{
  int	i = 0;
  for (std::vector<AEntity*>::iterator it = _entities.begin(); it != _entities.end(); ++it)
    {
      if (entity.getId() == (*it)->getId())
	_entities.erase(_entities.begin()+i);
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

std::vector<AEntity*> EntityManager::getEntitiesByType(E_ENTITYTYPE type)
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
