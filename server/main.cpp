//
// main.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Last update Wed Dec  2 09:59:24 2015 Nicolas Charvoz
// Last update Mon Nov 30 05:50:36 2015 Antoine Garcia
//

#include	"Server.hh"
#include	"EntityManager.hh"
#include	"../common/Thread/ThreadUnix.hh"

void function()
{
  std::cout << "Ca marche" << std::endl;
}

int		main(int ac, char **av)
{
  Server	*s = new Server();

  s->init();
  std::cout << "You've launched the Server of the RType" << std::endl;

  std::cout << "Made by La Pintade" << std::endl;


  // AThread *thread = new ThreadUnix();

  // thread->attach(&function, NULL);
  // thread->run();
  return (0);
}
