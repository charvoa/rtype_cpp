//
// ComponentShield.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Dec 21 02:19:48 2015 Louis Audibert
// Last update Mon Dec 21 02:22:36 2015 Louis Audibert
//

#ifndef _COMPONENTSHIELD_HH_
# define _COMPONENTSHIELD_HH_

# include <string>
# include <iostream>
# include <AComponent.hpp>

class ComponentShield : public AComponent
{
private:
  bool _shield;

public:
  ComponentShield();
  ~ComponentShield();

  bool	getShield() const;
  void	setShield(bool);
};

#endif /* _SHIELD_HH_ */
