//
// StartPanel.cpp for StartPanel in /home/barnea_v/rendu/rtype_cpp/client/common
//
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
//
// Started on  Mon Nov 30 09:52:01 2015 Viveka BARNEAUD
// Last update Sun Dec 13 10:46:03 2015 Nicolas Girardot
//

#include <iostream>
#include <PanelFactory.hh>
#include <StartPanel.hh>
#include <RenderWindow.hh>
#include <Button.hh>
#include <ButtonFactory.hh>
#include <SoundManager.hh>
#include <RoomPanel.hh>
#include <ANetwork.hpp>
#include <Client.hh>
#include <CRC.hpp>
#include <CreateRequest.hpp>
#include <JoinPanel.hh>

StartPanel::StartPanel(){}

StartPanel::~StartPanel(){}

void		StartPanel::setUserInterface()
{
  RenderWindow *window = RenderWindow::getInstance();
  getInputManager().setInputType(InputType::MENU_INPUT);

  Sprite *backgroundSpace = new Sprite;
  Sprite *earth = new Sprite;
  Sprite *cockpit = new Sprite;
  Sprite *logo = new Sprite;
  Sprite *panelUp = new Sprite;
  Sprite *panelDown = new Sprite;


  earth->setOrigin((RenderWindow::getInstance())->_ressources->_earth->getSize()._x / 2, (RenderWindow::getInstance())->_ressources->_earth->getSize()._y / 2);
  logo->setOrigin((RenderWindow::getInstance())->_ressources->_logo->getSize()._x / 2, (RenderWindow::getInstance())->_ressources->_logo->getSize()._y / 2);

  backgroundSpace->setTexture(*((RenderWindow::getInstance())->_ressources->_backgroundStartPanel));
  earth->setTexture(*((RenderWindow::getInstance())->_ressources->_earth));
  cockpit->setTexture(*((RenderWindow::getInstance())->_ressources->_cockpit));
  logo->setTexture(*((RenderWindow::getInstance())->_ressources->_logo));
  panelUp->setTexture(*((RenderWindow::getInstance())->_ressources->_panelIntroUp));
  panelDown->setTexture(*((RenderWindow::getInstance())->_ressources->_panelIntroDown));

  backgroundSpace->setPosition(0, 0);
  panelUp->setPosition(0, 0);
  panelDown->setPosition(0, 0);
  earth->setPosition(window->getSize()._x + (RenderWindow::getInstance())->_ressources->_earth->getSize()._x / 6, window->getSize()._y + (RenderWindow::getInstance())->_ressources->_earth->getSize()._y / 6);
  cockpit->setPosition(0, 0);
  logo->setPosition(window->getSize()._x / 2, window->getSize()._y / 6);
  logo->scale(0.5);

  backgroundSpace->scale(1.1);

  _backgrounds.push_back(*backgroundSpace);
  _backgrounds.push_back(*earth);
  _backgrounds.push_back(*cockpit);
  _backgrounds.push_back(*logo);
  _backgrounds.push_back(*panelUp);
  _backgrounds.push_back(*panelDown);

  // Button

  std::string name = "CREATE ROOM";
    ButtonFactory::create(Vector2(window->getSize()._x / 2, window->getSize()._y * 0.3), name);
    name = "JOIN ROOM";
    ButtonFactory::create(Vector2(window->getSize()._x / 2, window->getSize()._y * 0.4), name);
    name = "DEMO";
    ButtonFactory::create(Vector2(window->getSize()._x / 2, window->getSize()._y * 0.5), name);
    name = "SETTINGS";
    ButtonFactory::create(Vector2(window->getSize()._x / 2, window->getSize()._y * 0.6), name);
    name = "EXIT GAME";
    ButtonFactory::create(Vector2(window->getSize()._x / 2, window->getSize()._y * 0.7), name);


    _functions.push_back((APanel::funcs)&StartPanel::createRoom);
    _functions.push_back((APanel::funcs)&StartPanel::joinRoom);
    _functions.push_back((APanel::funcs)&StartPanel::demo);
    _functions.push_back((APanel::funcs)&StartPanel::settings);
    _functions.push_back((APanel::funcs)&StartPanel::exit);
}

void        StartPanel::createRoom()
{
  ANetwork *net = Client::getNetwork();
  ANetwork::t_frame sender = CreateRequest::create((unsigned char)C_CREATE_ROOM, CRC::calcCRC(""), 0, "");
  net->write(sender);
}

void        StartPanel::goToRoom(std::vector<std::string> &vector, int from)
{
  RenderWindow *window = RenderWindow::getInstance();
  window->getPanels().push(static_cast<RoomPanel*>(PanelFactory::createPanel(PanelFactory::PanelType::ROOM_PANEL)));
  window->getPanels().top()->setUserInterface();
  static_cast<RoomPanel*>(window->getPanels().top())->updatePlayers(vector, from);
}


void        StartPanel::joinRoom()
{
  RenderWindow *window = RenderWindow::getInstance();

  window->getPanels().push(static_cast<JoinPanel*>(PanelFactory::createPanel(PanelFactory::PanelType::JOIN_PANEL)));
  window->getPanels().top()->setUserInterface();
}

void        StartPanel::demo()
{
	(RenderWindow::getInstance())->addPanel(PanelFactory::DEMO_PANEL);
        (RenderWindow::getInstance())->getPanels().top()->setUserInterface();
}

void        StartPanel::exit()
{
  (RenderWindow::getInstance())->close();
}

void        StartPanel::settings()
{
	(RenderWindow::getInstance())->addPanel(PanelFactory::SETTINGS_PANEL);
        (RenderWindow::getInstance())->getPanels().top()->setUserInterface();
}

void		StartPanel::update()
{
  static int i = 0;
  if (i == 0)
    {
      Sound *Sound = Client::getSound();
      Sound->playSound("door");
    }

  _backgrounds.at(1).rotate(0.0009);
  if (i % 10000 < 5000)
    _backgrounds.at(0).move(-0.01,-0.01);
  else
    _backgrounds.at(0).move(0.01,0.01);

  if (i * 1.5 < 255)
    {
      float tint = (i * 1.5);

      _userInterface.at(0)->getSprite().getSprite().setColor(sf::Color(255, 255, 255, tint));
      _userInterface.at(1)->getSprite().getSprite().setColor(sf::Color(255, 255, 255, tint));
      _userInterface.at(2)->getSprite().getSprite().setColor(sf::Color(255, 255, 255, tint));
      _userInterface.at(3)->getSprite().getSprite().setColor(sf::Color(255, 255, 255, tint));
      _userInterface.at(4)->getSprite().getSprite().setColor(sf::Color(255, 255, 255, tint));

      _labels.at(0).getText().setColor(sf::Color(255, 255, 255, tint));
      _labels.at(1).getText().setColor(sf::Color(255, 255, 255, tint));
      _labels.at(2).getText().setColor(sf::Color(255, 255, 255, tint));
      _labels.at(3).getText().setColor(sf::Color(255, 255, 255, tint));
      _labels.at(4).getText().setColor(sf::Color(255, 255, 255, tint));


    }

  if (i < 640)
    {
      _backgrounds.at(4).move(0,-3);
      _backgrounds.at(5).move(0,3);
    }
  i++;
}
