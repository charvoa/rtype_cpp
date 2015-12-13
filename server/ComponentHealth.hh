//
// Health.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sat Nov 28 05:29:53 2015 Louis Audibert
// Last update Sun Dec 13 05:14:50 2015 Louis Audibert
//

#ifndef _COMPONENTHEALTH_HH_
# define _COMPONENTHEALTH_HH_

# include <string>
# include <iostream>
# include <AComponent.hpp>

class ComponentHealth : public AComponent
{
private:
  int	_nbLife;

public:
  ComponentHealth();
  ~ComponentHealth();

  unsigned int	getLife() const;
  void		setLife(int life);
};

#endif /* _HEALTH_HH_ */
