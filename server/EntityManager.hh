//
// EntityManager.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Tue Dec  1 01:08:09 2015 Louis Audibert
//

#ifndef _ENTITYMANAGER_HH_
# define _ENTITYMANAGER_HH_

# include <vector>
# include <iostream>
# include <EntityFactory.hh>
# include <AEntity.hh>
# include <E_EntityType.hh>
# include <PlayerFactory.hh>
# include <Bot.hpp>

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

  bool		createEntity(E_EntityType type);
  bool		createEntity(E_EntityType type, const Client &);
  bool		createEntitiesFromFolder(const std::string &filename, E_EntityType type);
  void		removeEntity(AEntity &entity);
  void		removeEntityById(int id);
  AEntity	*getEntityById(int id) const;
  std::vector<AEntity*> const getEntitiesByType(E_EntityType type) const;
  void		update();
};

#endif /* _ENTITYMANAGER_HH_ */
