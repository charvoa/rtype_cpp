//
// Threadstest.cpp for rtype in /home/nicolas/rendu/rtype_cpp/server/Thread
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Tue Dec  1 20:07:39 2015 Nicolas Girardot
// Last update Wed Dec  2 15:14:46 2015 Nicolas Charvoz
//

#include <iostream>
#include <string>

#ifdef __unix__
#	include "ThreadUnix.hpp"
#elif defined(_WIN32) || defined(WIN32)
#	include "ThreadWin.hpp"
#else
#endif

void	first()
{
  while (true)
    std::cout << "Tata" << std::endl;
}

int	main()
{
  AThread *thread = new Thread(1);
  thread->attach(&first, NULL);
  thread->run();
  while (true)
    {
      std::cout << "TOTO" << std::endl;
    }
}
