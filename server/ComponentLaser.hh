//
// Laser.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sat Nov 28 05:48:05 2015 Louis Audibert
// Last update Sun Dec 13 04:51:34 2015 Louis Audibert
//

#ifndef _COMPONENTLASER_HH_
# define _COMPONENTLASER_HH_

# include <string>
# include <iostream>
# include <AComponent.hpp>

class ComponentLaser : public AComponent
{
private:
  int	_dmg;

public:
  ComponentLaser();
  ~ComponentLaser();

  int	getDamages() const;
};

#endif /* _LASER_HH_ */
