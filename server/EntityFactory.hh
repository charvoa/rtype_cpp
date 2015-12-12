//
// EntityFactory.hh for rtype in /home/audibel/rendu/rtype_cpp/server/build
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Tue Dec  1 01:52:27 2015 Louis Audibert
// Last update Fri Dec 11 17:04:30 2015 Joris Bertomeu
//

#ifndef _ENTITYFACTORY_HH_
# define _ENTITYFACTORY_HH_

# include <AEntity.hh>
# include <DynLibLoader.hpp>

class EntityFactory
{
public:
  EntityFactory();
  ~EntityFactory();

  AEntity *createEntity(int &id);
  AEntity *createEntity(const std::string &filename, int &id);
};

#endif /* _ENTITYFACTORY_HH_ */
