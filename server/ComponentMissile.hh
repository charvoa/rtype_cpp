//
// Missile.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sat Nov 28 05:48:05 2015 Louis Audibert
// Last update Sun Dec 13 04:50:40 2015 Louis Audibert
//

#ifndef _COMPONENTMISSILE_HH_
# define _COMPONENTMISSILE_HH_

# include <string>
# include <iostream>
# include <AComponent.hpp>

class ComponentMissile : public AComponent
{
private:
  int	_dmg;

public:
  ComponentMissile();
  ~ComponentMissile();

  int	getDamages() const;
};

#endif /* _COMPONENTMISSILE_HH_ */
