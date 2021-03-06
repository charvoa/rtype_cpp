//
// SystemGun.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Nov 30 02:23:44 2015 Louis Audibert
// Last update Mon Dec 21 01:33:53 2015 Louis Audibert
//

#include <SystemGun.hh>

SystemGun::SystemGun(E_Component type)
{
  _type = type;
  switch (type)
    {
    case C_LASER:
      _component = new ComponentLaser();
      break;
    case C_RIFLE:
      _component = new ComponentRiffle();
      break;
    case C_MISSILE:
      _component = new ComponentMissile();
      break;
    default:
      break;
    }
}

SystemGun::~SystemGun()
{
}

E_Component SystemGun::getType()
{
  return (_type);
}
