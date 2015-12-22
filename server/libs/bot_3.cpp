//
// bot_3.cpp for rtype in /home/audibel/rendu/rtype_cpp/server/libs
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Tue Dec 15 05:23:35 2015 Louis Audibert
//

#include <iostream>
#include <Bot.hpp>

Bot::Bot(int id) : AEntity(id), _health(50), _y(0)
{
  _sprite = "sprite1.png";
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
  Random rand(100, 700);

  _y = rand.generate<int>();
}

void	Bot::update()
{
  _x -= 7;
  dynamic_cast<SystemPos*>(_systemManager->getSystemByComponent(C_POSITION))->update(_x, _y);
}

extern "C" AEntity* create_object(int id)
{
  return new Bot(id);
}
