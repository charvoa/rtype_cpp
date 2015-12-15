//
// bot_3.cpp for rtype in /home/audibel/rendu/rtype_cpp/server/libs
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Tue Dec 15 05:23:35 2015 Louis Audibert
// Last update Tue Dec 15 05:29:07 2015 Louis Audibert
//

#include <iostream>
#include <Bot.hpp>

Bot::Bot(int id) : AEntity(id), _health(50), _x(275), _y(0)
{
  std::cout << "Bot :: Bot3 :: Constructor" << std::endl;
  _sprite = "sprite1.png";
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

void	Bot::update()
{
  _x -= 5;
  std::cout << "Bot :: Bot3 :: Update" << std::endl;
  dynamic_cast<SystemPos*>(_systemManager.getSystemByComponent(C_POSITION))->update(_x, _y);
}

extern "C" AEntity* create_object(int id)
{
  return new Bot(id);
}
