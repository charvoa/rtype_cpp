//
// ThreadWin.cpp for R-type in /home/nicolas/rendu/rtype_cpp/server/Thread
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Tue Dec  1 17:46:23 2015 Nicolas Girardot
// Last update Tue Dec  1 20:05:59 2015 Nicolas Girardot
//

#include "ThreadWin.hh"

ThreadWin::ThreadWin()
{
	_id = GetCurrentThreadId();
}

unsigned int	ThreadWin::getId()
{
  return _id;
}

void		ThreadWin::attach(void(*function)(), void *data)
{
  _function = (void *)function;
  _parameters = data;
}

int		ThreadWin::join()
{
  return (WaitForSingleObject(_thread, INFINITE));
}

void		ThreadWin::exit()
{
  ExitThread((DWORD)_thread);
}

int		ThreadWin::run()
{
  return (DWORD)(CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)_function, _parameters, 0, NULL));
}
