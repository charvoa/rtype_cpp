//
// Riffle.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sun Dec 13 04:55:06 2015 Louis Audibert
// Last update Mon Dec 14 17:45:46 2015 Nicolas Charvoz
//

#include <Riffle.hh>

Riffle::Riffle(int id) : AEntity(id)
{
  _name = "E_RIFLE";
  addSystem(C_POSITION);
  std::cout << "Je créé un rifle" << std::endl;
}

Riffle::~Riffle()
{

}
