//
// StartPanel.cpp for StartPanel in /home/barnea_v/rendu/rtype_cpp/client/common
//
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
//
// Started on  Mon Nov 30 09:52:01 2015 Viveka BARNEAUD
// Last update Fri Dec  4 08:39:54 2015 Serge Heitzler
//

#include "PanelFactory.hh"
#include "StartPanel.hh"
#include "RenderWindow.hh"
#include <iostream>

StartPanel::StartPanel() //: APanel()
{
  RenderWindow *window = RenderWindow::getInstance();
  Texture *backgroundSpaceTexture = new Texture;
  Texture *earthTexture = new Texture;
  Texture *cockpitTexture = new Texture;

  Sprite *backgroundSpace = new Sprite;
  Sprite *earth = new Sprite;
  Sprite *cockpit = new Sprite;



  backgroundSpaceTexture->loadFromFile("../../common/res/sprites/background.png");
  earthTexture->loadFromFile("../../common/res/sprites/planet_earth_background.png");
  cockpitTexture->loadFromFile("../../common/res/sprites/cockpit.png");


  earth->setOrigin(earthTexture->getSize()._x / 2, earthTexture->getSize()._y / 2);
  
  backgroundSpace->setTexture(*backgroundSpaceTexture);
  earth->setTexture(*earthTexture);
  cockpit->setTexture(*cockpitTexture);

  backgroundSpace->setPosition(0, 0);
  earth->setPosition(window->getSize()._x + earthTexture->getSize()._x / 6, window->getSize()._y + earthTexture->getSize()._y / 6);
  cockpit->setPosition(0, 0);

  _sprites.push_back(*backgroundSpace);
  _sprites.push_back(*earth);
  _sprites.push_back(*cockpit);
  // this->getSprites().push_back(&backgroundSpace);
  // this->getSprites().push_back(&earth);
  //  this->getSprites().push_back(*cockpit);
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

void		StartPanel::update()
{
  _sprites.at(1).rotate(0.0007);
}
