//
// ThreadUnix.hh for R TYpe in /home/nicolas/rendu/rtype_cpp/server/Thread
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Tue Dec  1 10:42:19 2015 Nicolas Girardot
// Last update Tue Dec  1 20:40:56 2015 Nicolas Girardot
//

#ifndef _THREADUNIX_HH_
#define _THREADUNIX_HH_

#include <pthread.h>
#include "AThread.hpp"

class ThreadUnix : public AThread
{
  pthread_t	_thread;
public:
  ThreadUnix();
  unsigned int	getId();
  void		attach(void (*)(), void *);
  int		join();
  void		exit();
  int		run();
};

#endif
