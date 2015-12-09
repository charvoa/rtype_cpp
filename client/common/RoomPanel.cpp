//
// RoomPanel.cpp for RoomPanel in /home/barnea_v/rendu/rtype_cpp/client/common
//
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
//
// Started on  Mon Nov 30 09:50:28 2015 Viveka BARNEAUD
// Last update Wed Dec  9 08:21:56 2015 Serge Heitzler
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

  getInputManager().setInputType(InputType::MENU_INPUT);


  Texture *backgroundSpaceTexture = new Texture;

  Sprite *backgroundSpace = new Sprite;

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
  RenderWindow *window = RenderWindow::getInstance();
  unsigned int i = 0;

  while (i < vector.size() - 2)
    {
      Player *player = new Player;
      Text   *username = new Text();

      player->setUsername(vector.at(i));
      username->setString(player->getUsername());
      username->setSize(40);
      username->setStyle(1);
      //      username->setOrigin(username->getText().getGlobalBounds().width / 2, username->getText().getGlobalBounds().height / 2);
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
      _players.push_back(player);
      i++;
    }
  if (from == 0)
    _players.at(0)->setCurrentClient(true);
  else
    _players.at(vector.size() - 3)->setCurrentClient(true);    

    Text		       	*roomID = new Text();
 
    roomID->setString(vector.at(vector.size() - 2));
    roomID->setSize(60);
    roomID->setStyle(1);
    roomID->setOrigin(roomID->getText().getGlobalBounds().width / 2, roomID->getText().getGlobalBounds().height / 2);
    roomID->setPosition(Vector2(0.5 * window->getSize()._x, 0.95 * window->getSize()._y));
    roomID->setColor(Color::BLACK);
    _labels.push_back(*roomID);
    _idRoom = vector.at(vector.size() - 2);
}


void		RoomPanel::difficulty(Settings::Difficulty diff)
{
  (RenderWindow::getInstance())->getSettings()->setDifficulty(diff);
}

void		RoomPanel::launchGame()
{
  ANetwork *net = Client::getNetwork();
  ANetwork::t_frame sender = CreateRequest::create((unsigned char)4, CRC::calcCRC(_idRoom), 0, _idRoom);
  net->write(sender);
  //  (RenderWindow::getInstance())->addPanel(PanelFactory::GAME_PANEL);
}

void		RoomPanel::back()
{
  ANetwork *net = Client::getNetwork();
  ANetwork::t_frame sender = CreateRequest::create((unsigned char)13, CRC::calcCRC(_idRoom), 0, _idRoom);
  net->write(sender);
  (RenderWindow::getInstance())->back();
}

void	RoomPanel::update()
{
}

