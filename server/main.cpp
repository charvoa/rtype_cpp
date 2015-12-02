//
// main.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Last update Wed Dec  2 15:26:50 2015 Nicolas Girardot
// Last update Mon Nov 30 05:50:36 2015 Antoine Garcia
//

# include	"Server.hh"
# include	"EntityManager.hh"
#ifdef __unix__
# include	"../common/Thread/ThreadUnix.hpp"
#elif defined(_WIN32) || defined(WIN32)
# include 	"../common/Thread/ThreadWin.hpp"
#endif

void function()
{
  std::cout << "Ca marche" << std::endl;
}

int		main(int ac, char **av)
{
  Server	*s = new Server();

  (void)ac;
  (void)av;
  try {
    s->init();
    std::cout << "You've launched the Server of the RType" << std::endl;

    std::cout << "Made by La Pintade" << std::endl;
    s->run();
    AThread *thread = new Thread(2);
    thread->attach(&function, NULL);
    thread->run();
  } catch (const std::exception &e) {
    std::cout << "Error catched : " << e.what() << std::endl;
  }
  return (0);
}
