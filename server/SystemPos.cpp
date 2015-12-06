//
// SystemPos.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Nov 30 01:53:22 2015 Louis Audibert
// Last update Thu Dec  3 05:33:11 2015 Louis Audibert
//

#include <SystemPos.hh>

SystemPos::SystemPos()
{
  _component = new Position();
}

SystemPos::~SystemPos()
{
  std::cout << "SystemPos Destroyed" << std::endl;
}

bool	SystemPos::update(int x, int y)
{
  dynamic_cast<Position*>(_component)->setX(x);
  dynamic_cast<Position*>(_component)->setY(y);
  return(true);
}
