//
// SystemHitbox.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sat Dec 12 10:58:56 2015 Louis Audibert
// Last update Sun Dec 13 05:23:54 2015 Louis Audibert
//

#ifndef _SYSTEMHITBOX_HH_
# define _SYSTEMHITBOX_HH_

# include <iostream>
# include <ASystem.hpp>
# include <ComponentHitbox.hh>

class SystemHitbox : public ASystem
{
public:
  SystemHitbox();
  ~SystemHitbox();

  bool	update(std::list<Case*> hitbox);
};

#endif /* _SYSTEMHITBOX_HH */
