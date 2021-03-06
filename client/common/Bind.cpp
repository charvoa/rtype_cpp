//
// Bind.cpp for Bind in /home/barnea_v/rendu/rtype_cpp/client/common
//
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
//
// Started on  Mon Nov 30 09:51:14 2015 Viveka BARNEAUD
// Last update Sun Dec 27 08:17:35 2015 Serge Heitzler
//

#include <iostream>
#include <Bind.hh>

Bind::Bind(Bind::BindType type, sf::Keyboard::Key key, JoystickEvent joystick)
{
  _type = type;
  _key = key;
  _joystick = joystick;
}

Bind::~Bind(){}

Bind::BindType Bind::getType() const
{
  return _type;
}

sf::Keyboard::Key Bind::getKey() const
{
  return _key;
}

JoystickEvent Bind::getJoystick() const
{
  return _joystick;
}

void    Bind::setType(Bind::BindType type)
{
  _type = type;
}

void    Bind::setKey(sf::Keyboard::Key key)
{
  _key = key;
}

void    Bind::setJoystick(JoystickEvent joystick)
{
  _joystick = joystick;
}
