//
// Laser.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sun Dec 13 05:07:55 2015 Louis Audibert
// Last update Sun Dec 13 05:27:01 2015 Louis Audibert
//

#include <Laser.hh>

Laser::Laser(int id, AEntity *parent) : AEntity(id, parent)
{
  _name = "Laser:" + parent->getName();
}

Laser::~Laser()
{

}
