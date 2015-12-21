//
// ComponentShield.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Dec 21 02:18:20 2015 Louis Audibert
// Last update Mon Dec 21 02:22:16 2015 Louis Audibert
//

#include <ComponentShield.hh>

ComponentShield::ComponentShield() : _shield(false)
{

}

ComponentShield::~ComponentShield()
{

}

bool	ComponentShield::getShield() const
{
  return (_shield);
}

void	ComponentShield::setShield(bool shield)
{
  _shield = shield;
}
