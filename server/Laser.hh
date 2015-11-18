//
// Laser.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sat Nov 28 05:48:05 2015 Louis Audibert
// Last update Mon Nov 30 05:53:17 2015 Antoine Garcia
//

#ifndef _LASER_HH_
# define _LASER_HH_

# include <string>
# include <iostream>
# include "AComponent.hh"

class Laser : public AComponent
{
private:
  int	_dmg;

public:
  Laser();
  ~Laser();

  int	getDamages() const;
};

#endif /* _LASER_HH_ */
