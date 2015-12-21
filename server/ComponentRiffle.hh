//
// ComponentRiffle.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sat Nov 28 05:48:05 2015 Louis Audibert
// Last update Sun Dec 13 04:48:40 2015 Louis Audibert
//

#ifndef _COMPONENTRIFLE_HH_
# define _COMPONENTRIFLE_HH_

# include <string>
# include <iostream>
# include <AComponent.hpp>

class ComponentRiffle : public AComponent
{
private:
  int	_dmg;

public:
  ComponentRiffle();
  ~ComponentRiffle();

  int	getDamages() const;
};

#endif /* _RIFLE_HH_ */
