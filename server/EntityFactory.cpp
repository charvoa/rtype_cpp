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
  :
}

EntityFactory::~EntityFactory()
{
  std::cout << "EntityFactory Destroyed" << std::endl;
}

AEntity	*EntityFactory::createEntity(int &id)
{
  std::cout << "new AEntity created !" << std::endl;
  if (id == 4)
    id = 11;
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
  if (id == 4)
    id = 11;
  id++;
  return (my_entity(id));
}

AEntity *EntityFactory::createEntity(int &id, E_EntityType type)
{
  AEntity *newEntity;

  if (id == 4)
    id = 11;
  id++;
  switch (type)
    {
    case E_RIFLE:
      newEntity = new Riffle(5);
      break;
    case E_MISSILE:
      newEntity = new Missile(6);
      break;
    case E_LASER:
      newEntity = new Laser(7);
      break;
    default:
      newEntity = new AEntity(id);
      break;
    }
  return (newEntity);
}
