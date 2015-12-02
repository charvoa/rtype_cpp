//
// ThreadFactory.cpp for Rtype in /home/nicolas/rendu/rtype_cpp/common/Thread
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed Dec  2 14:55:14 2015 Nicolas Girardot
// Last update Wed Dec  2 14:58:07 2015 Nicolas Girardot
//

#include "ThreadFactory.hh"

ThreadFactory::ThreadFactory()
{
  _idnbr = 0;
}

ThreadFactory::~ThreadFactory()
{

}

Thread	*createThread()
{
  _idnbr++;
  return (new Thread(_idnbr));
}
