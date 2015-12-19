//
// Missile.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sun Dec 13 05:02:38 2015 Louis Audibert
// Last update Sat Dec 19 15:20:12 2015 Louis Audibert
//

#include <Missile.hh>

Missile::Missile(int id) : AEntity(id)
{
  addSystem(C_POSITION);
  _name = "6";
}

Missile::~Missile()
{

}
