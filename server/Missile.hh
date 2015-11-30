//
// Missile.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sat Nov 28 05:48:05 2015 Louis Audibert
// Last update Mon Nov 30 06:18:35 2015 Louis Audibert
//

#ifndef _MISSILE_HH_
# define _MISSILE_HH_

# include <string>
# include <iostream>
# include "AComponent.hpp"

class Missile : public AComponent
{
private:
  int	_dmg;

public:
  Missile();
  ~Missile();

  int	getDamages() const;
};

#endif /* _MISSILE_HH_ */
