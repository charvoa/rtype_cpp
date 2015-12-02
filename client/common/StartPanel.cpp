//
// StartPanel.cpp for StartPanel in /home/barnea_v/rendu/rtype_cpp/client/common
// 
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
// 
// Started on  Mon Nov 30 09:52:01 2015 Viveka BARNEAUD
// Last update Wed Dec  2 08:15:56 2015 Serge Heitzler
//

#include "PanelFactory.hh"
#include "StartPanel.hh"

StartPanel::StartPanel() : APanel()
{
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



  // POSITION AT CENTER
  //  backgroundSpace.setPosition(0, 0);
  //  earth.setPosition();
  //  cockpit.setPosition(0, 0);
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
