//
// Position.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sat Nov 28 05:15:28 2015 Louis Audibert
// Last update Mon Dec 21 02:19:42 2015 Louis Audibert
//

#ifndef _COMPONENTPOSITION_HH_
# define _COMPONENTPOSITION_HH_

# include <string>
# include <iostream>
# include <AComponent.hpp>

class ComponentPosition : public AComponent
{
private:
  int	_x;
  int	_y;

public:
  ComponentPosition();
  ComponentPosition(int x, int y);
  ~ComponentPosition();

  int	getX() const;
  int	getY() const;
  void	setX(int x);
  void	setY(int y);
};

#endif /* _POSITION_HH_ */
