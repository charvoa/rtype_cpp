//
// ThreadUnix.cpp for rtype in /home/nicolas/rendu/rtype_cpp/server/Thread
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Tue Dec  1 14:42:54 2015 Nicolas Girardot
// Last update Tue Dec  1 20:41:49 2015 Nicolas Girardot
//

#include "ThreadUnix.hh"

ThreadUnix::ThreadUnix()
{
  _id = pthread_self();
}

unsigned int	ThreadUnix::getId()
{
  return (_id);
}

void		ThreadUnix::attach(void (*function)(), void *data)
{
  _function = (void *)function;
  _parameters = data;
}

int		ThreadUnix::join()
{
  return (pthread_join(_thread, NULL));
}

void		ThreadUnix::exit()
{
  pthread_exit(NULL);
}

int		ThreadUnix::run()
{
  return (pthread_create(&_thread, NULL, (void* (*)(void*))_function, _parameters));
}
