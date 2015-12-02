//
// Thread.hpp for thread in /home/antoinegarcia/rendu/rtype_cpp/server
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Mon Nov 30 08:45:35 2015 Antoine Garcia
// Last update Tue Dec  1 20:40:54 2015 Nicolas Girardot
//

#ifndef _THREAD_HH_
# define _THREAD_HH_

class	AThread
{
protected:
  void			*_function;
  void			*_parameters;
  unsigned int		_id;
public:
  virtual	~AThread(){};
  virtual unsigned int	getId() = 0;
  virtual void		attach(void (*)(), void *) = 0;
  virtual int		join() = 0;
  virtual void		exit() = 0;
  virtual int		run() = 0;
};

#endif
