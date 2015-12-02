//
// ThreadWin.hh for R-type in /home/nicolas/rendu/rtype_cpp/server/Thread
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Tue Dec  1 17:46:33 2015 Nicolas Girardot
// Last update Wed Dec  2 15:12:15 2015 Nicolas Charvoz
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
  void		attach(void(*function)(), void *data) {
    _function = (void*)function;
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
