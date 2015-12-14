//
// EntityFactory.hh for rtype in /home/audibel/rendu/rtype_cpp/server/build
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Tue Dec  1 01:52:27 2015 Louis Audibert
// Last update Mon Dec 14 09:14:59 2015 Louis Audibert
//

#ifndef _ENTITYFACTORY_HH_
# define _ENTITYFACTORY_HH_

# include <AEntity.hh>
# include <Riffle.hh>
# include <Missile.hh>
# include <Laser.hh>
# ifdef _WIN32
#  include <DynLibLoaderWin.hpp>
# else
#  include <DynLibLoader.hpp>
# endif

class EntityFactory
{
public:
  EntityFactory();
  ~EntityFactory();

  AEntity *createEntity(int &id);
  AEntity *createEntity(const std::string &filename, int &id);
  AEntity *createEntity(int &id, E_EntityType type);
};

#endif /* _ENTITYFACTORY_HH_ */
