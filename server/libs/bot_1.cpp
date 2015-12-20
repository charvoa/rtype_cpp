//
// LittleMonster.cc for rtype in /home/audibel/rendu/rtype_cpp/server/libs
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Dec  7 00:54:35 2015 Louis Audibert
<<<<<<< HEAD
// Last update Sun Dec 20 16:38:48 2015 Nicolas Charvoz
=======
// Last update Sun Dec 20 07:10:11 2015 Louis Audibert
>>>>>>> 552b730d25c20f089732f4a681fbfc0002191495
//

#include <iostream>
#include <Bot.hpp>

Bot::Bot(int id) : AEntity(id), _health(50), _x(WIDTH + 100), _y(0), _direction(1)
{
  _sprite = "sprite3.png";
  _name = _sprite;
  addSystem(C_HEALTH);
  addSystem(C_POSITION);
  addSystem(C_HITBOX);
  generateY();
  dynamic_cast<SystemPos*>(_systemManager->getSystemByComponent(C_POSITION))->update(_x, _y);
}

Bot::~Bot()
{

}

void	Bot::generateY()
{
  Random rand(35, HEIGHT + 1);

  _y = rand.generate<int>();
}

void	Bot::update()
{
  if (_y == HEIGHT)
    _direction = -1;
  else if (_y == 35)
    _direction = 1;

  if (_direction == 1)
    _y++;
  else if (_direction == -1)
    _y--;

  _x--;
  dynamic_cast<SystemPos*>(_systemManager->getSystemByComponent(C_POSITION))->update(_x, _y);
}

extern "C" AEntity* create_object(int id)
{
  return new Bot(id);
}
