//
// OtherPlayer.cpp for RTYPE in /home/nicolas/rendu/rtype_cpp/client/common
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri Dec 11 14:49:27 2015 Nicolas Girardot
// Last update Mon Dec 14 07:03:19 2015 Serge Heitzler
//

#include <OtherPlayer.hh>

OtherPlayer::OtherPlayer(unsigned int pos, unsigned int id)
{
  RenderWindow *window = RenderWindow::getInstance();

  _username = "player" + std::to_string(id);
  _nbrLife = 3;

  Sprite	*heart1 = new Sprite();
  Sprite	*heart2 = new Sprite();
  Sprite	*heart3 = new Sprite();

  unsigned int	padding = window->getSize()._x * 0.435;

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
  _greyBack->setTexture(*((RenderWindow::getInstance())->_ressources->_greyPanel));

  heart1->setOrigin((RenderWindow::getInstance())->_ressources->_heart->getSize()._x / 2, (RenderWindow::getInstance())->_ressources->_heart->getSize()._y / 2);
  heart2->setOrigin((RenderWindow::getInstance())->_ressources->_heart->getSize()._x / 2, (RenderWindow::getInstance())->_ressources->_heart->getSize()._y / 2);
  heart3->setOrigin((RenderWindow::getInstance())->_ressources->_heart->getSize()._x / 2, (RenderWindow::getInstance())->_ressources->_heart->getSize()._y / 2);
  _greyBack->setOrigin((RenderWindow::getInstance())->_ressources->_greyPanel->getSize()._x / 2, (RenderWindow::getInstance())->_ressources->_greyPanel->getSize()._y / 2);

  _spaceShip->setOrigin((RenderWindow::getInstance())->_ressources->_blackShip->getSize()._x, (RenderWindow::getInstance())->_ressources->_blackShip->getSize()._y);

  _spaceShip->scale(0.15);

  unsigned int margin = window->getSize()._x * 0.01;
  unsigned int sizeBack = (RenderWindow::getInstance())->_ressources->_greyPanel->getSize()._x;


  _greyBack->setPosition(padding + margin * (pos - 1) + (sizeBack) * (pos - 1), window->getSize()._y * 0.925);


  _spaceShip->setPosition(padding + margin * (pos - 1) + (sizeBack) * (pos - 1), window->getSize()._y * 0.95);

   heart1->setPosition(padding + margin * (pos - 1) + (sizeBack) * (pos - 1) + 20, window->getSize()._y * 0.9);
   heart2->setPosition(padding + margin * (pos - 1) + (sizeBack) * (pos - 1) + 60, window->getSize()._y * 0.9);
   heart3->setPosition(padding + margin * (pos - 1) + (sizeBack) * (pos - 1) + 100, window->getSize()._y * 0.9);


  _hearts.push_back(heart1);
  _hearts.push_back(heart2);
  _hearts.push_back(heart3);



  _score->setString("0");
  _score->setSize(30);
  _score->setStyle(1);
  _score->setOrigin(_score->getText().getGlobalBounds().width / 2, _score->getText().getGlobalBounds().height / 2);
  _score->setPosition(Vector2(padding + margin * (pos - 1) + (sizeBack) * (pos - 1) + 60, window->getSize()._y * 0.94));
  _score->setColor(Color::WHITE);


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

void	OtherPlayer::setScore(int a)
{
  _score->setString(std::to_string(a));
}

void		OtherPlayer::render()
{
    unsigned int		i = 0;

  (RenderWindow::getInstance())->draw(_greyBack->getSprite());
  (RenderWindow::getInstance())->draw(_spaceShip->getSprite());
  while (i < this->_hearts.size() && this->_hearts.size() > 0)
    {
      (RenderWindow::getInstance())->draw(this->_hearts.at(i)->getSprite());
      i++;
    }
  (RenderWindow::getInstance())->draw(_score->getText());
}
