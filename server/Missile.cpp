//
// Missile.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sun Dec 13 05:02:38 2015 Louis Audibert
// Last update Sun Dec 20 16:38:22 2015 Nicolas Charvoz
//

#include <Missile.hh>

Missile::Missile(int id) : AEntity(id)
{
  addSystem(C_POSITION);
  addSystem(C_HITBOX);
  _name = "6";
}

Missile::~Missile()
{

}
