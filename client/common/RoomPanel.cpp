//
// RoomPanel.cpp for RoomPanel in /home/barnea_v/rendu/rtype_cpp/client/common
//
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
//
// Started on  Mon Nov 30 09:50:28 2015 Viveka BARNEAUD
// Last update Thu Dec 10 01:38:13 2015 Serge Heitzler
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



  std::string fileDefault = "../common/misc/MicroDesignDefault.png";
  std::string fileHighlight = "../common/misc/MicroDesignHighlight.png";
  std::string name = "BACK";
  ButtonFactory::create(Vector2(window->getSize()._x * 0.1, window->getSize()._y * 0.95), Vector2(100, 50), name, fileDefault, fileHighlight, fileDefault);
  name = "LAUNCH";
  ButtonFactory::create(Vector2(window->getSize()._x * 0.9, window->getSize()._y * 0.95), Vector2(100, 50), name, fileDefault, fileHighlight, fileDefault);

  
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

void		RoomPanel::newPlayer(std::string &newUsername)
{
  RenderWindow *window = RenderWindow::getInstance();
  Player *player = new Player;
  Text   *username = new Text();

  player->setUsername(newUsername);
  static_cast<RoomPanel*>(window->getPanels().top())->getPlayers().push_back(player);

  unsigned int i = static_cast<RoomPanel*>(window->getPanels().top())->getPlayers().size() - 1;
  
  username->setString(newUsername);
  username->setSize(40);
  username->setStyle(1);
  //  username->setOrigin(username->getText().getGlobalBounds().width / 2, username->getText().getGlobalBounds().height / 2);
  username->setPosition(Vector2(0.2 * window->getSize()._x, (0.2 + (0.05 * i)) * window->getSize()._y));
  switch (i)
    {
    case 0:
      username->setColor(Color::BLUE);
    case 1:
      username->setColor(Color::RED);
    case 2:
      username->setColor(Color::GREEN);
    case 3:
      username->setColor(Color::YELLOW);
    default:
      username->setColor(Color::BLACK);
    }
  window->getPanels().top()->getLabels().push_back(*username);
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
    static_cast<RoomPanel*>(window->getPanels().top())->getPlayers().at(i)->setCurrentClient(false);
  
  std::size_t pos = vector.at(0).find("Player");
  unsigned int idToRemove = std::stoi(vector.at(0).substr(pos + 6)) - 1;
  
  static_cast<RoomPanel*>(window->getPanels().top())->getPlayers().erase(static_cast<RoomPanel*>(window->getPanels().top())->getPlayers().begin() + idToRemove - 1);
  pos = vector.at(1).find("Player");
  unsigned int idToChange = std::stoi(vector.at(1).substr(pos + 6)) - 1;
  static_cast<RoomPanel*>(window->getPanels().top())->getPlayers().at(idToChange)->setCurrentClient(true);
}

void		RoomPanel::updatePlayers(std::vector<std::string> &vector, int from)
{
  (void)from;
  RenderWindow *window = RenderWindow::getInstance();
  unsigned int i = 0;

  while (i < vector.size() - 2)
    {
      getPlayers().at(i)->setUsername(vector.at(i));
      _backgrounds.at(i + 1).setTexture(*_spaceShipsTextures.at(i + 1));
      getLabels().at(i + 2).setString(vector.at(i));
      //      getLabels().at(i + 2).setColor(Color::WHITE);
      getLabels().at(i + 2).setOrigin(_labels.at(i + 2).getText().getGlobalBounds().width / 2, _labels.at(i + 2).getText().getGlobalBounds().height / 2);
      i++;
    }
  i--;
  _players.at(i)->setCurrentClient(true);

  std::cout << "i " << i << std::endl;
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
      username->setColor(Color::CYAN);
      

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
}


void		RoomPanel::difficulty(Settings::Difficulty diff)
{
  (RenderWindow::getInstance())->getSettings()->setDifficulty(diff);
}

void		RoomPanel::launchGame()
{
  ANetwork *net = Client::getNetwork();
  ANetwork::t_frame sender = CreateRequest::create((unsigned char)C_LAUNCHGAME, CRC::calcCRC(_idRoom), 0, _idRoom);
  net->write(sender);
  //  (RenderWindow::getInstance())->addPanel(PanelFactory::GAME_PANEL);
}

void		RoomPanel::back()
{
  ANetwork *net = Client::getNetwork();
  ANetwork::t_frame sender = CreateRequest::create((unsigned char)C_PLAYERLEFT, CRC::calcCRC(_idRoom), 0, _idRoom);
  net->write(sender);
  (RenderWindow::getInstance())->back();
}

void	RoomPanel::update()
{
}

