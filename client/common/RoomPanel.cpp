//
// RoomPanel.cpp for RoomPanel in /home/barnea_v/rendu/rtype_cpp/client/common
//
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
//
// Started on  Mon Nov 30 09:50:28 2015 Viveka BARNEAUD
// Last update Tue Dec  8 01:33:54 2015 Serge Heitzler
//

#include "RenderWindow.hh"
#include "RoomPanel.hh"

RoomPanel::RoomPanel(){}

RoomPanel::~RoomPanel(){}


void	        RoomPanel::setUserInterface()
{
  //  RenderWindow *window = RenderWindow::getInstance();
  getInputManager().setInputType(InputType::MENU_INPUT);

  Texture *backgroundSpaceTexture = new Texture;

  Sprite *backgroundSpace = new Sprite;

  backgroundSpaceTexture->loadFromFile("../common/misc/roomPanel.png");

  backgroundSpace->setTexture(*backgroundSpaceTexture);

  backgroundSpace->setPosition(0, 0);
  
  _backgrounds.push_back(*backgroundSpace);
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

void		RoomPanel::render()
{

}

void	RoomPanel::update()
{

}
