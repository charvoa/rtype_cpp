//
// boss_1.cpp for rtype in /home/audibel/rendu/rtype_cpp/server/libs
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Tue Dec 15 05:41:34 2015 Louis Audibert
//

#include <iostream>
#include <Bot.hpp>

Bot::Bot(int id) : AEntity(id), _health(50), _y(0), _direction(1)
{
  _timerShoot = new Timer(true);
  _sprite = "sprite4.png";
  _name = _sprite;
  _type = E_BOT;
  _isBoss = true;
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
  _x = WIDTH + 200;
}

void	Bot::generateY()
{
  _y = 445;
}

std::list<Case*> Bot::refreshHitbox()
{
  std::list<Case*> hitbox;
  Case	*myCase;

  myCase = new Case;
  myCase->x = reinterpret_cast<ComponentPosition*>(_systemManager->getSystemByComponent(C_POSITION)->getComponent())->getX();
  myCase->y = reinterpret_cast<ComponentPosition*>(_systemManager->getSystemByComponent(C_POSITION)->getComponent())->getY() - 332;
  hitbox.push_back(myCase);

  myCase = new Case;
  myCase->x = reinterpret_cast<ComponentPosition*>(_systemManager->getSystemByComponent(C_POSITION)->getComponent())->getX();
  myCase->y = reinterpret_cast<ComponentPosition*>(_systemManager->getSystemByComponent(C_POSITION)->getComponent())->getY() + 332;
  hitbox.push_back(myCase);

  return (hitbox);
}

void	Bot::update()
{
  if (_x >= 1500)
    _direction = -1;
  else
    _direction = 2;
  if (_direction == -1)
    _x -= 3;

  if (_direction == 2 && _y >= 250)
    _y -= 5;

  if (_direction == 3 && _y <= 640)
    _y += 5;

  if (_y == 300)
    _direction = 3;

  if (_y == 590)
    _direction = 2;

  dynamic_cast<SystemPos*>(_systemManager->getSystemByComponent(C_POSITION))->update(_x, _y);
  dynamic_cast<SystemHitbox*>(_systemManager->getSystemByComponent(C_HITBOX))->update(refreshHitbox());
}

// bool Bot::isInScreen() const {
//   if (_timerShoot->elapsedMilli().count() > 500 && _x < WIDTH) {
//     _timerShoot->reset();
//     return true;
//   }
//   return false;
// }

extern "C" AEntity* create_object(int id)
{
  return new Bot(id);
}
