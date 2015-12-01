//
// main.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Last update Wed Nov 18 17:01:40 2015 Joris Bertomeu
// Last update Mon Nov 30 05:50:36 2015 Antoine Garcia
//

#include	"Server.hh"
#include	"EntityManager.hh"

int		main(int ac, char **av)
{
  Server	*s = new Server();

  s->init();
  std::cout << "You've launched the Server of the RType" << std::endl;

  std::cout << "Made by La Pintade" << std::endl;
  return (0);
}
