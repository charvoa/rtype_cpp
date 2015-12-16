//
// RoomPanel.cpp for RoomPanel in /home/barnea_v/rendu/rtype_cpp/client/common
//
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
//
// Started on  Mon Nov 30 09:50:28 2015 Viveka BARNEAUD
// Last update Wed Dec 16 08:51:44 2015 Serge Heitzler
//

#include <thread>
#include <chrono>
#include <RenderWindow.hh>
#include <RoomPanel.hh>
#include <ButtonFactory.hh>
#ifdef _WIN32
# include <NetworkWin.hpp>
#else
# include <Network.hpp>
#endif
#include <CRC.hpp>
#include <CreateRequest.hpp>
#include <Client.hh>
#include <iostream>
#include <GamePanel.hh>
#include <File.hpp>

RoomPanel::RoomPanel()
{
	_type = PanelFactory::ROOM_PANEL;
  _idRoom = "";
  _received = new std::map<std::string, Texture *>;
}

RoomPanel::~RoomPanel(){}


void	        RoomPanel::setUserInterface()
{
  RenderWindow *window = RenderWindow::getInstance();
  Sprite *background = new Sprite;

  getInputManager().setInputType(InputType::MENU_INPUT);

  background->setTexture(*((RenderWindow::getInstance())->_ressources->_backgroundRoomPanel));
  background->setPosition(0, 0);
  _backgrounds.push_back(*background);


  std::string name = "BACK";
  ButtonFactory::create(Vector2(window->getSize()._x * 0.1, window->getSize()._y * 0.95), name);

  name = "LAUNCH";
  ButtonFactory::create(Vector2(window->getSize()._x * 0.9, window->getSize()._y * 0.95), name);


  // _userInterface.at(1)->getSprite().getSprite().setColor(sf::Color(255, 255, 255, 0));
  // _labels.at(1).getText().setColor(sf::Color(255, 255, 255, 255));

  _functions.push_back((APanel::funcs)&RoomPanel::back);
  _functions.push_back((APanel::funcs)&RoomPanel::launchGame);



  _spaceShipsTextures.push_back(((RenderWindow::getInstance())->_ressources->_blackShip));
  _spaceShipsTextures.push_back(((RenderWindow::getInstance())->_ressources->_blueShip));
  _spaceShipsTextures.push_back(((RenderWindow::getInstance())->_ressources->_redShip));
  _spaceShipsTextures.push_back(((RenderWindow::getInstance())->_ressources->_greenShip));
  _spaceShipsTextures.push_back(((RenderWindow::getInstance())->_ressources->_yellowShip));

  this->createPlayers();
}

void		setFileProgression(int p, void *data)
{
  //  std::cout << p << std::endl;
  (void)p;
  (void)data;
}

void		RoomPanel::receiveFiles(int port, int nbrFiles)
{
//  usleep(1000000);
//  std::this_thread::sleep_for(1);
  for (int a = 0; a < nbrFiles; a++)
    {
      std::cout << "Passing Thourhg" << port << std::endl;
      File	file;
      file.receiveMe(RenderWindow::getInstance()->getSettings()->getIP(), port++, "./recv/", setFileProgression, NULL);
    }

  FileManager Toto("./recv/");
  RenderWindow *window = RenderWindow::getInstance();

  std::list<File *> list = Toto.getFileListByExtension("png");
  for (std::list<File*>::iterator it = list.begin(); it != list.end(); ++it) {
    Texture *text = new Texture();
    text->loadFromFile((*it)->getFullPath());
    static_cast<RoomPanel*>(window->getPanels().top())->getReceived()->insert(std::make_pair((*it)->getBasename(),text));
  }

  // create texture here
  // Use FileManager
  // Get all png files from ./recv/
  // Build Texture
}

std::map<std::string, Texture*> *RoomPanel::getReceived()
{
  return this->_received;
}

unsigned int	RoomPanel::getNbPlayers() const
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

  while (i < (static_cast<RoomPanel*>(window->getPanels().top())->getPlayers().size()))
    {
      static_cast<RoomPanel*>(window->getPanels().top())->getPlayers().at(i)->setCurrentClient(false);
      static_cast<RoomPanel*>(window->getPanels().top())->getLabels().at(i + 2).setColor(Color::WHITE);
      i++;
    }

  std::size_t pos = vector.at(0).find("player");
  unsigned int idToRemove = std::stoi(vector.at(0).substr(pos + 6)) - 1;

  std::cout << "id to remove " << idToRemove << std::endl;

  if (idToRemove + 1  >= static_cast<RoomPanel*>(window->getPanels().top())->getNbPlayers())
    {
      static_cast<RoomPanel*>(window->getPanels().top())->getBackgrounds().at(idToRemove + 1).setTexture(*(static_cast<RoomPanel*>(window->getPanels().top())->getTextures()).at(0));
      static_cast<RoomPanel*>(window->getPanels().top())->getLabels().at(idToRemove + 2).setString("");
    }


  pos = vector.at(1).find("player");
  unsigned int idToChange = std::stoi(vector.at(1).substr(pos + 6)) - 1;

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
      // static_cast<RoomPanel*>(window->getPanels().top())->getFunctions().push_back((APanel::funcs)&RoomPanel::launchGame);

      // static_cast<RoomPanel*>(window->getPanels().top())->getUserInterface().at(1)->getSprite().getSprite().setColor(sf::Color(255, 255, 255, 255));

      // static_cast<RoomPanel*>(window->getPanels().top())->getLabels().at(1).getText().setColor(sf::Color(255, 255, 255, 255));


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


//

void		RoomPanel::downloadComplete(std::string &usernameComplete)
{
  RenderWindow *window = RenderWindow::getInstance();
  std::size_t pos = usernameComplete.find("player");
  unsigned int i = std::stoi(usernameComplete.substr(pos + 6));

  static_cast<RoomPanel*>(window->getPanels().top())->getBackgrounds().at(i + 6).getSprite().setColor(sf::Color(255, 255, 255, 255));
  i++;
}


int		RoomPanel::getCurrentPlayer()
{
  return _currentPlayer;
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

      // if (i == 0)
      // 	{
      // 	  _functions.push_back((APanel::funcs)&RoomPanel::launchGame);
      // 	  _userInterface.at(2)->getSprite().getSprite().setColor(sf::Color(255, 255, 255, 255));
      // 	  _labels.at(1).getText().setColor(sf::Color(255, 255, 255, 255));
      // 	}

      i++;
    }
  i--;
  _players.at(i)->setCurrentClient(true);
  _currentPlayer = i + 1;

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
  roomID->setPosition(Vector2(0.5 * window->getSize()._x, 0.03 * window->getSize()._y));
  roomID->setFont(*((RenderWindow::getInstance())->_ressources->_fontSecond));
  roomID->setColor(Color::WHITE);
  _labels.push_back(*roomID);
  _nbPlayers = 0;


  i = 0;

  while (i < 4)
    {
      Sprite *fireShip = new Sprite;

      fireShip->setTexture(*((RenderWindow::getInstance())->_ressources->_reactor));
      fireShip->setPosition(220 + 0.2 * (i + 1) * window->getSize()._x, 0.765 * window->getSize()._y);
      fireShip->getSprite().setOrigin(_spaceShipsTextures.at(0)->getSize()._x / 2, _spaceShipsTextures.at(0)->getSize()._y / 2);
      fireShip->getSprite().setColor(sf::Color(255, 255, 255, 0));

      window->getPanels().top()->getBackgrounds().push_back(*fireShip);
      i++;
    }



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

int	RoomPanel::getType()
{
	return _type;
}
