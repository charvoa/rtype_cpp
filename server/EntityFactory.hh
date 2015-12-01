//
// EntityFactory.hh for rtype in /home/audibel/rendu/rtype_cpp/server/build
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Tue Dec  1 01:52:27 2015 Louis Audibert
// Last update Tue Dec  1 02:14:52 2015 Louis Audibert
//

#ifndef _ENTITYFACTORY_HH_
# define _ENTITYFACTORY_HH_

# include "AEntity.hh"

class EntityFactory
{
private:
  int	_id;

  int	generateNewID();

public:
  EntityFactory();
  ~EntityFactory();

  AEntity *createEntity();
  AEntity *createEntity(const std::string &filename);
};

#endif /* _ENTITYFACTORY_HH_ */
