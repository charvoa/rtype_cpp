//
// Threadstest.cpp for rtype in /home/nicolas/rendu/rtype_cpp/server/Thread
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Tue Dec  1 20:07:39 2015 Nicolas Girardot
// Last update Tue Dec  1 20:39:57 2015 Nicolas Girardot
//

#include <iostream>
#include <string>

#ifdef __linux__
#	include "ThreadUnix.hh"
#elif _WIN32
#	include "ThreadWin.hh"
#else
#endif;

void	first()
{
  while (true)
    std::cout << "Tata" << std::endl;
}

int	main()
{
  AThread *thread = new ThreadWin();
  thread->attach(&first, NULL);
  thread->run();
  while (true)
    {
      std::cout << "TOTO" << std::endl;
    }
}
