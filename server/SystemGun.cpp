//
// SystemGun.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Nov 30 02:23:44 2015 Louis Audibert
// Last update Sun Dec 13 04:53:29 2015 Louis Audibert
//

#include <SystemGun.hh>

SystemGun::SystemGun(E_Component type)
{
  switch (type)
    {
    case E_LASER:
      _component = new ComponentLaser();
      break;
    case E_RIFLE:
      _component = new ComponentRiffle();
      break;
    case E_MISSILE:
      _component = new ComponentMissile();
      break;
    default:
      break;
    }
}

SystemGun::~SystemGun()
{
  std::cout << "System Gun Destroyed" << std::endl;
}
