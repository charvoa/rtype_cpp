//
// Bind.hh for Bind in /home/barnea_v/rendu/rtype_cpp/client/common
//
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
//
// Started on  Mon Nov 30 09:50:51 2015 Viveka BARNEAUD
// Last update Thu Dec  3 17:14:46 2015 Nicolas Girardot
//

#ifndef BIND_HH
#define BIND_HH

#include <SFML/Graphics.hpp>
#include <JoystickEvent.hpp>

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

  Bind(Bind::BindType, sf::Keyboard::Key, JoystickEvent);
  ~Bind();

  Bind::BindType getType() const;
  sf::Keyboard::Key getKey() const;
  JoystickEvent getJoystick() const;

  void setType(Bind::BindType);
  void setKey(sf::Keyboard::Key);
  void setJoystick(JoystickEvent);

private:
  Bind::BindType _type;
  sf::Keyboard::Key _key;
  JoystickEvent _joystick;
};

#endif // BIND_HH
