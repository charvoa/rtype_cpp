//
// Thread.hpp for thread in /home/antoinegarcia/rendu/rtype_cpp/server
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Mon Nov 30 08:45:35 2015 Antoine Garcia
// Last update Thu Dec 10 09:41:59 2015 Serge Heitzler
//

#ifndef _THREAD_HH_
# define _THREAD_HH_

class	AThread
{
protected:
  void			*(*_function)(void*);
  void			*_parameters;
  unsigned int		_id;
public:
  AThread() {};
  virtual	~AThread(){};
  virtual unsigned int	getId() { return (_id); };
  virtual void		attach(void *(*fn)(void*), void *);
  virtual int		join() { return (0); };
  virtual void		exit() {};
  virtual void	    cancel() {};
  virtual int		run() {
	  return (0);
  };
};

#endif
