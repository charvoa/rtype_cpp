//
// ThreadFactory.hh for rtype in /home/nicolas/rendu/rtype_cpp/common/Thread
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed Dec  2 14:44:56 2015 Nicolas Girardot
// Last update Wed Dec  2 14:56:17 2015 Nicolas Girardot
//

#ifndef _THREADFACTORY_HH_
#define _THREADFACTORY_HH_

#ifdef __linux__
#include "ThreadUnix.hpp"
#elif _WIN32
#include "ThreadWin.hpp"
#endif

class ThreadFactory
{
private:
  int	_idnbr;
public:
  ThreadFactory();
  ~ThreadFactory();

  Thread	*createThread(int id);
}

#endif
