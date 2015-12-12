//
// OtherPlayer.cpp for RTYPE in /home/nicolas/rendu/rtype_cpp/client/common
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri Dec 11 14:49:27 2015 Nicolas Girardot
// Last update Sat Dec 12 10:40:04 2015 Serge Heitzler
//

#include <OtherPlayer.hh>

OtherPlayer::OtherPlayer()
{
  _nbrLife = 3;

  Sprite	*heart1 = new Sprite();
  Sprite	*heart2 = new Sprite();
  Sprite	*heart3 = new Sprite();

  _score = new Text();
  _spaceShip = new Sprite();
  
  _hearts.push_back(heart1);
  _hearts.push_back(heart2);
  _hearts.push_back(heart3);
}

OtherPlayer::~OtherPlayer()
{

}

void	OtherPlayer::setLife(unsigned int i)
{
  _nbrLife = i;
}

const std::string &OtherPlayer::getUsername()
{
  return _username;
}

void	OtherPlayer::setUsername(const std::string &username)
{
  _username = username;
}

void		OtherPlayer::render()
{
    unsigned int		i = 0;

  (RenderWindow::getInstance())->draw(_spaceShip->getSprite());
  while (i < this->_hearts.size() && this->_hearts.size() > 0)
    {
      (RenderWindow::getInstance())->draw(this->_hearts.at(i)->getSprite());
      i++;
    }
  (RenderWindow::getInstance())->draw(_score->getText());
}
