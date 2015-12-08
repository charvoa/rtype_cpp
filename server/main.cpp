//
// main.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Last update Tue Dec  8 16:44:04 2015 Nicolas Charvoz
// Last update Mon Nov 30 05:50:36 2015 Antoine Garcia
//

# include	<Server.hh>
# include	<EntityManager.hh>
#ifdef __unix__
# include	<ThreadUnix.hpp>
#elif defined(_WIN32) || defined(WIN32)
# include 	<ThreadWin.hpp>
#endif

#include <Mutex.hpp>
#include <ANetwork.hpp>
#include <CreateRequest.hpp>

int		main(int ac, char **av)
{
  Server	*s = new Server();

  (void)ac;

  try {
    if (av[1])
      s->init(atoi(av[1]));
    else
      s->init(4253);
    std::cout << "You've launched the Server of the RType" << std::endl;

    std::cout << "Made by La Pintade" << std::endl;
    s->run();
  } catch (const std::exception &e) {
    std::cout << "Error catched : " << e.what() << std::endl;
# ifdef _WIN32
	system("PAUSE");
# endif
  }
  return (0);
}
