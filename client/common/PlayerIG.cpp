//
// PlayerIG.cpp for RTYPOE in /home/nicolas/rendu/rtype_cpp/client/common
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri Dec 11 14:49:27 2015 Nicolas Girardot
// Last update Sat Dec 12 03:18:06 2015 Serge Heitzler
//

#include <PlayerIG.hh>

PlayerIG::PlayerIG()
{
  _nbrLife = 3;

  Sprite	*heart1 = new Sprite();
  Sprite	*heart2 = new Sprite();
  Sprite	*heart3 = new Sprite();

  _score = new Text();
  _waveNumber = new Text();
  _spaceShip = new Sprite();
  
  _hearts.push_back(heart1);
  _hearts.push_back(heart2);
  _hearts.push_back(heart3);
}

PlayerIG::~PlayerIG()
{

}

void	PlayerIG::setLife(unsigned int i)
{
  _nbrLife = i;
}

const std::string &PlayerIG::getUsername()
{
  return _username;
}

void	PlayerIG::setUsername(const std::string &username)
{
  _username = username;
}
