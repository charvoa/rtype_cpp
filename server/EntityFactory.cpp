//
// EntityFactory.cpp for rtype in /home/audibel/rendu/rtype_cpp/server/build
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Tue Dec  1 01:52:21 2015 Louis Audibert
// Last update Wed Dec  9 06:42:17 2015 Louis Audibert
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

  // LittleMonster* (*create)(int);

  // void* handle = dlopen("./libs/littlemonster.so", RTLD_LAZY);

  // create = reinterpret_cast<LittleMonster* (*)(int)>(dlsym(handle, "create_object"));

  // LittleMonster* monster = (LittleMonster*)create(id);

  // monster->addSystem(E_HEALTH);
  // monster->addSystem(E_POSITION);

  // //std::cout << "before call to update function in EntityFactory" << std::endl;

  // std::cout << "health before update = " << dynamic_cast<Health*>(monster->getSystemManager()->getSystemByComponent(E_HEALTH)->getComponent())->getLife() << std::endl;

  // monster->update();

  // std::cout << "health after update = " << dynamic_cast<Health*>(monster->getSystemManager()->getSystemByComponent(E_HEALTH)->getComponent())->getLife() << std::endl;

  // const std::string lib = "littlemonster.so";

  // DLLoader<AEntity*> loader(lib, id);
  // AEntity *monster = loader.getInstance();
  // monster->setType(E_BOT);
  // monster->addSystem(E_HEALTH);
  //monster->addSystem(E_POSITION);
  //monster->update();

  // id += 1;
  // return (monster);
  id++;
  return (new AEntity(id));
}
