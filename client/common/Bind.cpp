//
// Bind.cpp for Bind in /home/barnea_v/rendu/rtype_cpp/client/common
//
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
//
// Started on  Mon Nov 30 09:51:14 2015 Viveka BARNEAUD
// Last update Wed Dec  9 13:42:40 2015 Nicolas Girardot
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
	std::cout << "set key" << std::endl;
    _key = key;
}

void    Bind::setJoystick(JoystickEvent joystick)
{
    _joystick = joystick;
}
