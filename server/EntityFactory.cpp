//
// EntityFactory.cpp for rtype in /home/audibel/rendu/rtype_cpp/server/build
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Tue Dec  1 01:52:21 2015 Louis Audibert
// Last update Tue Dec  1 13:06:41 2015 Louis Audibert
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
  id += 1;
  return (new AEntity(id));
}
