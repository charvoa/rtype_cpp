//
// RoomPanel.cpp for RoomPanel in /home/barnea_v/rendu/rtype_cpp/client/common
//
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
//
// Started on  Mon Nov 30 09:50:28 2015 Viveka BARNEAUD
// Last update Tue Dec  8 16:01:43 2015 Nicolas Girardot
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

  std::cout << "1" << std::endl;
  getInputManager().setInputType(InputType::MENU_INPUT);


  std::cout << "2zz" << std::endl;
  Texture *backgroundSpaceTexture = new Texture;

  std::cout << "3" << std::endl;
  Sprite *backgroundSpace = new Sprite;

  std::cout << "4" << std::endl;
    backgroundSpaceTexture->loadFromFile("../common/misc/roomPanel.png");

  std::cout << "5" << std::endl;
  backgroundSpace->setTexture(*backgroundSpaceTexture);

  std::cout << "6" << std::endl;
  backgroundSpace->setPosition(0, 0);

  std::cout << "7" << std::endl;
  backgroundSpace->scale(1.1);






  std::cout << "8" << std::endl;
  _backgrounds.push_back(*backgroundSpace);


  std::cout << "9" << std::endl;

  std::string fileDefault = "../common/misc/MicroDesignDefault.png";
  std::string fileHighlight = "../common/misc/MicroDesignHighlight.png";
  std::string name = "BACK";

  std::cout << "10" << std::endl;
  ButtonFactory::create(Vector2(window->getSize()._x * 0.1, window->getSize()._y * 0.95), Vector2(100, 50), name, fileDefault, fileHighlight, fileDefault);
  name = "LAUNCH";
  ButtonFactory::create(Vector2(window->getSize()._x * 0.9, window->getSize()._y * 0.95), Vector2(100, 50), name, fileDefault, fileHighlight, fileDefault);



  std::cout << "11" << std::endl;

  this->updatePlayers();

  std::cout << "12" << std::endl;

}


void		RoomPanel::updatePlayers()
{
  RenderWindow *window = RenderWindow::getInstance();
  Player *player = new Player;
  _players.push_back(player);
  _players.push_back(player);

  unsigned int i = 0;

  while (i < _players.size())
    {
      Text		       	*id = new Text();
      id->setString(std::to_string(i + 1));
      id->setSize(40);
      id->setStyle(1);
      id->setOrigin(id->getText().getGlobalBounds().width / 2, id->getText().getGlobalBounds().height / 2);
      id->setPosition(Vector2(0.1 * window->getSize()._x, (0.2 + (0.05 * i)) * window->getSize()._y));
      id->setColor(Color::BLACK);

      Text		       	*username = new Text();
      username->setString(_players.at(i)->getUsername());
      username->setSize(40);
      username->setStyle(1);
      username->setOrigin(username->getText().getGlobalBounds().width / 2, username->getText().getGlobalBounds().height / 2);
      username->setPosition(Vector2(0.2 * window->getSize()._x, (0.2 + (0.05 * i)) * window->getSize()._y));
      username->setColor(Color::BLACK);

      window->getPanels().top()->getLabels().push_back(*id);
      window->getPanels().top()->getLabels().push_back(*username);
      i++;
    }

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
