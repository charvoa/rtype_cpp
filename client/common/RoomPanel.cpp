//
// RoomPanel.cpp for RoomPanel in /home/barnea_v/rendu/rtype_cpp/client/common
//
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
//
// Started on  Mon Nov 30 09:50:28 2015 Viveka BARNEAUD
// Last update Thu Dec 10 14:44:20 2015 Serge Heitzler
//

#include <RenderWindow.hh>
#include <RoomPanel.hh>
#include <ButtonFactory.hh>
#include <Network.hpp>
#include <CRC.hpp>
#include <CreateRequest.hpp>
#include <Client.hh>
#include <iostream>

RoomPanel::RoomPanel()
{
  _idRoom = "";
}

RoomPanel::~RoomPanel(){}


void	        RoomPanel::setUserInterface()
{
  RenderWindow *window = RenderWindow::getInstance();
  Texture *backgroundSpaceTexture = new Texture;
  Sprite *backgroundSpace = new Sprite;

  getInputManager().setInputType(InputType::MENU_INPUT);

  backgroundSpaceTexture->loadFromFile("../common/misc/room_background.png");

  backgroundSpace->setTexture(*backgroundSpaceTexture);

  backgroundSpace->setPosition(0, 0);

  backgroundSpace->scale(1.1);

  _backgrounds.push_back(*backgroundSpace);



  std::string name = "BACK";
  ButtonFactory::create(Vector2(window->getSize()._x * 0.1, window->getSize()._y * 0.95), name);
  name = "LAUNCH";
  ButtonFactory::create(Vector2(window->getSize()._x * 0.9, window->getSize()._y * 0.95), name);

  
  _functions.push_back((APanel::funcs)&RoomPanel::back);
  _functions.push_back((APanel::funcs)&RoomPanel::launchGame);

  Texture *blackShipTexture = new Texture;
  blackShipTexture->loadFromFile("../common/misc/player_black.png");
  Texture *blueShipTexture = new Texture;
  blueShipTexture->loadFromFile("../common/misc/player_blue.png");
  Texture *redShipTexture = new Texture;
  redShipTexture->loadFromFile("../common/misc/player_red.png");
  Texture *greenShipTexture = new Texture;
  greenShipTexture->loadFromFile("../common/misc/player_green.png");
  Texture *yellowShipTexture = new Texture;
  yellowShipTexture->loadFromFile("../common/misc/player_yellow.png");

  _spaceShipsTextures.push_back(blackShipTexture);
  _spaceShipsTextures.push_back(blueShipTexture);
  _spaceShipsTextures.push_back(redShipTexture);
  _spaceShipsTextures.push_back(greenShipTexture);
  _spaceShipsTextures.push_back(yellowShipTexture);

  this->createPlayers();
}

unsigned int	RoomPanel::getNbPlayers()
{
  return _nbPlayers;
}

void	RoomPanel::minusNbPlayers()
{
  _nbPlayers--;
}

void	RoomPanel::addNbPlayers()
{
  _nbPlayers++;
}

std::vector<Texture*>	&RoomPanel::getTextures()
{
  return _spaceShipsTextures;
}


void		RoomPanel::newPlayer(std::string &newUsername)
{
  RenderWindow *window = RenderWindow::getInstance();
  unsigned int i = static_cast<RoomPanel*>(window->getPanels().top())->getNbPlayers();

  static_cast<RoomPanel*>(window->getPanels().top())->getLabels().at(i + 2).setString(newUsername);    
  static_cast<RoomPanel*>(window->getPanels().top())->getLabels().at(i + 2).setOrigin(static_cast<RoomPanel*>(window->getPanels().top())->getLabels().at(i + 2).getText().getGlobalBounds().width / 2, static_cast<RoomPanel*>(window->getPanels().top())->getLabels().at(i + 2).getText().getGlobalBounds().height / 2);
  
  static_cast<RoomPanel*>(window->getPanels().top())->getBackgrounds().at(i + 1).setTexture(*(static_cast<RoomPanel*>(window->getPanels().top())->getTextures()).at(i + 1));

  static_cast<RoomPanel*>(window->getPanels().top())->addNbPlayers();
}

std::vector<Player*>	&RoomPanel::getPlayers()
{
  return _players;
}

void		RoomPanel::playerLeft(std::vector<std::string> &vector)
{
  RenderWindow *window = RenderWindow::getInstance();
  unsigned int i = 0;

  std::cout << "FIRST USERNAME" << vector.at(0) << std::endl;
  std::cout << "SECOND USERNAME " << vector.at(1) << std::endl;

  while (i < (static_cast<RoomPanel*>(window->getPanels().top())->getPlayers().size()))
    {
      static_cast<RoomPanel*>(window->getPanels().top())->getPlayers().at(i)->setCurrentClient(false);
      static_cast<RoomPanel*>(window->getPanels().top())->getLabels().at(i + 2).setColor(Color::WHITE);
      i++;
    }
  
  std::size_t pos = vector.at(0).find("player");
  unsigned int idToRemove = std::stoi(vector.at(0).substr(pos + 6)) - 1;

  std::cout << "id to remove " << idToRemove << std::endl;

  static_cast<RoomPanel*>(window->getPanels().top())->getBackgrounds().at(idToRemove + 1).setTexture(*(static_cast<RoomPanel*>(window->getPanels().top())->getTextures()).at(0));
  static_cast<RoomPanel*>(window->getPanels().top())->getLabels().at(idToRemove + 2).setString("");

  
  pos = vector.at(1).find("player");
  unsigned int idToChange = std::stoi(vector.at(1).substr(pos + 6)) - 1;

  std::cout << "id you are " << idToChange << std::endl;

  static_cast<RoomPanel*>(window->getPanels().top())->getPlayers().at(idToChange)->setCurrentClient(true);
  
  static_cast<RoomPanel*>(window->getPanels().top())->getBackgrounds().at(idToChange + 1).setTexture(*(static_cast<RoomPanel*>(window->getPanels().top())->getTextures()).at(idToChange + 1));
  static_cast<RoomPanel*>(window->getPanels().top())->getLabels().at(idToChange + 2).setString(vector.at(1));


  i = static_cast<RoomPanel*>(window->getPanels().top())->getNbPlayers() - 1;
  while (i < 4)
    {
      static_cast<RoomPanel*>(window->getPanels().top())->getBackgrounds().at(i + 1).setTexture(*(static_cast<RoomPanel*>(window->getPanels().top())->getTextures()).at(0));
      static_cast<RoomPanel*>(window->getPanels().top())->getLabels().at(i + 2).setString("");
      i++;
    }
  
  switch (idToChange)
    {
    case 0:
      static_cast<RoomPanel*>(window->getPanels().top())->getLabels().at(idToChange + 2).setColor(Color::BLUE);
      break;
    case 1:
      static_cast<RoomPanel*>(window->getPanels().top())->getLabels().at(idToChange + 2).setColor(Color::RED);
      break;
    case 2:
      static_cast<RoomPanel*>(window->getPanels().top())->getLabels().at(idToChange + 2).setColor(Color::GREEN);
      break;
    case 3:
      static_cast<RoomPanel*>(window->getPanels().top())->getLabels().at(idToChange + 2).setColor(Color::YELLOW);
      break;
    default:
      static_cast<RoomPanel*>(window->getPanels().top())->getLabels().at(idToChange + 2).setColor(Color::WHITE);
      break;
    }
  

  static_cast<RoomPanel*>(window->getPanels().top())->minusNbPlayers();

  
}

void		RoomPanel::updatePlayers(std::vector<std::string> &vector, int from)
{
  (void)from;
  RenderWindow *window = RenderWindow::getInstance();
  unsigned int i = 0;

  while (i < vector.size() - 2)
    {
      std::cout << vector.at(i) << std::endl;
      getPlayers().at(i)->setUsername(vector.at(i));
      _backgrounds.at(i + 1).setTexture(*_spaceShipsTextures.at(i + 1));
      getLabels().at(i + 2).setString(vector.at(i));
      getLabels().at(i + 2).setOrigin(_labels.at(i + 2).getText().getGlobalBounds().width / 2, _labels.at(i + 2).getText().getGlobalBounds().height / 2);
      _nbPlayers++;
      i++;
    }
  i--;
  _players.at(i)->setCurrentClient(true);

  switch (i)
    {
    case 0:
      getLabels().at(i + 2).setColor(Color::BLUE);
      break;
    case 1:
      getLabels().at(i + 2).setColor(Color::RED);
      break;
    case 2:
      getLabels().at(i + 2).setColor(Color::GREEN);
      break;
    case 3:
      getLabels().at(i + 2).setColor(Color::YELLOW);
      break;
    default:
      getLabels().at(i + 2).setColor(Color::WHITE);
      break;
    }

  _idRoom = vector.at(vector.size() - 2);
  _labels.at(6).setString(_idRoom);
  _labels.at(6).setOrigin(_labels.at(6).getText().getGlobalBounds().width / 2, _labels.at(6).getText().getGlobalBounds().height / 2);
  _labels.at(6).setPosition(Vector2(0.5 * window->getSize()._x, 0.95 * window->getSize()._y));
}

void		RoomPanel::createPlayers()
{
  RenderWindow *window = RenderWindow::getInstance();
  unsigned int i = 0;
  
  std::string empty = "";
  
  while (i < 4)
    {      
      Text   *username = new Text();
      Sprite *blackShip = new Sprite;
      Player *player = new Player;
      
      player->setUsername(empty);
      player->setCurrentClient(false);

      blackShip->setTexture(*_spaceShipsTextures.at(0));
      blackShip->setPosition(0.2 * (i + 1) * window->getSize()._x, 0.6 * window->getSize()._y);
      blackShip->getSprite().setOrigin(_spaceShipsTextures.at(0)->getSize()._x / 2, _spaceShipsTextures.at(0)->getSize()._y / 2);
      blackShip->scale(0.4);

      username->setString(player->getUsername());
      username->setSize(40);
      username->setStyle(1);
      username->setOrigin(username->getText().getGlobalBounds().width / 2, username->getText().getGlobalBounds().height / 2);
      username->setPosition(Vector2(0.2 * (i + 1) * window->getSize()._x, 0.8 * window->getSize()._y));
      username->setColor(Color::WHITE);
      

      window->getPanels().top()->getBackgrounds().push_back(*blackShip);
      window->getPanels().top()->getLabels().push_back(*username);
      _players.push_back(player);
      i++;
    }

    Text		       	*roomID = new Text();
 
    roomID->setString(_idRoom);
    roomID->setSize(60);
    roomID->setStyle(1);
    roomID->setOrigin(roomID->getText().getGlobalBounds().width / 2, roomID->getText().getGlobalBounds().height / 2);
    roomID->setPosition(Vector2(0.5 * window->getSize()._x, 0.95 * window->getSize()._y));
    roomID->setColor(Color::WHITE);
    _labels.push_back(*roomID);
    _nbPlayers = 0;
}


void		RoomPanel::difficulty(Settings::Difficulty diff)
{
  (RenderWindow::getInstance())->getSettings()->setDifficulty(diff);
}

void		RoomPanel::launchGame()
{
  ANetwork *net = Client::getNetwork();
  ANetwork::t_frame sender = CreateRequest::create((unsigned char)C_LAUNCH_GAME, CRC::calcCRC(_idRoom), 0, _idRoom);
  net->write(sender);
  //  (RenderWindow::getInstance())->addPanel(PanelFactory::GAME_PANEL);
}

void		RoomPanel::back()
{
  ANetwork *net = Client::getNetwork();
  ANetwork::t_frame sender = CreateRequest::create((unsigned char)C_PLAYER_LEFT, CRC::calcCRC(_idRoom), 0, _idRoom);
  net->write(sender);
  (RenderWindow::getInstance())->back();
}

void	RoomPanel::update()
{
}

