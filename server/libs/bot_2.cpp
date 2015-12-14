//
// LittleMonster.cc for rtype in /home/audibel/rendu/rtype_cpp/server/libs
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Dec  7 00:54:35 2015 Louis Audibert
// Last update Sat Dec 12 08:39:55 2015 Joris Bertomeu
//

#include <iostream>
#include "Bot.hpp"

Bot::Bot(int id) : AEntity(id), _health(100), _x(275), _y(0), _direction(0)
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
  Random rand(0, 255);

  _y = rand.generate<int>();
}

void Bot::update()
{
  std::cout << "Bot :: Bot2 :: Update" << std::endl;
  //dynamic_cast<SystemHealth*>(_systemManager.getSystemByComponent(C_HEALTH))->update(_health++);
  // dynamic_cast<SystemPos*>(_systemManager.getSystemByComponent(C_POSITION))->update(_x, _y);
}

extern "C" AEntity* create_object(int id)
{
  return new Bot(id);
}
