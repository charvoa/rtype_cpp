//
// ThreadWin.hh for R-type in /home/nicolas/rendu/rtype_cpp/server/Thread
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Tue Dec  1 17:46:33 2015 Nicolas Girardot
// Last update Tue Dec  1 20:33:52 2015 Nicolas Girardot
//

#include <windows.h>

class ThreadWin : public AThread
{
  HANDLE	_thread;
public:
  ThreadWin();
  unsigned int	getId();
  void		attach(void *(*)(void *data));
  int		join();
  void		exit();
  int		run();
}
