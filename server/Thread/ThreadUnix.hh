//
// ThreadUnix.hh for R TYpe in /home/nicolas/rendu/rtype_cpp/server/Thread
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Tue Dec  1 10:42:19 2015 Nicolas Girardot
// Last update Tue Dec  1 11:40:11 2015 Nicolas Girardot
//

#include <pthread.h>

class ThreadUnix : public AThread
{
public:
  void *(*)(void *data)
};
