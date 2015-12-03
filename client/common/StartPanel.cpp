//
// StartPanel.cpp for StartPanel in /home/barnea_v/rendu/rtype_cpp/client/common
// 
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
// 
// Started on  Mon Nov 30 09:52:01 2015 Viveka BARNEAUD
// Last update Thu Dec  3 10:58:00 2015 Serge Heitzler
//

#include "PanelFactory.hh"
#include "StartPanel.hh"
#include "RenderWindow.hh"

StartPanel::StartPanel() : APanel()
{
  RenderWindow *window = RenderWindow::getInstance();
  Texture backgroundSpaceTexture;
  Texture earthTexture;
  Texture cockpitTexture;
  
  Sprite backgroundSpace;
  Sprite earth;
  Sprite cockpit;
  
  backgroundSpaceTexture.loadFromFile("../../common/res/sprites/background.jpg");
  earthTexture.loadFromFile("../../common/res/sprites/planet_earth_backgorund.png");
  cockpitTexture.loadFromFile("../../common/res/sprites/cockpit.png");

  backgroundSpace.setTexture(backgroundSpaceTexture);
  earth.setTexture(earthTexture);
  cockpit.setTexture(cockpitTexture);
  

  backgroundSpace.setPosition(window->getSize()._x / 2, window->getSize()._y / 2);
  earth.setPosition(window->getSize()._x, window->getSize()._y);
  cockpit.setPosition(window->getSize()._x / 2, window->getSize()._y / 2);
}

StartPanel::~StartPanel() {}

void        StartPanel::joinRoom()
{
	(RenderWindow::getInstance())->addPanel(PanelFactory::JOIN_PANEL);
}

void        StartPanel::createRoom()
{
	(RenderWindow::getInstance())->addPanel(PanelFactory::ROOM_PANEL);
}

void        StartPanel::demo()
{
	(RenderWindow::getInstance())->addPanel(PanelFactory::DEMO_PANEL);
}

void        StartPanel::exit()
{

}

void        StartPanel::settings()
{
	(RenderWindow::getInstance())->addPanel(PanelFactory::SETTINGS_PANEL);
}

void		StartPanel::render()
{

}
