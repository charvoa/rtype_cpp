//
// Position.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sat Nov 28 05:15:28 2015 Louis Audibert
// Last update Thu Dec  3 05:27:35 2015 Louis Audibert
//

#ifndef _POSITION_HH_
# define _POSITION_HH_

# include <string>
# include <iostream>
# include <AComponent.hpp>

class Position : public AComponent
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
