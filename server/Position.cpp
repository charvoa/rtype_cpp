//
// Position.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sat Nov 28 05:20:29 2015 Louis Audibert
// Last update Mon Nov 30 01:32:29 2015 Louis Audibert
//

#include "Position.hh"

Position::Position() : _x(0), _y(0)
{

}

Position::Position(int x, int y) : _x(x), _y(y)
{

}

Position::~Position()
{
  std::cout << "Position Component Destroyed." << std::endl;
}

int	Position::getX() const
{
  return (_x);
}

int	Position::getY() const
{
  return (_y);
}

void	Position::setX(int x)
{
  _x = x;
}

void	Position::setY(int y)
{
  _y = y;
}
