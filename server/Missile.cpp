//
// Missile.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sun Dec 13 05:02:38 2015 Louis Audibert
// Last update Sun Dec 13 05:03:55 2015 Louis Audibert
//

#include <Missile.hh>

Missile::Missile(int id, AEntity *parent) : AEntity(id, parent)
{
  _name = "Missile";
}

Missile::~Missile()
{

}
