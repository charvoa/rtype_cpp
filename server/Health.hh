//
// Health.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sat Nov 28 05:29:53 2015 Louis Audibert
// Last update Mon Nov 30 01:33:54 2015 Louis Audibert
//

#ifndef _HEALTH_HH_
# define _HEALTH_HH_

# include <string>
# include <iostream>
# include "IComponent.hh"

class Health : public IComponent
{
private:
  int	_nbLife;

public:
  Health();
  ~Health();

  unsigned int	getLife() const;
  void		setLife(int life);
};

#endif /* _HEALTH_HH_ */
