//
// EntityFactory.cpp for rtype in /home/audibel/rendu/rtype_cpp/server/build
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Tue Dec  1 01:52:21 2015 Louis Audibert
// Last update Sat Dec 12 04:26:07 2015 Joris Bertomeu
//

#include <EntityFactory.hh>

EntityFactory::EntityFactory()
{

}

EntityFactory::~EntityFactory()
{
  std::cout << "EntityFactory Destroyed" << std::endl;
}

AEntity	*EntityFactory::createEntity(int &id)
{
  std::cout << "new AEntity created !" << std::endl;
  id += 1;
  return (new AEntity(id));
}

AEntity *EntityFactory::createEntity(const std::string &filename, int id)
{
  (void)filename;
  DynLibLoader	loader;
  AEntity	*(*my_entity)(int);

  try {
    loader.open(filename);
    my_entity = reinterpret_cast<AEntity*(*)(int)>(loader.getSymbol("create_object"));
  } catch (const std::exception &e) {
    throw (std::logic_error(e.what()));
  }
  return (my_entity(id));
}
