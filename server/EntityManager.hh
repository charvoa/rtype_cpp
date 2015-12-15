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

# include <list>
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
  std::list<AEntity*> _entities;

public:
  EntityManager();
  ~EntityManager();

  int		createEntity(E_EntityType type);
  int		createEntity(E_EntityType type,  Client &);
  int		createEntity(E_EntityType type, AEntity *);
  int		createEntitiesFromFolder( std::string &filename, E_EntityType type);
  void		removeEntity(AEntity *entity);
  void		removeEntityById(int id);
  std::list<AEntity*>  getEntities() ;
  AEntity	*getEntityById(int id) ;
  std::list<AEntity*>  getEntitiesByType(E_EntityType type) ;
  std::list<AEntity*>  getAmmoEntities() ;
};

#endif /* _ENTITYMANAGER_HH_ */
