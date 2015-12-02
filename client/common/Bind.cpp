//
// Bind.cpp for Bind in /home/barnea_v/rendu/rtype_cpp/client/common
// 
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
// 
// Started on  Mon Nov 30 09:51:14 2015 Viveka BARNEAUD
// Last update Mon Nov 30 16:55:21 2015 Viveka BARNEAUD
//

#include "Bind.hh"

Bind::Bind(Bind::BindType type, sf::Event key, sf::Event joystick)
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

sf::Event Bind::getKey() const
{
    return _key;
}

sf::Event Bind::getJoystick() const
{
    return _joystick;
}

void    Bind::setType(Bind::BindType type)
{
    _type = type;
}

void    Bind::setKey(sf::Event key)
{
    _key = key;
}

void    Bind::setJoystick(sf::Event joystick)
{
    _joystick = joystick;
}
