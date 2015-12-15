//
// GamePanel.cpp for RTypoe in /home/nicolas/rendu/rtype_cpp/client/common
//
// Made @OCby Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri Dec 11 14:06:17 2015 Nicolas Girardot
// Last update Tue Dec 15 09:43:37 2015 Serge Heitzler
//

#ifdef _WIN32
#include "../NetworkWin.hpp"
#include <ThreadWin.hpp>
#else
#include "../Network.hpp"
#include <ThreadUnix.hpp>
#endif

#include <memory>
#include <iostream>
#include <GamePanel.hh>
#include <Client.hh>
#include <ProtocoleClient.hh>
#include <AThread.hpp>

void	*readUDP(void *s)
{
  ANetwork::t_frame a;
  ProtocoleClient x;

  while (true)
    {
      try
	{

	  a = Client::getUDPNetwork()->read();
	  // if (a == NULL)
	  // {
	  //   std::cout << "Connection Lost with server" << std::endl;
	  //   exit (0);
	  // }
	  //	  std::cout << "UDP data is " << a.data << std::endl;
	  x.methodChecker(a);
	}
      catch (const std::exception &e)
	{
	  std::cout << e.what() << std::endl;
	}
    }
  return s;
}

GamePanel::GamePanel()
{
  RenderWindow *window = RenderWindow::getInstance();
  getInputManager().setInputType(InputType::GAME_INPUT);

  _randPosY = new Random(250, 600);
  _randPlanet = new Random(0, 7);


  std::unique_ptr<AThread> t(new Thread(1));
  char str1[] = "";
  (void) str1;
  t->attach(&readUDP, (void *)str1);
  t->run();

  //  for (int i = 0; i != 3; i++)
  //    _players.push_back(new OtherPlayer());
  //init all sprites with the textures;

  window->setMouseCursorVisible(false);

  Sound *s = Client::getSound();
  s->stopMusic("mainMenu");
  s->playMusic("gameIntro", 0);

  Text	*teamScore = new Text();

  teamScore->setString("0");
  teamScore->setSize(40);
  teamScore->setStyle(1);
  teamScore->setOrigin(teamScore->getText().getGlobalBounds().width / 2, teamScore->getText().getGlobalBounds().height / 2);
  teamScore->setPosition(Vector2(window->getSize()._x / 2, window->getSize()._y * 0.025));
  teamScore->setColor(Color::WHITE);
  _labels.push_back(*teamScore);

  Text	*waveNumber = new Text();

  waveNumber->setString("0");
  waveNumber->setSize(60);
  waveNumber->setStyle(1);
  waveNumber->setOrigin(waveNumber->getText().getGlobalBounds().width / 2, waveNumber->getText().getGlobalBounds().height / 2);
  waveNumber->setPosition(Vector2(window->getSize()._x * 0.88, window->getSize()._y * 0.92));
  waveNumber->setColor(Color::WHITE);
  _labels.push_back(*waveNumber);

  Sprite *backgroundSpace1 = new Sprite;

  backgroundSpace1->setTexture(*((RenderWindow::getInstance())->_ressources->_backgroundGame2));
  backgroundSpace1->setPosition(0, 0);
  _backgrounds.push_back(*backgroundSpace1);

  Sprite *backgroundSpace2 = new Sprite;

  backgroundSpace2->setTexture(*((RenderWindow::getInstance())->_ressources->_backgroundGame2));
  backgroundSpace2->setPosition(backgroundSpace2->getGlobalBounds().second.first, 0);
  _backgrounds.push_back(*backgroundSpace2);


  Sprite *topGame1 = new Sprite;

  topGame1->setTexture(*((RenderWindow::getInstance())->_ressources->_topGame));
  topGame1->setPosition(0, 0);
  _backgrounds.push_back(*topGame1);


  Sprite *topGame2 = new Sprite;

  topGame2->setTexture(*((RenderWindow::getInstance())->_ressources->_topGame));
  topGame2->setPosition(topGame2->getGlobalBounds().second.first, 0);
  _backgrounds.push_back(*topGame2);


  Sprite *bottomGame1 = new Sprite;

bottomGame1->setTexture(*((RenderWindow::getInstance())->_ressources->_bottomGame));
 bottomGame1->setPosition(0, 860);
 _backgrounds.push_back(*bottomGame1);


  Sprite *bottomGame2 = new Sprite;

bottomGame2->setTexture(*((RenderWindow::getInstance())->_ressources->_bottomGame));
  bottomGame2->setPosition(bottomGame2->getGlobalBounds().second.first, 860);
  _backgrounds.push_back(*bottomGame2);


  Sprite *planet = new Sprite;

  planet->setTexture(*((RenderWindow::getInstance())->_ressources->_deathStar));
  planet->setPosition(2500, _randPosY->generate<int>());
  planet->scale(0.6);
  _backgrounds.push_back(*planet);


  Sprite *header = new Sprite;

  header->setTexture(*((RenderWindow::getInstance())->_ressources->_header));
  header->setPosition(window->getSize()._x / 2, 0);
  header->setOrigin((RenderWindow::getInstance())->_ressources->_header->getSize()._x / 2, 0);
  header->scale(1.5);
  _backgrounds.push_back(*header);

    Sprite *hud = new Sprite;

  hud->setTexture(*((RenderWindow::getInstance())->_ressources->_hud));
  hud->setPosition(0, 0);
  _backgrounds.push_back(*hud);



//   Sprite *planet = new Sprite;

// planet->setTexture(*((RenderWindow::getInstance())->_ressources->_planet->getTexture()));
//   planet->setPosition(0, 0);
//   _backgrounds.push_back(*planet);

  this->setPlayers(static_cast<RoomPanel*>(window->getPanels().top())->getNbPlayers(), static_cast<RoomPanel*>(window->getPanels().top())->getCurrentPlayer());

  //  static_cast<RoomPanel*>(window->getPanels().top())->getReceived();
}

GamePanel::~GamePanel() {}

void		GamePanel::setPlayers(int nbPlayer, int currentPlayer)
{

  int i = 1;
  while (i <= nbPlayer)
    {
      Sprite	*ship = new Sprite();
      switch (i)
	{
	case 1:
	  ship->setTexture(*((RenderWindow::getInstance())->_ressources->_blueShipGame));
	  break;
	case 2:
	  ship->setTexture(*((RenderWindow::getInstance())->_ressources->_redShipGame));
	  break;
	case 3:
	  ship->setTexture(*((RenderWindow::getInstance())->_ressources->_greenShipGame));
	  break;
	case 4:
	  ship->setTexture(*((RenderWindow::getInstance())->_ressources->_yellowShipGame));
	  break;
	default:
	  ship->setTexture(*((RenderWindow::getInstance())->_ressources->_blackShip));
	  break;
	}
      ship->scale(0.2);
      ship->setPosition(-500, 500);
      ship->setOrigin((RenderWindow::getInstance())->_ressources->_blackShip->getSize()._x / 2, (RenderWindow::getInstance())->_ressources->_blackShip->getSize()._y / 2);
      _dicoSprites.insert(std::make_pair(i, ship));
      i++;
    }

  /* USER INTERFACE HUD */

  _mainPlayer = new MainPlayer(currentPlayer);
  i = 1;
  int j = 1;
  while (i <= nbPlayer)
    {
      if (i == currentPlayer)
	;
      else
	{
	  OtherPlayer	*other = new OtherPlayer(j, i);
	  _otherPlayers.push_back(other);
	  j++;
	}
      i++;
    }

  _dicoTextures.insert(std::make_pair(5, ((RenderWindow::getInstance())->_ressources->_riffle)));
  _dicoTextures.insert(std::make_pair(6, ((RenderWindow::getInstance())->_ressources->_rocket)));
  _dicoTextures.insert(std::make_pair(7, ((RenderWindow::getInstance())->_ressources->_laserBlueBig)));
  _dicoTextures.insert(std::make_pair(8, ((RenderWindow::getInstance())->_ressources->_laserRedBig)));
  _dicoTextures.insert(std::make_pair(9, ((RenderWindow::getInstance())->_ressources->_laserGreenBig)));
  _dicoTextures.insert(std::make_pair(10, ((RenderWindow::getInstance())->_ressources->_laserYellowBig)));
  //  _dicoTextures.insert(std::make_pair(11, ((RenderWindow::getInstance())->_ressources->_riffle)));
  //  _dicoTextures.insert(std::make_pair(12, ((RenderWindow::getInstance())->_ressources->_riffle)));
  
}


void		GamePanel::newEntity(std::vector<std::string> &vector)
{
  RenderWindow *window = RenderWindow::getInstance();
  Sprite	*newSprite = new Sprite();

  std::string  	typeString = vector.at(0);
  int	  	id = std::atoi(vector.at(1).c_str());
  int		type;

  if (typeString.find(":") == !std::string::npos)
    type = 7;
  else
    type = std::atoi(vector.at(0).c_str());

  
  newSprite->setTexture(*((static_cast<GamePanel*>(window->getPanels().top())->getDicoTextures())[type]));
  //  newSprite->scale();
  newSprite->setPosition(-500, 500);
  
  ((static_cast<GamePanel*>(window->getPanels().top())->getDicoSprites())).insert(std::make_pair(id, newSprite));

}

void		GamePanel::deleteEntity(std::vector<std::string> &vector)
{
  int	id = std::atoi(vector.at(0).c_str());
  std::map<int, Sprite*>::iterator it;
  it = ((static_cast<GamePanel*>(window->getPanels().top())->getDicoSprites())).erase(id);
}

void		GamePanel::die()
{

}

void		GamePanel::display(std::vector<std::string> &vector)
{
  RenderWindow *window = RenderWindow::getInstance();
  int  	id;



  float	posX = (std::atoi(vector.at(1).c_str()));
  float	posY = (std::atoi(vector.at(2).c_str()));

  float realPosX = (posX * 16);
  float realPosY = (posY * 16);


  //   int	scale = std::atoi(vector.at(3).c_str());


  id = std::atoi(vector.at(0).c_str());


  // std::cout << "vector.size() " << vector.size() << std::endl;
  // std::cout << "pos X " << posX << std::endl;
  // std::cout << "realPos X " << realPosX << std::endl;
  // std::cout << "pos Y " << posY << std::endl;
  // std::cout << "realPos Y " << realPosY << std::endl;

  // static int i = 0;

  // if (i == 0)
  //   {
  //     ((static_cast<GamePanel*>(window->getPanels().top())->getDicoSprites())[id])->setPosition(realPosX, realPosY);
  //   }

  // i++;




  // float moveX = ((static_cast<GamePanel*>(window->getPanels().top())->getDicoSprites())[id])->getPosX() - realPosX;

  // float moveY = ((static_cast<GamePanel*>(window->getPanels().top())->getDicoSprites())[id])->getPosY() - realPosY;

   ((static_cast<GamePanel*>(window->getPanels().top())->getDicoSprites())[id])->setPosition(realPosX, realPosY);


   
  // ((static_cast<GamePanel*>(window->getPanels().top())->getDicoSprites())[id])->move(moveX, moveY);

  // std::cout << "realPos X " << moveX << std::endl;
  // std::cout << "realPos Y " << moveY << std::endl;

  // std::cout << "COUSCOUS" << std::endl;

}

std::map<int, Sprite*>		&GamePanel::getDicoSprites()
{
  return _dicoSprites;
}

std::map<int, Texture*>		&GamePanel::getDicoTextures()
{
  return _dicoTextures;
}

std::vector<Sprite *> &GamePanel::getSprites()
{
  return _sprites;
}

Text		&GamePanel::getTeamScore()
{
  return _labels.at(0);
}

Text		&GamePanel::getCurrentWave()
{
  return _labels.at(1);
}

void		GamePanel::setCurrentWave(unsigned int value)
{
  RenderWindow *window = RenderWindow::getInstance();

  static_cast<GamePanel*>(window->getPanels().top())->getCurrentWave().setString(std::to_string(value));
}

void		GamePanel::setTeamScore(unsigned int value)
{
  RenderWindow *window = RenderWindow::getInstance();

  static_cast<GamePanel*>(window->getPanels().top())->getTeamScore().setString(std::to_string(value));
}

OtherPlayer	*GamePanel::getPlayerByName(const std::string &name)
{
  for (std::vector<OtherPlayer *>::iterator it = _otherPlayers.begin(); it != _otherPlayers.end(); it++)
    {
      if ((*it)->getUsername() == name)
	return (*it);
    }
  return NULL;
}

MainPlayer		*GamePanel::getMainPlayer()
{
  return _mainPlayer;
}

void		GamePanel::setScore(const std::string &name, int score)
{
  RenderWindow *window = RenderWindow::getInstance();

  if (static_cast<GamePanel*>(window->getPanels().top())->getMainPlayer()->getUsername() == name)
    {
      static_cast<GamePanel*>(window->getPanels().top())->getMainPlayer()->setScore(score);
    }
  else
    {
      OtherPlayer *player;
      player = static_cast<GamePanel*>(window->getPanels().top())->getPlayerByName(name);
      if (player == NULL)
	{
	  std::cout << "Player does not exist" << std::endl;
	  return ;
	}
      player->setScore(score);
    }
}

void		GamePanel::setLife(const std::string &name, int life)
{
  RenderWindow *window = RenderWindow::getInstance();

  std::cout << "Player Name is " << static_cast<GamePanel*>(window->getPanels().top())->getMainPlayer()->getUsername() << std::endl;
  if (static_cast<GamePanel*>(window->getPanels().top())->getMainPlayer()->getUsername() == name)
    {
      static_cast<GamePanel*>(window->getPanels().top())->getMainPlayer()->setNbLife(life);
    }
  else
    {
      OtherPlayer *player;
      player = static_cast<GamePanel*>(window->getPanels().top())->getPlayerByName(name);
      if (player == NULL)
	{
	  std::cout << "Player does not exist" << std::endl;
	  return ;
	}
      player->setLife(life);
    }
}



void		GamePanel::render()
{
  Sound *s = Client::getSound();
  if (s->isPlaying("gameIntro") || s->isPlaying("gameLoop"));
  else
    s->playMusic("gameLoop", 1);
  this->drawBackgrounds();
  this->drawUserInterface();
  this->drawLabels();
  this->drawInGame();
  this->_mainPlayer->render();
  this->drawOtherPlayer();

  _inputManager.joystickMovedInDirection();
  
  RenderWindow *window = RenderWindow::getInstance();
  for (std::map<int, Sprite*>::iterator it = _dicoSprites.begin(); it != _dicoSprites.end(); ++it)
    {
      window->draw((*it).second->getSprite());
    }
  _inputManager.keyPressedInGame();
}

void		GamePanel::drawOtherPlayer()
{
unsigned int		i = 0;

  i = 0;
  while (i < this->_otherPlayers.size() && this->_otherPlayers.size() > 0)
    {
this->_otherPlayers.at(i)->render();
      i++;
    }
}

void					GamePanel::setPlanetTexture(int i)
{
  switch (i)
    {
    case 0:
      _backgrounds.at(6).setTexture(*((RenderWindow::getInstance())->_ressources->_planetEarth));
      break;
    case 1:
      _backgrounds.at(6).setTexture(*((RenderWindow::getInstance())->_ressources->_planetExodus));
      break;
    case 2:
      _backgrounds.at(6).setTexture(*((RenderWindow::getInstance())->_ressources->_planetJupiter));
      break;
    case 3:
      _backgrounds.at(6).setTexture(*((RenderWindow::getInstance())->_ressources->_planetMars));
      break;
    case 4:
      _backgrounds.at(6).setTexture(*((RenderWindow::getInstance())->_ressources->_planetMoon));
      break;
    case 5:
      _backgrounds.at(6).setTexture(*((RenderWindow::getInstance())->_ressources->_planetNeptune));
      break;
    case 6:
      _backgrounds.at(6).setTexture(*((RenderWindow::getInstance())->_ressources->_planetSaturne));
      break;
    case 7:
      _backgrounds.at(6).setTexture(*((RenderWindow::getInstance())->_ressources->_deathStar));
      break;
    default:
      _backgrounds.at(6).setTexture(*((RenderWindow::getInstance())->_ressources->_deathStar));
      break;
    }
}


void		GamePanel::update()
{
  static unsigned int i = 0;

  if (i > 492)
    {
      _backgrounds.at(0).move(-1, 0);
      _backgrounds.at(1).move(-1, 0);
      _backgrounds.at(2).move(-5, 0);
      _backgrounds.at(3).move(-5, 0);
      _backgrounds.at(4).move(-5, 0);
      _backgrounds.at(5).move(-5, 0);

      _backgrounds.at(6).move(-2, 0);
    }

  
  if (_backgrounds.at(0).getGlobalBounds().first.first == -(_backgrounds.at(0).getGlobalBounds().second.first))
    {
      _backgrounds.at(0).setPosition(_backgrounds.at(0).getGlobalBounds().second.first, 0);
    }
  if (_backgrounds.at(1).getGlobalBounds().first.first == -(_backgrounds.at(1).getGlobalBounds().second.first))
    {
      _backgrounds.at(1).setPosition(_backgrounds.at(1).getGlobalBounds().second.first, 0);
    }

  
  
  if (_backgrounds.at(2).getGlobalBounds().first.first <= -(_backgrounds.at(2).getGlobalBounds().second.first))
    {
      _backgrounds.at(2).setPosition(_backgrounds.at(2).getGlobalBounds().second.first, 0);
    }
  if (_backgrounds.at(3).getGlobalBounds().first.first <= -(_backgrounds.at(3).getGlobalBounds().second.first))
    {
      _backgrounds.at(3).setPosition(_backgrounds.at(3).getGlobalBounds().second.first, 0);
    }

  if (_backgrounds.at(4).getGlobalBounds().first.first == -(_backgrounds.at(4).getGlobalBounds().second.first))
    {
      _backgrounds.at(4).setPosition(_backgrounds.at(4).getGlobalBounds().second.first, 860);
    }
  if (_backgrounds.at(5).getGlobalBounds().first.first == -(_backgrounds.at(5).getGlobalBounds().second.first))
    {
      _backgrounds.at(5).setPosition(_backgrounds.at(5).getGlobalBounds().second.first, 860);
    }


  
  if (_backgrounds.at(6).getGlobalBounds().first.first == -500)
    {
      _backgrounds.at(6).setPosition(_backgrounds.at(1).getGlobalBounds().second.first, _randPosY->generate<int>());

      //      this->setPlanetTexture(_randPlanet->generate<int>());
    }
  i++;
}
