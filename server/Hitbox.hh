//
// Hitbox.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sat Dec 12 11:10:26 2015 Louis Audibert
// Last update Sat Dec 12 11:19:58 2015 Louis Audibert
//

#ifndef _HITBOX_HH_
# define _HITBOX_HH_

# include <vector>
# include <string>
# include <iostream>
# include <AComponent.hpp>
# include <Case.hh>

class	Hitbox : public AComponent
{
private:
  std::vector<Case*> _hitbox;

public:
  Hitbox();
  ~Hitbox();

  std::vector<Case*>	getHitbox();
  void			setHitbox(std::vector<Case*>);
};

#endif /* _HITBOX_HH_ */
