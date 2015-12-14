//
// Laser.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sun Dec 13 05:07:55 2015 Louis Audibert
// Last update Mon Dec 14 08:10:53 2015 Louis Audibert
//

#include <Laser.hh>

Laser::Laser(int id) : AEntity(id)
{
  addSystem(C_POSITION);
  _name = "Laser:" + _parent->getName();
}

Laser::~Laser()
{

}
