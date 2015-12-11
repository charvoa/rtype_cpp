//
// PlayerIG.cpp for RTYPOE in /home/nicolas/rendu/rtype_cpp/client/common
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri Dec 11 14:49:27 2015 Nicolas Girardot
// Last update Fri Dec 11 17:29:58 2015 Nicolas Girardot
//

#include <PlayerIG.hh>

PlayerIG::PlayerIG()
{
  _life = new Text();
  _nbrLife = 3;
  _name = new Text();
}

PlayerIG::~PlayerIG()
{

}

void	PlayerIG::setLife(unsigned int i)
{
  _nbrLife = i;
}

const std::string &PlayerIG::getName()
{
  return _nameValue;
}

void	PlayerIG::setName(const std::string &name)
{
  _nameValue = name;
  _name->setString(name);
}
