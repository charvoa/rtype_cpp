//
// EntityFactory.cpp for rtype in /home/audibel/rendu/rtype_cpp/server/build
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Tue Dec  1 01:52:21 2015 Louis Audibert
// Last update Tue Dec  1 04:29:13 2015 Louis Audibert
//

#include "EntityFactory.hh"

EntityFactory::EntityFactory()
{
  _id = 0;
}

EntityFactory::~EntityFactory()
{
  std::cout << "EntityFactory Destroyed" << std::endl;
}

int	EntityFactory::generateNewID()
{
  _id += 1;
  return (_id);
}

AEntity	*EntityFactory::createEntity()
{
  std::cout << "new AEntity created !" << std::endl;
  return (new AEntity(generateNewID()));
}

AEntity *EntityFactory::createEntity(const std::string &filename)
{
  //temporary
  return (new AEntity(generateNewID()));
}
