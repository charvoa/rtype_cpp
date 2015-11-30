//
// Vector2.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Mon Nov 23 08:20:13 2015 Serge Heitzler
// Last update Wed Nov 25 16:31:02 2015 Nicolas Girardot
//

#ifndef VECTOR2_HH_
#define VECTOR2_HH_

#include "IVector2.hh"

class	        Vector2 : public IVector2
{
public:
  Vector2(int x, int y);
  ~Vector2();


  int		_x;
  int		_y;

};

#endif /* !VECTOR2_HH_ */
