//
// Vector2.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Mon Nov 23 08:20:13 2015 Serge Heitzler
// Last update Wed Nov 25 02:43:23 2015 Serge Heitzler
//

#ifndef VECTOR2_HH_
#define VECTOR2_HH_

class	        Vector2 : public IVector2
{

  Vector2(int x, int y);
  ~Vector2();

public:

  int		_x;
  int		_y;

};

#endif /* !VECTOR2_HH_ */
