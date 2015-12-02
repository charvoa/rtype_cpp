//
// EntityManager.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Tue Dec  1 01:08:09 2015 Louis Audibert
// Last update Tue Dec  1 13:02:51 2015 Louis Audibert
//

#ifndef _ENTITYMANAGER_HH_
# define _ENTITYMANAGER_HH_

# include <vector>
# include <iostream>
# include "EntityFactory.hh"
# include "AEntity.hh"
# include "E_EntityType.hh"

class EntityManager
{
private:
  int		_id;
  EntityFactory _entityFactory;
  std::vector<AEntity*> _entities;

public:
  EntityManager();
  ~EntityManager();

  bool		createEntity(E_ENTITYTYPE type);
  bool		createEntitiesFromFolder(const std::string &filename, E_ENTITYTYPE type);
  void		removeEntity(AEntity &entity);
  void		removeEntityById(int id);
  AEntity	*getEntityById(int id);
  std::vector<AEntity*> getEntitiesByType(E_ENTITYTYPE type);
  void		update();
};

#endif /* _ENTITYMANAGER_HH_ */
