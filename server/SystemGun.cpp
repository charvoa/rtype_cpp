//
// SystemGun.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Nov 30 02:23:44 2015 Louis Audibert
// Last update Tue Dec  8 22:23:43 2015 Nicolas Charvoz
//

#include <SystemGun.hh>

SystemGun::SystemGun(E_Component type)
{
  switch (type)
    {
    case E_LASER:
      _component = new Laser();
      break;
    case E_RIFLE:
      _component = new Rifle();
      break;
    case E_MISSILE:
      _component = new Missile();
      break;
    default:
      break;
    }
}

SystemGun::~SystemGun()
{
  std::cout << "System Gun Destroyed" << std::endl;
}
