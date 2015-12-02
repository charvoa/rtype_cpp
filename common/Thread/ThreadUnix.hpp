//
// ThreadWin.hh for R-type in /home/nicolas/rendu/rtype_cpp/server/Thread
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Tue Dec  1 17:46:33 2015 Nicolas Girardot
// Last update Wed Dec  2 14:56:08 2015 Nicolas Charvoz
//

#ifndef _THREADWIN_HH_
#define _THREADWIN_HH_

#include <pthread.h>
#include "AThread.hpp"

class Thread : public AThread
{
  HANDLE	_thread;
public:
  ThreadWin(unsigned int id) : _id(id) {};
  unsigned int	getId() {
    return _id;
  };
  void		attach(void(*)(), void *) {
    _function = (void*)function;
    _parameters = data;
  };
  int		join() {
    return (pthread_join(_thread, NULL));
  };
  void		exit() {
    pthread_exit(NULL);
  };
  int		run() {
    return (pthread_create(&_thread, NULL, (void* (*)(void*))_function,
			   _parameters));
  };
};

#endif
