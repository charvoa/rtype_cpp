//
// EntityFactory.cpp for rtype in /home/audibel/rendu/rtype_cpp/server/build
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Tue Dec  1 01:52:21 2015 Louis Audibert
//

#include <EntityFactory.hh>

EntityFactory::EntityFactory()
{
}

EntityFactory::~EntityFactory()
{
}

AEntity	*EntityFactory::createEntity(int &id)
{
  id++;
  return (new AEntity(id));
}

AEntity *EntityFactory::createEntity(const std::string &filename, int &id)
{
  DynLibLoader	loader;
  AEntity	*(*my_entity)(int);

  try {
    loader.open(filename);
    my_entity = reinterpret_cast<AEntity*(*)(int)>(loader.getSymbol("create_object"));
  } catch (const std::exception &e) {
    throw (std::logic_error(e.what()));
  }
  id++;
  return (my_entity(id));
}

AEntity *EntityFactory::createEntity(int &id, E_EntityType type)
{
  AEntity *newEntity;

  id++;
  switch (type)
    {
    case E_RIFLE:
      {
	newEntity = new Riffle(id);
	break;
      }
    case E_MISSILE:
      {
	newEntity = new Missile(id);
	break;
      }
    case E_LASER:
      {
	newEntity = new Laser(id);
	break;
      }
    default:
      {
	newEntity = new AEntity(id);
	break;
      }
    }
  return (newEntity);
}
