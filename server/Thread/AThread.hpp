//
// Thread.hpp for thread in /home/antoinegarcia/rendu/rtype_cpp/server
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Mon Nov 30 08:45:35 2015 Antoine Garcia
// Last update Mon Nov 30 08:49:56 2015 Antoine Garcia
//

#ifndef _THREAD_HH_
# define _THREAD_HH_

class	AThread
{
  unsigned int	_id;
  bool		_joinable;
public:
  virtual ~AThread(){};
  unsigned int getId() = 0;
  bool		joinable() = 0;
  void		join() = 0;
  void		exit() = 0;
  void		run() = 0;
};

#endif
