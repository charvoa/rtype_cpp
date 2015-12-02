//
// EntityManager.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Tue Dec  1 01:08:09 2015 Louis Audibert
// Last update Wed Dec  2 02:35:14 2015 Louis Audibert
//

#ifndef _ENTITYMANAGER_HH_
# define _ENTITYMANAGER_HH_

# include <vector>
# include <iostream>
# include "EntityFactory.hh"
# include "AEntity.hh"
# include "E_EntityType.hh"
# include "PlayerFactory.hh"

class EntityManager
{
private:
  int		_id;
  EntityFactory _entityFactory;
  PlayerFactory _playerFactory;
  std::vector<AEntity*> _entities;

public:
  EntityManager();
  ~EntityManager();

  bool		createEntity(E_ENTITYTYPE type);
  bool		createEntity(E_ENTITYTYPE type, const Client &);
  bool		createEntitiesFromFolder(const std::string &filename, E_ENTITYTYPE type);
  void		removeEntity(AEntity &entity);
  void		removeEntityById(int id);
  AEntity	*getEntityById(int id);
  std::vector<AEntity*> getEntitiesByType(E_ENTITYTYPE type);
  void		update();
};

#endif /* _ENTITYMANAGER_HH_ */
