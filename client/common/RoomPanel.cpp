//
// RoomPanel.cpp for RoomPanel in /home/barnea_v/rendu/rtype_cpp/client/common
//
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
//
// Started on  Mon Nov 30 09:50:28 2015 Viveka BARNEAUD
// Last update Tue Dec  8 13:48:17 2015 Serge Heitzler
//

#include "RenderWindow.hh"
#include "RoomPanel.hh"
#include "ButtonFactory.hh"
#include <iostream>

RoomPanel::RoomPanel()
{


}

RoomPanel::~RoomPanel(){}


void	        RoomPanel::setUserInterface()
{
  RenderWindow *window = RenderWindow::getInstance();

  getInputManager().setInputType(InputType::MENU_INPUT);


  Texture *backgroundSpaceTexture = new Texture;

  Sprite *backgroundSpace = new Sprite;

  backgroundSpaceTexture->loadFromFile("../common/misc/roomPanel.png");

  backgroundSpace->setTexture(*backgroundSpaceTexture);

  backgroundSpace->setPosition(0, 0);

  backgroundSpace->scale(1.1);

  _backgrounds.push_back(*backgroundSpace);

  std::string fileDefault = "../common/misc/MicroDesignDefault.png";
  std::string fileHighlight = "../common/misc/MicroDesignHighlight.png";
  std::string name = "BACK";

  std::cout << "10" << std::endl;
  ButtonFactory::create(Vector2(window->getSize()._x * 0.1, window->getSize()._y * 0.95), Vector2(100, 50), name, fileDefault, fileHighlight, fileDefault);
  name = "LAUNCH";
  ButtonFactory::create(Vector2(window->getSize()._x * 0.9, window->getSize()._y * 0.95), Vector2(100, 50), name, fileDefault, fileHighlight, fileDefault);

  



  
}

void		RoomPanel::newPlayer(std::string &newUsername)
{
  RenderWindow *window = RenderWindow::getInstance();
  Player *player = new Player;
  Text   *username = new Text();

  player->setUsername(newUsername);
  static_cast<RoomPanel*>(window->getPanels().top())->getPlayers().push_back(player);

  unsigned int i =  static_cast<RoomPanel*>(window->getPanels().top())->getPlayers().size() - 1;
  
  username->setString(newUsername);
  username->setSize(40);
  username->setStyle(1);
  username->setOrigin(username->getText().getGlobalBounds().width / 2, username->getText().getGlobalBounds().height / 2);
  username->setPosition(Vector2(0.2 * window->getSize()._x, (0.2 + (0.05 * i)) * window->getSize()._y));
  username->setColor(Color::BLACK);  
  window->getPanels().top()->getLabels().push_back(*username);
}

std::vector<Player*>	&RoomPanel::getPlayers()
{
  return _players;
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
      username->setOrigin(username->getText().getGlobalBounds().width / 2, username->getText().getGlobalBounds().height / 2);
      username->setPosition(Vector2(0.2 * window->getSize()._x, (0.2 + (0.05 * i)) * window->getSize()._y));
      username->setColor(Color::BLACK);
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

  
}


void		RoomPanel::difficulty(Settings::Difficulty diff)
{
  (RenderWindow::getInstance())->getSettings()->setDifficulty(diff);
}

void		RoomPanel::start()
{
	(RenderWindow::getInstance())->addPanel(PanelFactory::LOADING_PANEL);
}

void		RoomPanel::back()
{
	(RenderWindow::getInstance())->back();
}

void	RoomPanel::update()
{
}
