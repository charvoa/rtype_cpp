//
// bot_4.cpp for rtype in /home/audibel/rendu/rtype_cpp/server/libs
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Dec 21 01:45:11 2015 Louis Audibert
// Last update Tue Dec 22 03:34:10 2015 Louis Audibert
//

#include <iostream>
#include <Bot.hpp>

Bot::Bot(int id) : AEntity(id), _health(50), _x(WIDTH + 100), _y(0), _direction(1)
{
  _sprite = "sprite2.png";
  _name = _sprite;
  _type = E_BOT;
  addSystem(C_HEALTH);
  addSystem(C_POSITION);
  addSystem(C_HITBOX);
  generateY();
  dynamic_cast<SystemPos*>(_systemManager->getSystemByComponent(C_POSITION))->update(_x, _y);
  dynamic_cast<SystemHitbox*>(_systemManager->getSystemByComponent(C_HITBOX))->update(refreshHitbox());
}

Bot::~Bot()
{

}

void	Bot::generateY()
{
  Random rand(35, HEIGHT + 1);

  _y = rand.generate<int>();
}

std::list<Case*> Bot::refreshHitbox()
{
  std::list<Case*> hitbox;
  Case	*myCase;

  myCase = new Case;
  myCase->x = reinterpret_cast<ComponentPosition*>(_systemManager->getSystemByComponent(C_POSITION)->getComponent())->getX();
  myCase->y = reinterpret_cast<ComponentPosition*>(_systemManager->getSystemByComponent(C_POSITION)->getComponent())->getY() - 67;
  hitbox.push_back(myCase);

  myCase = new Case;
  myCase->x = reinterpret_cast<ComponentPosition*>(_systemManager->getSystemByComponent(C_POSITION)->getComponent())->getX();
  myCase->y = reinterpret_cast<ComponentPosition*>(_systemManager->getSystemByComponent(C_POSITION)->getComponent())->getY() + 67;
  hitbox.push_back(myCase);

  return (hitbox);
}

void	Bot::update()
{
  if (_x > 900)
    _direction = -1;
  else if (_x < 700)
    _direction = 1;
  else
    _direction = 0;

  if (_direction == 1 && _y < 855)
    _y++;
  else if (_direction == -1 && _y > 35)
    _y--;

  _x--;
  dynamic_cast<SystemPos*>(_systemManager->getSystemByComponent(C_POSITION))->update(_x, _y);
  dynamic_cast<SystemHitbox*>(_systemManager->getSystemByComponent(C_HITBOX))->update(refreshHitbox());
}

extern "C" AEntity* create_object(int id)
{
  return new Bot(id);
}
