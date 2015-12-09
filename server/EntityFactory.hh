//
// EntityFactory.hh for rtype in /home/audibel/rendu/rtype_cpp/server/build
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Tue Dec  1 01:52:27 2015 Louis Audibert
// Last update Tue Dec  8 05:03:47 2015 Louis Audibert
//

#ifndef _ENTITYFACTORY_HH_
# define _ENTITYFACTORY_HH_

# include <AEntity.hh>
# include <DLLoader.hpp>

class EntityFactory
{
public:
  EntityFactory();
  ~EntityFactory();

  AEntity *createEntity(int &id);
  AEntity *createEntity(const std::string &filename, int &id);
};

#endif /* _ENTITYFACTORY_HH_ */
