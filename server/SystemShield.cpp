//
// SystemShield.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Dec 21 02:24:30 2015 Louis Audibert
// Last update Mon Dec 21 02:26:03 2015 Louis Audibert
//

#include <SystemShield.hh>

SystemShield::SystemShield()
{

}

SystemShield::~SystemShield()
{

}

bool	SystemShield::update(bool shield)
{
  dynamic_cast<ComponentShield*>(_component)->setShield(shield);
  return (true);
}
