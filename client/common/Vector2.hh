//
// Vector2.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Mon Nov 23 08:20:13 2015 Serge Heitzler
<<<<<<< HEAD
// Last update Mon Nov 30 06:18:34 2015 Serge Heitzler
=======
// Last update Wed Nov 25 16:31:02 2015 Nicolas Girardot
>>>>>>> 02a251ffe5f072a58c677484f844235795494e85
//

#ifndef VECTOR2_HH_
#define VECTOR2_HH_

<<<<<<< HEAD
template <typename T>
class	        Vector2 : public IVector2
{

  Vector2(T x, T y);
=======
#include "IVector2.hh"

class	        Vector2 : public IVector2
{
public:
  Vector2(int x, int y);
>>>>>>> 02a251ffe5f072a58c677484f844235795494e85
  ~Vector2();


  T		_x;
  T		_y;

};

#endif /* !VECTOR2_HH_ */
