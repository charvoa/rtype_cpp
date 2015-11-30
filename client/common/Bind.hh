//
// Bind.hh for Bind in /home/barnea_v/rendu/rtype_cpp/client/common
// 
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
// 
// Started on  Mon Nov 30 09:50:51 2015 Viveka BARNEAUD
// Last update Mon Nov 30 09:55:48 2015 Viveka BARNEAUD
//

#ifndef BIND_HH
#define BIND_HH

#include <SFML/Graphics.hpp>
#include <SFML/Event.hpp>

class Bind
{
public:
    typedef enum e_BindType
    {
        ATTACK_BIND,
        MOVE_UP_BIND,
        MOVE_DOWN_BIND,
        MOVE_LEFT_BIND,
        MOVE_RIGHT_BIND,
        LEAVE_GAME_BIND,
        WEAPON_1,
        WEAPON_2,
        WEAPON_3
    } BindType;

    Bind(Bind::BindType, sf::Event::key, sf::Event::joystick);
    ~Bind();

    Bind::BindType getType() const;
    sf::Event getKey() const;
    sf::Event getJoystick() const;

    void setType(Bind::BindType);
    void setKey(sf::Event::key);
    void setJoystick(sf::Event::joystick);

private:
    Bind::BindType _type;
    sf::Event _key;
    sf::Event _joystick;
};

#endif // BIND_HH
