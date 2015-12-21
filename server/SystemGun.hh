//
// SystemGun.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Nov 30 02:21:19 2015 Louis Audibert
// Last update Wed Dec 16 06:01:33 2015 Louis Audibert
//

#ifndef _SYSTEMGUN_HH_
# define _SYSTEMGUN_HH_

# include <iostream>
# include <ASystem.hpp>
# include <ComponentMissile.hh>
# include <ComponentRiffle.hh>
# include <ComponentLaser.hh>

class SystemGun : public ASystem
{
private:
  E_Component _type;

public:
  SystemGun(E_Component type);
  ~SystemGun();

  E_Component getType();
};

#endif /* _SYSTEMGUN_HH_ */
