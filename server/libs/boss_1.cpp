//
// boss_1.cpp for rtype in /home/audibel/rendu/rtype_cpp/server/libs
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Tue Dec 15 05:41:34 2015 Louis Audibert
// Last update Tue Dec 15 06:09:30 2015 Louis Audibert
//

#include <iostream>
#include <Bot.hpp>

Bot::Bot(int id) : AEntity(id), _health(500), _x(180), _y(0), _direction(1)
{
  std::cout << "Boss :: Boss1 :: Constructor" << std::endl;
  _sprite = "sprite4.png";
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
  Random rand(0, 50);

  _y = rand.generate<int>();
}

void	Bot::update()
{
  if (_x >= 200)
    _direction = -1;
  if (_direction == -1)
    _x--;

  std::cout << "Boss :: Boss1 :: Update" << std::endl;
  dynamic_cast<SystemHealth*>(_systemManager.getSystemByComponent(C_HEALTH))->update(_health++);
  dynamic_cast<SystemPos*>(_systemManager.getSystemByComponent(C_POSITION))->update(_x, _y);
}

extern "C" AEntity* create_object(int id)
{
  return new Bot(id);
}
