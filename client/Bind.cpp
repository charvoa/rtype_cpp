#include "bind.hh"

Bind::Bind(Bind::BindType type, sf::Event::key key, sf::Event::Joystick joystick)
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

sf::Event::key Bind::getKey() const
{
    return _key;
}

sf::Event::joystick Bind::getJoystick() const
{
    return _joystick;
}

void    Bind::setType(Bind::BindType type)
{
    _type = type;
}

void    Bind::setKey(sf::Event::key key)
{
    _key = key;
}

void    Bind::setJoystick(sf::Event::joystick joystick)
{
    _joystick = joystick;
}
