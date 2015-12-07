//
// StartPanel.cpp for StartPanel in /home/barnea_v/rendu/rtype_cpp/client/common
//
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
//
// Started on  Mon Nov 30 09:52:01 2015 Viveka BARNEAUD
// Last update Mon Dec  7 01:03:57 2015 Serge Heitzler
//

#include <iostream>
#include "PanelFactory.hh"
#include "StartPanel.hh"
#include "RenderWindow.hh"
#include "InputManager.hh"
#include "Button.hh"

StartPanel::StartPanel()
{
  RenderWindow *window = RenderWindow::getInstance();
  getInputManager().setInputType(InputType::MENU_INPUT);
  
  Texture *backgroundSpaceTexture = new Texture;
  Texture *earthTexture = new Texture;
  Texture *cockpitTexture = new Texture;
  Texture *logoTexture = new Texture;

  Sprite *backgroundSpace = new Sprite;
  Sprite *earth = new Sprite;
  Sprite *cockpit = new Sprite;
  Sprite *logo = new Sprite;

  
  backgroundSpaceTexture->loadFromFile("../common/misc/background.png");
  earthTexture->loadFromFile("../common/misc/planet_earth_background.png");
  cockpitTexture->loadFromFile("../common/misc/cockpit.png");
  logoTexture->loadFromFile("../common/misc/rtype_logo.png");

  earth->setOrigin(earthTexture->getSize()._x / 2, earthTexture->getSize()._y / 2);
  logo->setOrigin(logoTexture->getSize()._x / 2, logoTexture->getSize()._y / 2);
  
  backgroundSpace->setTexture(*backgroundSpaceTexture);
  earth->setTexture(*earthTexture);
  cockpit->setTexture(*cockpitTexture);
  logo->setTexture(*logoTexture);

  backgroundSpace->setPosition(0, 0);
  earth->setPosition(window->getSize()._x + earthTexture->getSize()._x / 6, window->getSize()._y + earthTexture->getSize()._y / 6);
  cockpit->setPosition(0, 0);
  logo->setPosition(window->getSize()._x / 2, window->getSize()._y / 6);

  backgroundSpace->scale(1.1);
  
  _sprites.push_back(*backgroundSpace);
  _sprites.push_back(*earth);
  _sprites.push_back(*cockpit);
  _sprites.push_back(*logo);
  // this->getSprites().push_back(&backgroundSpace);
  // this->getSprites().push_back(&earth);
  //  this->getSprites().push_back(*cockpit);

  // Button

  std::string name = "toto";
  std::string fileDefault = "../common/misc/MicroDesignDefault.png";
  std::string fileHighlight = "../common/misc/MicroDesignHighlight.png";
  Button *startButton = new Button(Vector2(window->getSize()._x / 2, window->getSize()._y / 3), Vector2(200, 50), name, fileDefault, fileHighlight, fileDefault);
  getElements().push_back(// static_cast<AMenuElement*>
			  (startButton));
  
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
  static int i = 0;
  
  _sprites.at(1).rotate(0.0007);
  if (i % 10000 < 5000)
    _sprites.at(0).move(-0.01,-0.01);
  else
    _sprites.at(0).move(0.01,0.01);
  i++;
}
