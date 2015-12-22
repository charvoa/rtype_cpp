//
// MainPlayer.cpp for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Sat Dec 12 06:40:19 2015 Serge Heitzler
// Last update Tue Dec 22 06:35:47 2015 Serge Heitzler
//

#include <RenderWindow.hh>
#include <MainPlayer.hh>
#include <GamePanel.hh>

MainPlayer::MainPlayer(unsigned int id)
{
  RenderWindow *window = RenderWindow::getInstance();

  _username = "player" + std::to_string(id);
  _spaceShip = new Sprite();
  _nbrLife = 3;
  _nbrRocket = 0;
  _score = new Text();
  _nbrRocketText = new Text();
  _id = id;
  
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
      laser->setTexture(*((RenderWindow::getInstance())->_ressources->_laserBlackLittle));
      break;
    case 1:
      _spaceShip->setTexture(*((RenderWindow::getInstance())->_ressources->_blueShip));
      laser->setTexture(*((RenderWindow::getInstance())->_ressources->_laserBlueLittle));
      break;
    case 2:
      _spaceShip->setTexture(*((RenderWindow::getInstance())->_ressources->_redShip));
      laser->setTexture(*((RenderWindow::getInstance())->_ressources->_laserRedLittle));
      break;
    case 3:
      _spaceShip->setTexture(*((RenderWindow::getInstance())->_ressources->_greenShip));
      laser->setTexture(*((RenderWindow::getInstance())->_ressources->_laserGreenLittle));
      break;
    case 4:
      _spaceShip->setTexture(*((RenderWindow::getInstance())->_ressources->_yellowShip));
      laser->setTexture(*((RenderWindow::getInstance())->_ressources->_laserYellowLittle));
      break;
    default:
      _spaceShip->setTexture(*((RenderWindow::getInstance())->_ressources->_blackShip));
      laser->setTexture(*((RenderWindow::getInstance())->_ressources->_laserBlackLittle));
      break;
    }

  riffle->setTexture(*((RenderWindow::getInstance())->_ressources->_riffleHUD));
  rocket->setTexture(*((RenderWindow::getInstance())->_ressources->_rocket));
  heart1->setTexture(*((RenderWindow::getInstance())->_ressources->_heart));
  heart2->setTexture(*((RenderWindow::getInstance())->_ressources->_heart));
  heart3->setTexture(*((RenderWindow::getInstance())->_ressources->_heart));


  _spaceShip->setPosition(window->getSize()._x * 0.03, window->getSize()._y * 0.89);
  riffle->setPosition(window->getSize()._x * 0.27, window->getSize()._y * 0.88);
  rocket->setPosition(window->getSize()._x * 0.27, window->getSize()._y * 0.92);
  laser->setPosition(window->getSize()._x * 0.27, window->getSize()._y * 0.95);
  heart1->setPosition(window->getSize()._x * 0.13, window->getSize()._y * 0.88);
  heart2->setPosition(window->getSize()._x * 0.16, window->getSize()._y * 0.88);
  heart3->setPosition(window->getSize()._x * 0.19, window->getSize()._y * 0.88);

  _spaceShip->scale(0.2);

  heart1->scale(1.5);
  heart2->scale(1.5);
  heart3->scale(1.5);

  _hearts.push_back(heart1);
  _hearts.push_back(heart2);
  _hearts.push_back(heart3);

  _ammos.push_back(riffle);
  _ammos.push_back(rocket);
  _ammos.push_back(laser);

  _score->setString("0");
  _score->setSize(50);
  _score->setStyle(1);
  _score->setOrigin(_score->getText().getGlobalBounds().width / 2, _score->getText().getGlobalBounds().height / 2);
  _score->setPosition(Vector2(window->getSize()._x * 0.17, window->getSize()._y * 0.95));
  _score->setColor(Color::WHITE);

  _nbrRocketText->setString("0");
  _nbrRocketText->setSize(30);
  _nbrRocketText->setStyle(1);
  _nbrRocketText->setOrigin(_nbrRocketText->getText().getGlobalBounds().width / 2, _nbrRocketText->getText().getGlobalBounds().height / 2);
  _nbrRocketText->setPosition(Vector2(window->getSize()._x * 0.31, window->getSize()._y * 0.92));
  _nbrRocketText->setColor(Color::WHITE);

}

MainPlayer::~MainPlayer(){}

const std::string	&MainPlayer::getUsername() const
{
  return _username;
}

void		        MainPlayer::ammoLeft(std::vector<std::string> &v)
{
  unsigned int value = std::atoi(v.at(1).c_str());

  if (v.at(0) == "E_MISSILE")
    this->setNbRocket(value);
  else
    this->setNbLaser(value);
}

void		MainPlayer::setNbRocket(unsigned int nb)
{
  _nbrRocket = nb;
  if (_nbrRocket <= 0)
    _ammos.at(1)->getSprite().setTexture(((RenderWindow::getInstance())->_ressources->_rocketBlack->getTexture()));
  else
    _ammos.at(1)->getSprite().setTexture(((RenderWindow::getInstance())->_ressources->_rocket->getTexture()));
  
  _nbrRocketText->getText().setString(std::to_string(nb));  
  _nbrRocketText->setOrigin(_nbrRocketText->getText().getGlobalBounds().width / 2, _nbrRocketText->getText().getGlobalBounds().height / 2);
}

void		MainPlayer::setNbLaser(unsigned int nb)
{
  if (nb > 0)
    {
      switch (_id)
	{
	case 0:
	  _ammos.at(2)->getSprite().setTexture(((RenderWindow::getInstance())->_ressources->_laserBlackLittle->getTexture()));
	  break;
	case 1:
	  _ammos.at(2)->getSprite().setTexture(((RenderWindow::getInstance())->_ressources->_laserBlueLittle->getTexture()));
	  break;
	case 2:
	  _ammos.at(2)->getSprite().setTexture(((RenderWindow::getInstance())->_ressources->_laserRedLittle->getTexture()));
	  break;
	case 3:
	  _ammos.at(2)->getSprite().setTexture(((RenderWindow::getInstance())->_ressources->_laserGreenLittle->getTexture()));
	  break;
	case 4:
	  _ammos.at(2)->getSprite().setTexture(((RenderWindow::getInstance())->_ressources->_laserYellowLittle->getTexture()));
	  break;
	default:
	  _ammos.at(2)->getSprite().setTexture(((RenderWindow::getInstance())->_ressources->_laserBlackLittle->getTexture()));
	  break;
	}
    }
  else
    _ammos.at(2)->getSprite().setTexture(((RenderWindow::getInstance())->_ressources->_laserBlackLittle->getTexture()));
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
  _score->setOrigin(_score->getText().getGlobalBounds().width / 2, _score->getText().getGlobalBounds().height / 2);
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
