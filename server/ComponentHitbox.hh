//
// Hitbox.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sat Dec 12 11:10:26 2015 Louis Audibert
// Last update Sun Dec 13 05:22:21 2015 Louis Audibert
//

#ifndef _HITBOX_HH_
# define _HITBOX_HH_

# include <list>
# include <string>
# include <iostream>
# include <AComponent.hpp>
# include <Case.hh>

class	ComponentHitbox : public AComponent
{
private:
  std::list<Case*> _hitbox;

public:
  ComponentHitbox();
  ~ComponentHitbox();

  std::list<Case*>	getHitbox();
  void			setHitbox(std::list<Case*>);
};

#endif /* _HITBOX_HH_ */
