//
// Riffle.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sun Dec 13 04:55:06 2015 Louis Audibert
// Last update Sun Dec 13 04:58:11 2015 Louis Audibert
//

#include <Riffle.hh>

Riffle::Riffle(int id, AEntity *parent) : AEntity(id, parent)
{
  _name = "Riffle";
}

Riffle::~Riffle()
{

}
