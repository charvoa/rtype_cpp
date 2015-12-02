//
// EntityFactory.cpp for rtype in /home/audibel/rendu/rtype_cpp/server/build
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Tue Dec  1 01:52:21 2015 Louis Audibert
// Last update Wed Dec  2 13:28:02 2015 Nicolas Charvoz
//

#include "EntityFactory.hh"

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

AEntity *EntityFactory::createEntity(const std::string &filename, int &id)
{
  //temporary
  (void) filename;
  id += 1;
  return (new AEntity(id));
}
