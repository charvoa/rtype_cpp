//
// EntityFactory.cpp for rtype in /home/audibel/rendu/rtype_cpp/server/build
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Tue Dec  1 01:52:21 2015 Louis Audibert
// Last update Mon Dec  7 08:12:52 2015 Louis Audibert
//

#include <EntityFactory.hh>
#include <dlfcn.h>

#include "libs/LittleMonster.hh"

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
  (void)filename;
  void* handle = dlopen("./libs/littlemonster.so", RTLD_LAZY);

  //  LittleMonster* (*create)(int);
  void (*updateFunc)(AEntity*);

  //  create = (LittleMonster* (*)(int))dlsym(handle, "create_object");
  updateFunc = (void (*)(AEntity*))dlsym(handle, "update");

  //  LittleMonster* monster = (LittleMonster*)create(id);

  updateFunc(new AEntity(id));

  //monster->update(new AEntity(id));
  //blabla
  id += 1;
  return (new AEntity(id));
}
