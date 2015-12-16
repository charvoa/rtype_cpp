//
// LittleMonster.cc for rtype in /home/audibel/rendu/rtype_cpp/server/libs
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Dec  7 00:54:35 2015 Louis Audibert
// Last update Wed Dec 16 08:27:04 2015 Louis Audibert
//

#include <iostream>
#include "Bot.hpp"

Bot::Bot(int id) : AEntity(id), _health(100), _x(WIDTH + 20), _y(0), _direction(0)
{
  std::cout << "Bot :: Bot2 :: Constructor" << std::endl;
  _sprite = "sprite6.png";
  _name = _sprite;
  addSystem(C_HEALTH);
  addSystem(C_POSITION);
  generateY();
  dynamic_cast<SystemPos*>(_systemManager.getSystemByComponent(C_POSITION))->update(_x, _y);
}

Bot::~Bot()
{

}

void	Bot::generateY()
{
  Random rand(0, HEIGHT + 1);

  _y = rand.generate<int>();
}

void Bot::update()
{
  _x--;
  dynamic_cast<SystemPos*>(_systemManager.getSystemByComponent(C_POSITION))->update(_x, _y);
  // if (_y >= (HEIGHT / 2))
  //   {
  //     if (_y == (HEIGHT / 2))
  // 	_direction = 1;
  //     else if (_y == HEIGHT)
  // 	_direction = 0;
  //   }
  // else if (_y <= (HEIGHT / 2) - 1)
  //   {
  //     if (_y == (HEIGHT / 2) - 1)
  // 	_direction = 0;
  //     else if (_y == 0)
  // 	_direction = 1;
  //   }

  // if (_direction == 1)
  //   _y++;
  // else if (_direction == 0)
  //   _y--;

  // _x--;
  // std::cout << "Bot :: Bot2 :: Update" << std::endl;
  // dynamic_cast<SystemPos*>(_systemManager.getSystemByComponent(C_POSITION))->update(_x, _y);
}

extern "C" AEntity* create_object(int id)
{
  return new Bot(id);
}
