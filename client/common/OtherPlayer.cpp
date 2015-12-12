//
// OtherPlayer.cpp for RTYPE in /home/nicolas/rendu/rtype_cpp/client/common
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri Dec 11 14:49:27 2015 Nicolas Girardot
// Last update Sat Dec 12 13:47:43 2015 Serge Heitzler
//

#include <OtherPlayer.hh>

OtherPlayer::OtherPlayer(unsigned int pos, unsigned int id)
{
  (void)id;
  _nbrLife = 3;

  Sprite	*heart1 = new Sprite();
  Sprite	*heart2 = new Sprite();
  Sprite	*heart3 = new Sprite();

  Sprite	*greyBack = new Sprite();

  unsigned int	padding = window->getSize()._x * 0.4;

  _score = new Text();
  _spaceShip = new Sprite();
  _greyBack = new Sprite();
  

  switch (id)
    {
    case 0:
      _spaceShip->setTexture(*((RenderWindow::getInstance())->_ressources->_blackShip));
      break;
    case 1:
      _spaceShip->setTexture(*((RenderWindow::getInstance())->_ressources->_blueShip));
      break;
    case 2:
      _spaceShip->setTexture(*((RenderWindow::getInstance())->_ressources->_redShip));
      break;
    case 3:
      _spaceShip->setTexture(*((RenderWindow::getInstance())->_ressources->_greenShip));
      break;
    case 4:
      _spaceShip->setTexture(*((RenderWindow::getInstance())->_ressources->_yellowShip));
      break;
    default:
      _spaceShip->setTexture(*((RenderWindow::getInstance())->_ressources->_blackShip));
      break;
    }

  
  heart1->setTexture(*((RenderWindow::getInstance())->_ressources->_heart));
  heart2->setTexture(*((RenderWindow::getInstance())->_ressources->_heart));
  heart3->setTexture(*((RenderWindow::getInstance())->_ressources->_heart));

  
  _spaceShip->scale(0.15);

  _greyBack->setPosition(padding + window->getSize()._x * 0.03, window->getSize()._y * 0.8);
  _spaceShip->setPosition(padding + window->getSize()._x * 0.03, window->getSize()._y * 0.85);
  heart1->setPosition(padding + window->getSize()._x * 0.03, window->getSize()._y * 0.8);



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
  (RenderWindow::getInstance())->draw(_greyBack->getSprite());
  while (i < this->_hearts.size() && this->_hearts.size() > 0)
    {
      (RenderWindow::getInstance())->draw(this->_hearts.at(i)->getSprite());
      i++;
    }
  (RenderWindow::getInstance())->draw(_score->getText());
}
