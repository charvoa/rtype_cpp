//
// Laser.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sun Dec 13 05:07:55 2015 Louis Audibert
// Last update Sat Dec 19 12:40:50 2015 Louis Audibert
//

#include <Laser.hh>

Laser::Laser(int id) : AEntity(id)
{
  addSystem(C_POSITION);
  _name = "7:" + _parent->getName();
}

Laser::~Laser()
{

}
