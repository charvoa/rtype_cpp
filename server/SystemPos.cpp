//
// SystemPos.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Nov 30 01:53:22 2015 Louis Audibert
// Last update Mon Dec 21 10:26:53 2015 Nicolas Charvoz
//

#include <SystemPos.hh>

SystemPos::SystemPos()
{
  _component = new ComponentPosition();
  //  std::cout << "new SystemPos created." << std::endl;
}

SystemPos::~SystemPos()
{
  //std::cout << "SystemPos Destroyed" << std::endl;
}

bool	SystemPos::update(int x, int y)
{
  dynamic_cast<ComponentPosition*>(_component)->setX(x);
  dynamic_cast<ComponentPosition*>(_component)->setY(y);
  return(true);
}
