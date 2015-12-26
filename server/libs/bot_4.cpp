//
// bot_4.cpp for rtype in /home/audibel/rendu/rtype_cpp/server/libs
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Dec 21 01:45:11 2015 Louis Audibert
// Last update Thu Dec 24 02:28:49 2015 Louis Audibert
//

#include <iostream>
#include <Bot.hpp>

Bot::Bot(int id) : AEntity(id), _health(50), _y(0), _direction(1)
{
  _timerShoot = new Timer(true);
  _sprite = "sprite2.png";
  _name = _sprite;
  _type = E_BOT;
  addSystem(C_HEALTH);
  addSystem(C_POSITION);
  addSystem(C_HITBOX);
  generateX();
  generateY();
  dynamic_cast<SystemPos*>(_systemManager->getSystemByComponent(C_POSITION))->update(_x, _y);
  dynamic_cast<SystemHitbox*>(_systemManager->getSystemByComponent(C_HITBOX))->update(refreshHitbox());
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
  else if (_x < 600)
    _direction = 1;
  else
    _direction = 0;

  if (_direction == 1 && _y < 820)
    _y++;
  else if (_direction == -1 && _y > 70)
    _y--;

  _x -= 4;
  dynamic_cast<SystemPos*>(_systemManager->getSystemByComponent(C_POSITION))->update(_x, _y);
  dynamic_cast<SystemHitbox*>(_systemManager->getSystemByComponent(C_HITBOX))->update(refreshHitbox());
  if (_timerShoot->elapsed().count() > 2 && _x < WIDTH)
    {
      _timerShoot->reset();
    }
}

extern "C" AEntity* create_object(int id)
{
  return new Bot(id);
}
