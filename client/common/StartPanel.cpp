//
// StartPanel.cpp for StartPanel in /home/barnea_v/rendu/rtype_cpp/client/common
//
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
//
// Started on  Mon Nov 30 09:52:01 2015 Viveka BARNEAUD
// Last update Fri Dec  4 17:12:10 2015 Nicolas Girardot
//

#include "PanelFactory.hh"
#include "StartPanel.hh"
#include "RenderWindow.hh"
#include <iostream>

StartPanel::StartPanel() //: APanel()
{
  //  RenderWindow *window = RenderWindow::getInstance();
  Texture *cockpitTexture = new Texture;

  Sprite *cockpit = new Sprite;



  cockpitTexture->loadFromFile("../../common/res/sprites/cockpit.png");


  cockpit->setTexture(*cockpitTexture);

  cockpit->setPosition(0, 0);//window->getSize()._x / 3, window->getSize()._y / 3);

  _sprites.push_back(*cockpit);
  // this->getSprites().push_back(&backgroundSpace);
  // this->getSprites().push_back(&earth);
  // this->getSprites().push_back(&cockpit);
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

// void		StartPanel::render()
// {

// }

void		StartPanel::update()
{

}
