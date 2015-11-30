//
// SystemGun.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Nov 30 02:21:19 2015 Louis Audibert
// Last update Mon Nov 30 05:50:05 2015 Louis Audibert
//

#ifndef _SYSTEMGUN_HH_
# define _SYSTEMGUN_HH_

# include <iostream>
# include "ASystem.hh"
# include "Missile.hh"
# include "Rifle.hh"
# include "Laser.hh"

class SystemGun : public ASystem
{
public:
  SystemGun(E_COMPONENT type);
  ~SystemGun();
};

#endif /* _SYSTEMGUN_HH_ */
