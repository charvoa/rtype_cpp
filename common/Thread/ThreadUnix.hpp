//
// ThreadUnix.hpp for  in /home/nicolaschr/rendu/rtype_cpp/common/Thread
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Dec  2 17:01:11 2015 Nicolas Charvoz
// Last update Thu Dec 10 09:39:07 2015 Serge Heitzler
//

#ifndef _THREADUNIX_HPP_
#define _THREADUNIX_HPP_

#include "AThread.hpp"
#include <pthread.h>

class Thread : public AThread
{
private:

  pthread_t	_thread;

public:

  Thread(unsigned int id) {
    _id = id;
  };

  ~Thread(){};

  unsigned int	getId() {
    return _id;
  };

  void		attach(void *(*function)(void *data), void *data) {
    _function = function;
    _parameters = data;
  };

  int		join() {
    return (pthread_join(_thread, NULL));
  };

  void	        cancel() {
    pthread_cancel(_thread);
  };

  void		exit() {
    pthread_exit(NULL);
  };

  int		run() {
    return (pthread_create(&_thread, NULL, _function,
			   _parameters));
  };
};

#endif
