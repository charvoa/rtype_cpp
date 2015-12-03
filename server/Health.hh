//
// Health.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sat Nov 28 05:29:53 2015 Louis Audibert
// Last update Thu Dec  3 05:17:43 2015 Louis Audibert
//

#ifndef _HEALTH_HH_
# define _HEALTH_HH_

# include <string>
# include <iostream>
# include <AComponent.hpp>

class Health : public AComponent
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
