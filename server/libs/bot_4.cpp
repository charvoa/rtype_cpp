//
// bot_4.cpp for rtype in /home/audibel/rendu/rtype_cpp/server/libs
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Dec 21 01:45:11 2015 Louis Audibert
// Last update Tue Dec 22 03:42:33 2015 Serge Heitzler
//

#include <iostream>
#include <Bot.hpp>

Bot::Bot(int id) : AEntity(id), _health(50), _y(0), _direction(1)
{
  _sprite = "sprite2.png";
  _name = _sprite;
  addSystem(C_HEALTH);
  addSystem(C_POSITION);
  addSystem(C_HITBOX);
  generateX();
  generateY();
  dynamic_cast<SystemPos*>(_systemManager->getSystemByComponent(C_POSITION))->update(_x, _y);
}

Bot::~Bot()
{

}

void	Bot::generateX()
{
  Random rand(WIDTH + 100, WIDTH + 900);

  _x = rand.generate<int>();
}

void	Bot::generateY()
{
  Random rand(35, HEIGHT + 1);

  _y = rand.generate<int>();
}

void	Bot::update()
{
  if (_x > 900)
    _direction = -1;
  else if (_x < 600)
    _direction = 1;
  else
    _direction = 0;

  if (_direction == 1 && _y < 855)
    _y++;
  else if (_direction == -1 && _y > 35)
    _y--;

  _x--;
  dynamic_cast<SystemPos*>(_systemManager->getSystemByComponent(C_POSITION))->update(_x, _y);
}

extern "C" AEntity* create_object(int id)
{
  return new Bot(id);
}
