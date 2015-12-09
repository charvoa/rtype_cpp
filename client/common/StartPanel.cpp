//
// StartPanel.cpp for StartPanel in /home/barnea_v/rendu/rtype_cpp/client/common
//
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
//
// Started on  Mon Nov 30 09:52:01 2015 Viveka BARNEAUD
// Last update Tue Dec  8 13:30:58 2015 Serge Heitzler
//

#include <iostream>
#include <PanelFactory.hh>
#include <StartPanel.hh>
#include <RenderWindow.hh>
#include <Button.hh>
#include <ButtonFactory.hh>
#include <RoomPanel.hh>
#include <ANetwork.hpp>
#include <Client.hh>
#include <CRC.hpp>
#include <CreateRequest.hpp>

StartPanel::StartPanel(){}

StartPanel::~StartPanel(){}

void		StartPanel::setUserInterface()
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
  logo->scale(0.5);

  backgroundSpace->scale(1.1);

  _backgrounds.push_back(*backgroundSpace);
  _backgrounds.push_back(*earth);
  _backgrounds.push_back(*cockpit);
  _backgrounds.push_back(*logo);

  // Button

  std::string fileDefault = "../common/misc/MicroDesignDefault.png";
  std::string fileHighlight = "../common/misc/MicroDesignHighlight.png";
  std::string name = "CREATE";
    ButtonFactory::create(Vector2(window->getSize()._x / 2, window->getSize()._y * 0.3), Vector2(100, 50), name, fileDefault, fileHighlight, fileDefault);
    name = "JOIN";
    ButtonFactory::create(Vector2(window->getSize()._x / 2, window->getSize()._y * 0.4), Vector2(100, 50), name, fileDefault, fileHighlight, fileDefault);
    name = "SETTINGS";
    ButtonFactory::create(Vector2(window->getSize()._x / 2, window->getSize()._y * 0.5), Vector2(100, 50), name, fileDefault, fileHighlight, fileDefault);
    name = "CREDITS";
    ButtonFactory::create(Vector2(window->getSize()._x / 2, window->getSize()._y * 0.6), Vector2(100, 50), name, fileDefault, fileHighlight, fileDefault);
    name = "EXIT";
    ButtonFactory::create(Vector2(window->getSize()._x / 2, window->getSize()._y * 0.7), Vector2(100, 50), name, fileDefault, fileHighlight, fileDefault);



    _functions.push_back((APanel::funcs)&StartPanel::createRoom);
    _functions.push_back((APanel::funcs)&StartPanel::joinRoom);
    _functions.push_back((APanel::funcs)&StartPanel::settings);
    _functions.push_back((APanel::funcs)&StartPanel::credits);
    _functions.push_back((APanel::funcs)&StartPanel::exit);
}

void        StartPanel::createRoom()
{
  ANetwork *net = Client::getNetwork();
  ANetwork::t_frame sender = CreateRequest::create((unsigned char)1, CRC::calcCRC(""), 0, "");
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
  // FAIRE POP UNE MESSAGE BOX ET PAS UN NOUVEAU PANEL

  
  // (RenderWindow::getInstance())->getPanels().push(static_cast<RoomPanel*>(PanelFactory::createPanel(PanelFactory::PanelType::ROOM_PANEL)));
  // (RenderWindow::getInstance())->getPanels().top()->setUserInterface();
  // static_cast<RoomPanel*>(window->getPanels().top())->updatePlayers(vector, from);

}

void        StartPanel::demo()
{
	(RenderWindow::getInstance())->addPanel(PanelFactory::DEMO_PANEL);
        (RenderWindow::getInstance())->getPanels().top()->setUserInterface();
}

void        StartPanel::credits()
{
	(RenderWindow::getInstance())->addPanel(PanelFactory::DEMO_PANEL);
        (RenderWindow::getInstance())->getPanels().top()->setUserInterface();
}

void        StartPanel::exit()
{

}

void        StartPanel::settings()
{
	(RenderWindow::getInstance())->addPanel(PanelFactory::SETTINGS_PANEL);
        (RenderWindow::getInstance())->getPanels().top()->setUserInterface();
}

void		StartPanel::update()
{
  static int i = 0;

  _backgrounds.at(1).rotate(0.0009);
  if (i % 10000 < 5000)
    _backgrounds.at(0).move(-0.01,-0.01);
  else
    _backgrounds.at(0).move(0.01,0.01);
  i++;
}
