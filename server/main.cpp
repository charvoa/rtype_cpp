//
// main.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Last update Thu Nov 19 00:04:35 2015 Joris Bertomeu
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

  try {
    s->init();
    std::cout << "You've launched the Server of the RType" << std::endl;

    std::cout << "Made by La Pintade" << std::endl;
    s->run();
    // AThread *thread = new ThreadUnix();

    // thread->attach(&function, NULL);
    // thread->run();
  } catch (const std::exception &e) {
    std::cout << "Error catched : " << e.what() << std::endl;
  }
  return (0);
}
