//
// Threadstest.cpp for rtype in /home/nicolas/rendu/rtype_cpp/server/Thread
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Tue Dec  1 20:07:39 2015 Nicolas Girardot
// Last update Wed Dec  2 16:58:47 2015 Nicolas Charvoz
//

#include <iostream>
#include <string>

#ifdef __unix__
#	include "ThreadUnix.hpp"
#elif defined(_WIN32) || defined(WIN32)
#	include "ThreadWin.hpp"
#else
#endif

#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <stdio.h>

void *first(void *args)
{
  std::cout << (char*)args << std::endl;
}

int	main()
{
  char *s = (char*)malloc(4 * sizeof(char));

  strcpy(s, "lol");
  s[4] = 0;

  AThread *thread = new Thread(1);
  thread->attach(&first, (void*)s);
  thread->run();
  thread->join();
}
