//
// Position.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sat Nov 28 05:15:28 2015 Louis Audibert
// Last update Mon Nov 30 01:31:51 2015 Louis Audibert
//

#ifndef _POSITION_HH_
# define _POSITION_HH_

# include <string>
# include <iostream>
# include "IComponent.hh"

class Position : public IComponent
{
private:
  int	_x;
  int	_y;

public:
  Position();
  Position(int x, int y);
  ~Position();

  int	getX() const;
  int	getY() const;
  void	setX(int x);
  void	setY(int y);
};

#endif /* _POSITION_HH_ */
