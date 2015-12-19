//
// LittleMonster.cc for rtype in /home/audibel/rendu/rtype_cpp/server/libs
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Dec  7 00:54:35 2015 Louis Audibert
// Last update Sat Dec 19 11:30:34 2015 Nicolas Girardot
//

#include <iostream>
#include <Bot.hpp>

Bot::Bot(int id) : AEntity(id), _health(50), _x(WIDTH + 20), _y(0), _direction(1)
{
  std::cout << "Bot :: Bot1 :: Constructor" << std::endl;
  _sprite = "sprite3.png";
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
  Random rand(0, HEIGHT + 1);

  _y = rand.generate<int>();
}

void	Bot::update()
{
  _x--;
  if (ComponentPosition *com = reinterpret_cast<ComponentPosition*>(getSystemManager()->getSystemByComponent(C_POSITION)->getComponent()))
    std::cout << "BLABLABLA" << com->getX() << std::endl;
  //  getSystemManager()->getSystemByComponent(C_POSITION)->update(1,1);
  dynamic_cast<SystemPos*>(_systemManager.getSystemByComponent(C_POSITION))->update(_x, _y);


  ComponentPosition *pos = reinterpret_cast<ComponentPosition*>(this->getSystemManager()->getSystemByComponent(C_POSITION)->getComponent());
  std::cout << "Position of bot1 >> " << this->getId() << ": " << pos->getX() << " ; " << pos->getY() << " << " << std::endl;


  if (_y == HEIGHT)
    _direction = -1;
  else if (_y == 0)
    _direction = 1;

  if (_direction == 1)
    _y++;
  else if (_direction == -1)
    _y--;

  _x--;
  std::cout << "Bot :: Bot1 :: Update" << std::endl;
  dynamic_cast<SystemPos*>(_systemManager.getSystemByComponent(C_POSITION))->update(_x, _y);
}

extern "C" AEntity* create_object(int id)
{
  return new Bot(id);
}
