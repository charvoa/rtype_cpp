//
// Vector2.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Mon Nov 23 08:20:13 2015 Serge Heitzler
// Last update Mon Nov 30 06:18:34 2015 Serge Heitzler
//

#ifndef VECTOR2_HH_
#define VECTOR2_HH_

template <typename T>
class	        Vector2 : public IVector2
{

  Vector2(T x, T y);
  ~Vector2();

public:

  T		_x;
  T		_y;

};

#endif /* !VECTOR2_HH_ */
