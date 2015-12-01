//
// Vector2.cpp for Vector2 in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Wed Nov 25 04:21:14 2015 Serge Heitzler
// Last update Tue Dec  1 11:59:29 2015 Nicolas Girardot
//

#include "Vector2.hh"

template <typename T>
Vector2<T>::Vector2(T x, T y)
{
  _x = x;
  _y = y;
}

template <typename T>
Vector2<T>::~Vector2()
{

}

template class Vector2<int>;
