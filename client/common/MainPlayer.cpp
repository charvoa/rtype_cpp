//
// MainPlayer.cpp for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Sat Dec 12 06:40:19 2015 Serge Heitzler
// Last update Sat Dec 12 10:48:47 2015 Serge Heitzler
//

#include <RenderWindow.hh>
#include <MainPlayer.hh>

MainPlayer::MainPlayer(int id)
{
  RenderWindow *window = RenderWindow::getInstance();

  _spaceShip = new Sprite();
  _nbrLife = 3;
  _nbrRocket = 0;
  _score = new Text();
  _nbrRocketText = new Text();

  Sprite	*riffle = new Sprite();
  Sprite	*rocket = new Sprite();
  Sprite	*laser = new Sprite();

  Sprite	*heart1 = new Sprite();
  Sprite	*heart2 = new Sprite();
  Sprite	*heart3 = new Sprite();

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


      riffle->setTexture(*((RenderWindow::getInstance())->_ressources->_riffle));
      rocket->setTexture(*((RenderWindow::getInstance())->_ressources->_rocket));
      laser->setTexture(*((RenderWindow::getInstance())->_ressources->_laser));
      heart1->setTexture(*((RenderWindow::getInstance())->_ressources->_heart));
      heart2->setTexture(*((RenderWindow::getInstance())->_ressources->_heart));
      heart3->setTexture(*((RenderWindow::getInstance())->_ressources->_heart));


  _spaceShip->setPosition(window->getSize()._x * 0.05, window->getSize()._y * 0.95);
  riffle->setPosition(window->getSize()._x * 0.15, window->getSize()._y * 0.92);
  rocket->setPosition(window->getSize()._x * 0.15, window->getSize()._y * 0.95);
  laser->setPosition(window->getSize()._x * 0.15, window->getSize()._y * 0.98);
  heart1->setPosition(window->getSize()._x * 0.1, window->getSize()._y * 0.95);
  heart2->setPosition(window->getSize()._x * 0.11, window->getSize()._y * 0.95);
  heart3->setPosition(window->getSize()._x * 0.12, window->getSize()._y * 0.95);

  _spaceShip->scale(0.5);
  riffle->scale(0.5);
  rocket->scale(0.5);
  laser->scale(0.5);
  heart1->scale(0.5);
  heart2->scale(0.5);
  heart3->scale(0.5);

  _hearts.push_back(heart1);
  _hearts.push_back(heart2);
  _hearts.push_back(heart3);

  _ammos.push_back(riffle);
  _ammos.push_back(rocket);
  _ammos.push_back(laser);  

  _score->setString("0");
  _score->setSize(30);
  _score->setStyle(1);
  _score->setOrigin(_score->getText().getGlobalBounds().width / 2, _score->getText().getGlobalBounds().height / 2);
  _score->setPosition(Vector2(window->getSize()._x * 0.1, window->getSize()._y * 0.9));
  _score->setColor(Color::WHITE);

}

MainPlayer::~MainPlayer(){}

void		MainPlayer::setNbRocket(unsigned int nb)
{
  _nbrRocket = nb;
  if (_nbrRocket <= 0)
    _ammos.at(1)->getSprite().setTexture(((RenderWindow::getInstance())->_ressources->_rocketBlack->getTexture()));
  _nbrRocketText->getText().setString(std::to_string(nb));
}

void		MainPlayer::setNbLife(unsigned int nb)
{
  unsigned int i = 0;
  _nbrLife = nb;
  while (i < _nbrLife)
    {
      _hearts.at(i)->getSprite().setColor(sf::Color(255, 255, 255, 255));
      i++;
    }
  while (i < 3)
    {
      _hearts.at(i)->getSprite().setColor(sf::Color(255, 255, 255, 0));
      i++;
    }
  if (_nbrLife <= 0)
    {
      _spaceShip->setTexture(*((RenderWindow::getInstance())->_ressources->_blackShip));
    }
}

void		MainPlayer::setScore(unsigned int score)
{
  _score->getText().setString(std::to_string(score));
}

void		MainPlayer::render()
{
    unsigned int		i = 0;

  (RenderWindow::getInstance())->draw(_spaceShip->getSprite());
  while (i < this->_hearts.size() && this->_hearts.size() > 0)
    {
      (RenderWindow::getInstance())->draw(this->_hearts.at(i)->getSprite());
      (RenderWindow::getInstance())->draw(this->_ammos.at(i)->getSprite());
      i++;
    }
  (RenderWindow::getInstance())->draw(_score->getText());
  (RenderWindow::getInstance())->draw(_nbrRocketText->getText());
}
