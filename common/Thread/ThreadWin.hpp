//
// ThreadWin.hh for R-type in /home/nicolas/rendu/rtype_cpp/server/Thread
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Tue Dec  1 17:46:33 2015 Nicolas Girardot
// Last update Mon Dec  7 15:08:29 2015 Nicolas Charvoz
//

#ifndef _THREADWIN_HPP_
#define _THREADWIN_HPP_

#include <windows.h>
#include "AThread.hpp"

class Thread : public AThread
{
  HANDLE	_thread;
public:
  Thread(unsigned int id) { _id = id;};
  unsigned int	getId() {
    return _id;
  };
  void		attach(void *(*function)(void*), void *data) {
    _function = function;
    _parameters = data;
  };
  int		join() {
    return (WaitForSingleObject(_thread, INFINITE));
  };
  void		exit() {
    ExitThread((DWORD)_thread);
  };
  int		run() {
    return (DWORD)(CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)_function,
				_parameters, 0, NULL));

  };
};

#endif
