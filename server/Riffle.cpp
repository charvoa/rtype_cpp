//
// Riffle.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sun Dec 13 04:55:06 2015 Louis Audibert
// Last update Mon Dec 14 17:36:27 2015 Nicolas Charvoz
//

#include <Riffle.hh>

Riffle::Riffle(int id) : AEntity(id)
{
  _name = "Riffle";
  addSystem(C_POSITION);
  ComponentPosition *pos = reinterpret_cast<ComponentPosition*>(this->_parent->getSystemManager()->getSystemByComponent(C_POSITION)->getComponent());

  this->update(pos->getX(), pos->getY());

}

Riffle::~Riffle()
{

}
