//
// GamePanel.cpp for RTypoe in /home/nicolas/rendu/rtype_cpp/client/common
//
// Made @OCby Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri Dec 11 14:06:17 2015 Nicolas Girardot
// Updated on  Fri Dec 11 14:06:17 2015 Nicolas Girardot
//

#include <memory>
#include <iostream>
#include <GamePanel.hh>
#include <Client.hh>
#include <ProtocoleClient.hh>
#include <AThread.hpp>
#include <ButtonFactory.hh>
#include <Asteroid.hh>
#include <CRC.hpp>

void	*readUDP(void *s)
{
  void	*data;
  ProtocoleClient x;

  while (true)
    {
      if (!(data = Client::getUDPNetwork()->read(sizeof(ANetwork::t_frame))))
	{}
      else
	x.methodChecker(*reinterpret_cast<ANetwork::t_frame*>(data));
    }
  return s;
}

GamePanel::GamePanel()
{
  RenderWindow *window = RenderWindow::getInstance();
  getInputManager().setInputType(InputType::GAME_INPUT);
  _escapeKey = false;

  _type = PanelFactory::GAME_PANEL;
  _randPosY = new Random(350, 500);
  _randPlanet = new Random(0, 7);
  _randBackground = new Random(0, 2);

  std::unique_ptr<AThread> t(new Thread(1));

  _t = std::move(t);
  char str1[] = "";
  (void) str1;
  _t->attach(&readUDP, (void *)str1);
  _t->run();

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

  waveNumber->setString("1");
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

  Sprite *planet = new Sprite;

  planet->setTexture(*((RenderWindow::getInstance())->_ressources->_deathStar));
  planet->setPosition(2500, _randPosY->generate<int>());
  planet->scale(0.5);
  _backgrounds.push_back(*planet);
  
  

  Sprite *topGame1 = new Sprite;

  topGame1->setTexture(*((RenderWindow::getInstance())->_ressources->_topGame));
  topGame1->setPosition(0, 0);
  _inGame.push_back(*topGame1);


  Sprite *topGame2 = new Sprite;

  topGame2->setTexture(*((RenderWindow::getInstance())->_ressources->_topGame));
  topGame2->setPosition(topGame2->getGlobalBounds().second.first, 0);
  _inGame.push_back(*topGame2);

  Sprite *header = new Sprite;

  header->setTexture(*((RenderWindow::getInstance())->_ressources->_header));
  header->setPosition(window->getSize()._x / 2, 0);
  header->setOrigin((RenderWindow::getInstance())->_ressources->_header->getSize()._x / 2, 0);
  header->scale(1.5);
  _inGame.push_back(*header);

  Sprite *bottomGame1 = new Sprite;

bottomGame1->setTexture(*((RenderWindow::getInstance())->_ressources->_bottomGame));
 bottomGame1->setPosition(0, 860);
 _inGame.push_back(*bottomGame1);


  Sprite *bottomGame2 = new Sprite;

bottomGame2->setTexture(*((RenderWindow::getInstance())->_ressources->_bottomGame));
  bottomGame2->setPosition(bottomGame2->getGlobalBounds().second.first, 860);
  _inGame.push_back(*bottomGame2);

  Sprite *hud = new Sprite;

  hud->setTexture(*((RenderWindow::getInstance())->_ressources->_hud));
  hud->setPosition(0, 0);
  _inGame.push_back(*hud);


  Sprite *black = new Sprite;

  black->setTexture(*((RenderWindow::getInstance())->_ressources->_backgroundBlack));
  black->setPosition(0, 0);
  black->getSprite().setColor(sf::Color(255, 255, 255, 0));
  _inGame.push_back(*black);

  this->setPlayers(static_cast<RoomPanel*>(window->getPanels().top())->getNbPlayers(), static_cast<RoomPanel*>(window->getPanels().top())->getCurrentPlayer());


  Text	*sentence = new Text();

  sentence->setString("Wave 1");
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

void			GamePanel::playerLeft(const std::string &playerName)
{
  RenderWindow *window = RenderWindow::getInstance();

  static_cast<GamePanel*>(window->getPanels().top())->getLabels().at(2).getText().setColor(sf::Color(255, 255, 255, 255));
  static_cast<GamePanel*>(window->getPanels().top())->getLabels().at(2).getText().setString(playerName + " has left the game");
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
  int	  	id = std::atoi(vector.at(1).c_str());
  Sprite	*newSprite = new Sprite();
  std::string  	type = vector.at(0);
 
  std::cout << "[SUCCESS] creating entity : ID = " << id << "; Type  = " << type << ";" << std::endl;
  std::size_t found = type.find(":");
  if (found != std::string::npos)
    {
      int parent = 0;
      
      std::size_t pos = vector.at(0).find("player");
      parent = std::stoi(vector.at(0).substr(pos + 6)) - 1;

      std::string idString = vector.at(0).erase(1, 8);
      
      type = std::to_string(std::stoi(idString) + parent);

      newSprite->setTexture(*((static_cast<GamePanel*>(window->getPanels().top())->getDicoTextures())[type]));
      newSprite->setOrigin(0, (static_cast<GamePanel*>(window->getPanels().top())->getDicoTextures())[type]->getSize()._y / 2);
    }
  else
    {
      newSprite->setTexture(*((static_cast<GamePanel*>(window->getPanels().top())->getDicoTextures())[type]));
      newSprite->setOrigin(((static_cast<GamePanel*>(window->getPanels().top())->getDicoTextures())[type])->getSize()._x / 2, ((static_cast<GamePanel*>(window->getPanels().top())->getDicoTextures())[type])->getSize()._y / 2);
    }



  newSprite->setPosition(-2000, 500);

  ((static_cast<GamePanel*>(window->getPanels().top())->getDicoSprites())).insert(std::make_pair(id, newSprite));

  //  std::cout << "[INFO] size dicoSprites : " << (static_cast<GamePanel*>(window->getPanels().top())->getDicoSprites()).size() << std::endl;

}

void		GamePanel::deleteEntity(std::vector<std::string> &vector)
{
  RenderWindow *window = RenderWindow::getInstance();
  int	id = std::atoi(vector.at(0).c_str());


  std::map<int, Sprite*>::iterator it = ((static_cast<GamePanel*>(window->getPanels().top())->getDicoSprites())).find(id);
  if (it != ((static_cast<GamePanel*>(window->getPanels().top())->getDicoSprites())).end())
    {
      ((static_cast<GamePanel*>(window->getPanels().top())->getDicoSprites())).erase(it);
      std::cout << "[SUCCESS] Deleting id :" << id << std::endl;
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

void		GamePanel::display(std::vector<std::string> &vector)
{
  RenderWindow *window = RenderWindow::getInstance();
  int  	id;

  float	posX = (std::atoi(vector.at(1).c_str())) + 70;
  float	posY = (std::atoi(vector.at(2).c_str()));

  id = std::atoi(vector.at(0).c_str());
  std::map<int, Sprite*>::iterator it = ((static_cast<GamePanel*>(window->getPanels().top())->getDicoSprites())).find(id);
  if (it != ((static_cast<GamePanel*>(window->getPanels().top())->getDicoSprites())).end())
    ((static_cast<GamePanel*>(window->getPanels().top())->getDicoSprites())[id])->setPosition(posX, posY);
  //  std::cout << "Displaying with id : " << id << "; posX : " << posX << "; posY : " << posY << std::endl;
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

  
  static_cast<GamePanel*>(window->getPanels().top())->getLabels().at(2).setString("Wave " + std::to_string(value));
  static_cast<GamePanel*>(window->getPanels().top())->getLabels().at(2).getText().setColor(sf::Color(255, 255, 255, 255));

  static_cast<GamePanel*>(window->getPanels().top())->getLabels().at(2).setOrigin(static_cast<GamePanel*>(window->getPanels().top())->getLabels().at(2).getText().getGlobalBounds().width / 2, static_cast<GamePanel*>(window->getPanels().top())->getLabels().at(2).getText().getGlobalBounds().height / 2);
  
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
  static_cast<GamePanel*>(window->getPanels().top())->getLabels().at(2).getText().setString("Are you sure to exit the game ?");

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

  _inGame.at(7).getSprite().setColor(sf::Color(255, 255, 255, 0));

  _labels.at(2).getText().setColor(sf::Color(255, 255, 255, 0));

  _escapeKey = false;

  window->setMouseCursorVisible(false);
}


void		GamePanel::exit()
{
  Sound *s = Client::getSound();
  _t->cancel();
  Client::getUDPNetwork()->close();
  std::cout << "EXIT" << std::endl;
  if (s->isPlaying("gameIntro"))
    s->stopMusic("gameIntro");
  else
    s->stopMusic("gameLoop");
  s->playMusic("mainMenu");
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

  _inputManager.joystickMovedInDirection();
  _inputManager.keyPressedInGame();
  RenderWindow *window = RenderWindow::getInstance();
  
  for (std::map<int, Sprite*>::iterator it = _dicoSprites.begin(); it != _dicoSprites.end(); ++it)
    {
      window->draw((*it).second->getSprite());
    }
  for (std::vector<Explosion *>::iterator it = _explosion.begin(); it != _explosion.end();)
    {
      window->draw((*it)->getSprite());
      (*it)->update();
      if ((*it)->getState() == true)
	it = _explosion.erase(it);
      else
	it++;
    }
  for (std::map<int, Asteroid*>::iterator it = _dicoAsteroids.begin(); it != _dicoAsteroids.end(); ++it)
    {
      window->draw((*it).second->getSprite());
      (*it).second->update();
    }

  this->drawInGame();
  this->_mainPlayer->render();
  this->drawOtherPlayer();
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
      _backgrounds.at(2).setTexture(*((RenderWindow::getInstance())->_ressources->_planetEarth));
      break;
    case 1:
      _backgrounds.at(2).setTexture(*((RenderWindow::getInstance())->_ressources->_planetExodus));
      break;
    case 2:
      _backgrounds.at(2).setTexture(*((RenderWindow::getInstance())->_ressources->_planetJupiter));
      break;
    case 3:
      _backgrounds.at(2).setTexture(*((RenderWindow::getInstance())->_ressources->_planetMars));
      break;
    case 4:
      _backgrounds.at(2).setTexture(*((RenderWindow::getInstance())->_ressources->_planetMoon));
      break;
    case 5:
      _backgrounds.at(2).setTexture(*((RenderWindow::getInstance())->_ressources->_planetNeptune));
      break;
    case 6:
      _backgrounds.at(2).setTexture(*((RenderWindow::getInstance())->_ressources->_planetSaturne));
      break;
    case 7:
      _backgrounds.at(2).setTexture(*((RenderWindow::getInstance())->_ressources->_deathStar));
      break;
    default:
      _backgrounds.at(2).setTexture(*((RenderWindow::getInstance())->_ressources->_deathStar));
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
      _inGame.at(0).move(-5, 0);
      _inGame.at(1).move(-5, 0);
      _inGame.at(3).move(-5, 0);
      _inGame.at(4).move(-5, 0);

      _backgrounds.at(2).move(-2, 0);

    }
  if (i == 492)
    _labels.at(2).getText().setColor(sf::Color(255, 255, 255, 255));



  if (_backgrounds.at(0).getGlobalBounds().first.first == -(_backgrounds.at(0).getGlobalBounds().second.first))
    {
      _backgrounds.at(0).setPosition(_backgrounds.at(0).getGlobalBounds().second.first, 0);
    }
  if (_backgrounds.at(1).getGlobalBounds().first.first == -(_backgrounds.at(1).getGlobalBounds().second.first))
    {
      _backgrounds.at(1).setPosition(_backgrounds.at(1).getGlobalBounds().second.first, 0);
    }



  if (_inGame.at(0).getGlobalBounds().first.first <= -(_inGame.at(0).getGlobalBounds().second.first))
    {
      _inGame.at(0).setPosition(_inGame.at(0).getGlobalBounds().second.first, 0);
    }
  if (_inGame.at(1).getGlobalBounds().first.first <= -(_inGame.at(1).getGlobalBounds().second.first))
    {
      _inGame.at(1).setPosition(_inGame.at(1).getGlobalBounds().second.first, 0);
    }

  if (_inGame.at(3).getGlobalBounds().first.first == -(_inGame.at(3).getGlobalBounds().second.first))
    {
      _inGame.at(3).setPosition(_inGame.at(3).getGlobalBounds().second.first, 860);
    }
  if (_inGame.at(4).getGlobalBounds().first.first == -(_inGame.at(4).getGlobalBounds().second.first))
    {
      _inGame.at(4).setPosition(_inGame.at(4).getGlobalBounds().second.first, 860);
    }



  

  if (_backgrounds.at(2).getGlobalBounds().first.first == -500)
    {
      _backgrounds.at(2).setPosition(_backgrounds.at(1).getGlobalBounds().second.first, _randPosY->generate<int>());
      //      this->setPlanetTexture(_randPlanet->generate<int>());
    }

  if (_labels.at(2).getText().getColor().a > 0 && !_escapeKey)
    _labels.at(2).getText().setColor(sf::Color(255, 255, 255, _labels.at(2).getText().getColor().a - 1));

  i++;

}
