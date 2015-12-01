//
// main.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Last update Tue Dec  1 04:47:53 2015 Louis Audibert
// Last update Mon Nov 30 05:50:36 2015 Antoine Garcia
//

#include	"Server.hh"
#include "EntityManager.hh"

int		main(int ac, char **av)
{
  //  Server	*s = new Server();
  std::cout << "You've launched the Server of the RType" << std::endl;

  EntityManager *test = new EntityManager();

  test->createEntity();
  test->createEntity();
  test->createEntity();
  AEntity *testpos = test->getEntityById(1);
  testpos->addSystem(E_POSITION);
  AEntity *testhealth = test->getEntityById(2);
  testhealth->addSystem(E_HEALTH);

  test->removeEntityById(3);
  test->removeEntityById(2);
  test->removeEntityById(1);

  std::cout << "Made by La Pintade" << std::endl;
  return (0);
}
