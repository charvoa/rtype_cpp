//
// LittleMonster.cc for rtype in /home/audibel/rendu/rtype_cpp/server/libs
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Dec  7 00:54:35 2015 Louis Audibert
// Last update Fri Dec 11 17:39:18 2015 Joris Bertomeu
//

#include <iostream>
#include "Bot.hpp"

Bot::Bot(int id) : AEntity(id)
{
  std::cout << "Bot :: Bot2 :: Constructor" << std::endl;
}

Bot::~Bot()
{

}

void Bot::update()
{
  // if (_y == 255)
  //   _direction = -1;
  // else if (_y == -255)
  //   _direction = 1;

  // if (_direction == 1)
  //   _y++;
  // else if (_direction == -1)
  //   _y--;

  // _x += 1;
  std::cout << "Bot :: Bot2 :: Update" << std::endl;
  //dynamic_cast<SystemHealth*>(_systemManager.getSystemByComponent(E_HEALTH))->update(_health++);
  // dynamic_cast<SystemPos*>(_systemManager.getSystemByComponent(E_POSITION))->update(_x, _y);
}

extern "C" AEntity* create_object(int id)
{
  return new Bot(id);
}
