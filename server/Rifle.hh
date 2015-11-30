//
// Rifle.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sat Nov 28 05:48:05 2015 Louis Audibert
// Last update Mon Nov 30 05:52:02 2015 Antoine Garcia
//

#ifndef _RIFLE_HH_
# define _RIFLE_HH_

# include <string>
# include <iostream>
# include "AComponent.hh"

class Rifle : public AComponent
{
private:
  int	_dmg;

public:
  Rifle();
  ~Rifle();

  int	getDamages() const;
};

#endif /* _RIFLE_HH_ */
