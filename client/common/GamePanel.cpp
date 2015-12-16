//
// GamePanel.cpp for RTypoe in /home/nicolas/rendu/rtype_cpp/client/common
//
// Made @OCby Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri Dec 11 14:06:17 2015 Nicolas Girardot
// Last update Wed Dec 16 18:40:02 2015 Nicolas Girardot
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
#include <ButtonFactory.hh>

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
  _escapeKey = false;

  _type = PanelFactory::GAME_PANEL;
  _randPosY = new Random(250, 600);
  _randPlanet = new Random(0, 7);
  _randBackground = new Random(0, 2);

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
  Sprite *backgroundSpace2 = new Sprite;

  switch (_randBackground->generate<int>())
    {
    case 0:
      backgroundSpace1->setTexture(*((RenderWindow::getInstance())->_ressources->_backgroundGame1));
      backgroundSpace2->setTexture(*((RenderWindow::getInstance())->_ressources->_backgroundGame1));
      break;
    case 1:
      backgroundSpace1->setTexture(*((RenderWindow::getInstance())->_ressources->_backgroundGame2));
      backgroundSpace2->setTexture(*((RenderWindow::getInstance())->_ressources->_backgroundGame2));
      break;
    case 2:
      backgroundSpace1->setTexture(*((RenderWindow::getInstance())->_ressources->_backgroundGame3));
      backgroundSpace2->setTexture(*((RenderWindow::getInstance())->_ressources->_backgroundGame3));
      break;
    }
  backgroundSpace1->setPosition(0, 0);
  backgroundSpace2->setPosition(backgroundSpace2->getGlobalBounds().second.first, 0);

  _backgrounds.push_back(*backgroundSpace1);
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


  Sprite *black = new Sprite;

  black->setTexture(*((RenderWindow::getInstance())->_ressources->_backgroundBlack));
  black->setPosition(0, 0);
  black->getSprite().setColor(sf::Color(255, 255, 255, 0));
  _inGame.push_back(*black);


//   Sprite *planet = new Sprite;

// planet->setTexture(*((RenderWindow::getInstance())->_ressources->_planet->getTexture()));
//   planet->setPosition(0, 0);
//   _backgrounds.push_back(*planet);

  this->setPlayers(static_cast<RoomPanel*>(window->getPanels().top())->getNbPlayers(), static_cast<RoomPanel*>(window->getPanels().top())->getCurrentPlayer());


  Text	*sentence = new Text();

  sentence->setString("Are you sure to exit the game ?");
  sentence->setSize(80);
  sentence->setStyle(1);
  sentence->setOrigin(sentence->getText().getGlobalBounds().width / 2, sentence->getText().getGlobalBounds().height / 2);
  sentence->setPosition(Vector2(window->getSize()._x * 0.5, window->getSize()._y * 0.5));
  sentence->getText().setColor(sf::Color(255, 255, 255, 0));
  _labels.push_back(*sentence);
}

GamePanel::~GamePanel() {}

int			GamePanel::getType()
{
  return _type;
}

void		GamePanel::setPlayers(int nbPlayer, int currentPlayer)
{
  RenderWindow *window = RenderWindow::getInstance();

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

  _dicoTextures.insert(std::make_pair("5", ((RenderWindow::getInstance())->_ressources->_riffle)));
  _dicoTextures.insert(std::make_pair("6", ((RenderWindow::getInstance())->_ressources->_rocket)));
  _dicoTextures.insert(std::make_pair("7", ((RenderWindow::getInstance())->_ressources->_laserBlueBig)));
  _dicoTextures.insert(std::make_pair("8", ((RenderWindow::getInstance())->_ressources->_laserRedBig)));
  _dicoTextures.insert(std::make_pair("9", ((RenderWindow::getInstance())->_ressources->_laserGreenBig)));
  _dicoTextures.insert(std::make_pair("10", ((RenderWindow::getInstance())->_ressources->_laserYellowBig)));

  for (std::map<std::string, Texture*>::iterator it = static_cast<RoomPanel*>(window->getPanels().top())->getReceived()->begin(); it != static_cast<RoomPanel*>(window->getPanels().top())->getReceived()->end(); ++it)
    {
      std::cout << "filename : " << (*it).first << std::endl;
      _dicoTextures.insert(std::make_pair((*it).first, (*it).second));
    }
}


void		GamePanel::newEntity(std::vector<std::string> &vector)
{
  RenderWindow *window = RenderWindow::getInstance();
  Sprite	*newSprite = new Sprite();

  std::string  	type = vector.at(0);
  int	  	id = std::atoi(vector.at(1).c_str());

  if (type.find(":") == !std::string::npos)
    std::cout << "LASERRRR" << std::endl;


  std::cout << "Creating new Entity with ID = " << id << "; Type  = " << type << std::endl;
  newSprite->setTexture(*((static_cast<GamePanel*>(window->getPanels().top())->getDicoTextures())[type]));


  std::cout << "NTM" << std::endl;

  //  newSprite->scale();
  //  newSprite->setPosition(-500, 500);
  newSprite->setPosition(500, 500);

  ((static_cast<GamePanel*>(window->getPanels().top())->getDicoSprites())).insert(std::make_pair(id, newSprite));

  std::cout << "NVM" << std::endl;
}

void		GamePanel::deleteEntity(std::vector<std::string> &vector)
{
  RenderWindow *window = RenderWindow::getInstance();
  int	id = std::atoi(vector.at(0).c_str());

  std::map<int, Sprite*>::iterator it = ((static_cast<GamePanel*>(window->getPanels().top())->getDicoSprites())).find(id);
  if (it != ((static_cast<GamePanel*>(window->getPanels().top())->getDicoSprites())).end())
    {
      ((static_cast<GamePanel*>(window->getPanels().top())->getDicoSprites())).erase(it);
    }
}

void		GamePanel::die(int id, int idDied)
{
  RenderWindow *window = RenderWindow::getInstance();
  Explosion *e = new Explosion();
  switch (id) {
  case 1:
    e->setTexture(*(RenderWindow::getInstance()->_ressources->_explosion_blue));
    break;
  case 2:
    e->setTexture(*(RenderWindow::getInstance()->_ressources->_explosion_red));
    break;
  case 3:
    e->setTexture(*(RenderWindow::getInstance()->_ressources->_explosion_green));
    break;
  case 4:
    e->setTexture(*(RenderWindow::getInstance()->_ressources->_explosion_yellow));
    break;
  }

  int PosX  = static_cast<GamePanel*>(window->getPanels().top())->getDicoSprites()[idDied]->getPosX();
  int PosY  = static_cast<GamePanel*>(window->getPanels().top())->getDicoSprites()[idDied]->getPosY();
  e->setPosition(PosX, PosY);
  static_cast<GamePanel*>(window->getPanels().top())->getExplosions().push_back(e);

}

std::vector<Explosion *>	&GamePanel::getExplosions()
{
  return _explosion;
}

void		GamePanel::addExplosion()
{
  Explosion *t = new Explosion();
  t->setTexture(*(RenderWindow::getInstance()->_ressources->_explosion_green));
  _explosion.push_back(t);
}

void		GamePanel::display(std::vector<std::string> &vector)
{
  RenderWindow *window = RenderWindow::getInstance();
  int  	id;

  float	posX = (std::atoi(vector.at(1).c_str()));
  float	posY = (std::atoi(vector.at(2).c_str()));

  float realPosX = (posX * 16) + 70;
  float realPosY = (posY * 16) + 50;

  id = std::atoi(vector.at(0).c_str());

  std::map<int, Sprite*>::iterator it = ((static_cast<GamePanel*>(window->getPanels().top())->getDicoSprites())).find(id);
  if (it != ((static_cast<GamePanel*>(window->getPanels().top())->getDicoSprites())).end())
    {
      ((static_cast<GamePanel*>(window->getPanels().top())->getDicoSprites())[id])->setPosition(realPosX, realPosY);
    }
  //  std::cout << "Displaying with id = " << id << std::endl;
}

std::map<int, Sprite*>		&GamePanel::getDicoSprites()
{
  return _dicoSprites;
}

std::map<std::string, Texture*>		&GamePanel::getDicoTextures()
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

void		GamePanel::setEscapeMenu(bool value)
{
  RenderWindow *window = RenderWindow::getInstance();

  _escapeKey = value;
  std::string name = "RESUME";
  ButtonFactory::create(Vector2(window->getSize()._x * 0.25, window->getSize()._y * 0.7), name);
  name = "EXIT";
  ButtonFactory::create(Vector2(window->getSize()._x * 0.75, window->getSize()._y * 0.7), name);
  static_cast<GamePanel*>(window->getPanels().top())->getFunctions().push_back((APanel::funcs)&GamePanel::resume);
  static_cast<GamePanel*>(window->getPanels().top())->getFunctions().push_back((APanel::funcs)&GamePanel::exit);
  static_cast<GamePanel*>(window->getPanels().top())->getInGame().at(0).getSprite().setColor(sf::Color(255, 255, 255, 255));
  static_cast<GamePanel*>(window->getPanels().top())->getLabels().at(2).getText().setColor(sf::Color(255, 255, 255, 255));
  window->setMouseCursorVisible(true);
}


bool		GamePanel::getEscapeMenu()
{
  return _escapeKey;
}

void		GamePanel::resume()
{
  RenderWindow *window = RenderWindow::getInstance();

  _labels.erase(_labels.begin() + 3);
  _labels.erase(_labels.begin() + 3);

  _userInterface.erase(_userInterface.begin());
  _userInterface.erase(_userInterface.begin());

  _inGame.at(0).getSprite().setColor(sf::Color(255, 255, 255, 0));

  _labels.at(2).getText().setColor(sf::Color(255, 255, 255, 0));

  _escapeKey = false;

  window->setMouseCursorVisible(false);
}


void		GamePanel::exit()
{
  // close UDP read && exit thread
  Client::getUDPNetwork()->close();
  std::cout << "EXIT" << std::endl;
  RenderWindow::getInstance()->back();
  RenderWindow::getInstance()->back();
}

void		GamePanel::render()
{
  Sound *s = Client::getSound();
  if (s->isPlaying("gameIntro") || s->isPlaying("gameLoop"));
  else
    s->playMusic("gameLoop", 1);
  this->drawBackgrounds();
  this->_mainPlayer->render();
  this->drawOtherPlayer();

  _inputManager.joystickMovedInDirection();
  _inputManager.keyPressedInGame();
  RenderWindow *window = RenderWindow::getInstance();
  for (std::map<int, Sprite*>::iterator it = _dicoSprites.begin(); it != _dicoSprites.end(); ++it)
    {
      window->draw((*it).second->getSprite());
    }
  for (std::vector<Explosion *>::iterator it = _explosion.begin(); it != _explosion.end(); )
    {
      window->draw((*it)->getSprite());
      (*it)->update();
      if ((*it)->getState() == true)
	it = _explosion.erase(it);
      else
	it++;
    }
  this->drawInGame();
  this->drawUserInterface();
  this->drawLabels();
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
