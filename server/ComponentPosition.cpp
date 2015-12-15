//
// Position.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sat Nov 28 05:20:29 2015 Louis Audibert
// Last update Mon Dec 21 01:26:02 2015 Louis Audibert
//

#include <ComponentPosition.hh>

ComponentPosition::ComponentPosition() : _x(0), _y(0)
{

}

ComponentPosition::ComponentPosition(int x, int y) : _x(x), _y(y)
{

}

ComponentPosition::~ComponentPosition()
{
}

int	ComponentPosition::getX() const
{
  return (_x);
}

int	ComponentPosition::getY() const
{
  return (_y);
}

void	ComponentPosition::setX(int x)
{
  _x = x;
}

void	ComponentPosition::setY(int y)
{
  _y = y;
}
