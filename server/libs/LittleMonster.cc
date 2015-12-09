//
// LittleMonster.cc for rtype in /home/audibel/rendu/rtype_cpp/server/libs
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Dec  7 00:54:35 2015 Louis Audibert
// Last update Tue Dec  8 07:24:24 2015 Louis Audibert
//

#include <iostream>
#include "LittleMonster.hh"

LittleMonster::LittleMonster(int id) : AEntity(id), _health(50), _x(0), _y(0), _direction(1)
{

}

LittleMonster::~LittleMonster()
{

}

void LittleMonster::update()
{
  if (_y == 255)
    _direction = -1;
  else if (_y == -255)
    _direction = 1;

  if (_direction == 1)
    _y++;
  else if (_direction == -1)
    _y--;

  _x += 1;

  //dynamic_cast<SystemHealth*>(_systemManager.getSystemByComponent(E_HEALTH))->update(_health++);
  dynamic_cast<SystemPos*>(_systemManager.getSystemByComponent(E_POSITION))->update(_x, _y);
}

extern "C" LittleMonster* create_object(int id)
{
  return new LittleMonster(id);
}
