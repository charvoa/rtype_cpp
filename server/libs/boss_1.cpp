//
// boss_1.cpp for rtype in /home/audibel/rendu/rtype_cpp/server/libs
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Tue Dec 15 05:41:34 2015 Louis Audibert
// Last update Wed Dec 23 08:31:03 2015 Louis Audibert
//

#include <iostream>
#include <Bot.hpp>
#include <Game.hh>

Bot::Bot(int id) : AEntity(id), _health(1500), _y(0), _direction(1)
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
    _direction = 1;
  if (_direction == -1)
    _x -= 3;

  dynamic_cast<SystemPos*>(_systemManager->getSystemByComponent(C_POSITION))->update(_x, _y);
  dynamic_cast<SystemHitbox*>(_systemManager->getSystemByComponent(C_HITBOX))->update(refreshHitbox());
  if (_timerShoot->elapsed().count() > 2)
    {
      _timerShoot->reset();
      _currentGame->shootBot(this);
    }
}

extern "C" AEntity* create_object(int id)
{
  return new Bot(id);
}
