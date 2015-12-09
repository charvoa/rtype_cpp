//
// JoinPanel.cpp for Rtype in /home/nicolas/rendu/rtype_cpp/client/build
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed Dec  2 16:53:07 2015 Nicolas Girardot
// Last update Wed Dec  9 03:16:34 2015 Serge Heitzler
//

#include <JoinPanel.hh>
#include <PanelFactory.hh>
#include <RenderWindow.hh>
#include <ButtonFactory.hh>
#include <iostream>

JoinPanel::JoinPanel()
{
}

JoinPanel::~JoinPanel() {}

void	        JoinPanel::setUserInterface()
{
  RenderWindow *window = RenderWindow::getInstance();
  getInputManager().setInputType(InputType::MENU_INPUT);

  Texture *backgroundSpaceTexture = new Texture;
  Texture *earthTexture = new Texture;
  Texture *cockpitTexture = new Texture;
  Texture *logoTexture = new Texture;
  Texture *blackTexture = new Texture;

  Sprite *backgroundSpace = new Sprite;
  Sprite *earth = new Sprite;
  Sprite *cockpit = new Sprite;
  Sprite *logo = new Sprite;
  Sprite *black = new Sprite;

  backgroundSpaceTexture->loadFromFile("../common/misc/background.png");
  earthTexture->loadFromFile("../common/misc/planet_earth_background.png");
  cockpitTexture->loadFromFile("../common/misc/cockpit.png");
  logoTexture->loadFromFile("../common/misc/rtype_logo.png");
  blackTexture->loadFromFile("../common/misc/black_background.png");

  earth->setOrigin(earthTexture->getSize()._x / 2, earthTexture->getSize()._y / 2);
  logo->setOrigin(logoTexture->getSize()._x / 2, logoTexture->getSize()._y / 2);

  backgroundSpace->setTexture(*backgroundSpaceTexture);
  earth->setTexture(*earthTexture);
  cockpit->setTexture(*cockpitTexture);
  logo->setTexture(*logoTexture);
  black->setTexture(*blackTexture);

  backgroundSpace->setPosition(0, 0);
  earth->setPosition(window->getSize()._x + earthTexture->getSize()._x / 6, window->getSize()._y + earthTexture->getSize()._y / 6);
  cockpit->setPosition(0, 0);
  black->setPosition(0, 0);
  logo->setPosition(window->getSize()._x / 2, window->getSize()._y / 6);
  logo->scale(0.5);

  backgroundSpace->scale(1.1);

  std::cout << "SIZE " << _backgrounds.size() << std::endl;

  _backgrounds.push_back(*backgroundSpace);
  _backgrounds.push_back(*earth);
  _backgrounds.push_back(*cockpit);
  _backgrounds.push_back(*logo);
  _backgrounds.push_back(*black);

  // Button

  std::string fileDefault = "../common/misc/MicroDesignDefault.png";
  std::string fileHighlight = "../common/misc/MicroDesignHighlight.png";
  std::string name = "BACK";
  ButtonFactory::create(Vector2(window->getSize()._x * 0.25, window->getSize()._y * 0.7), Vector2(100, 50), name, fileDefault, fileHighlight, fileDefault);
    name = "JOIN";
    ButtonFactory::create(Vector2(window->getSize()._x * 0.75, window->getSize()._y * 0.7), Vector2(100, 50), name, fileDefault, fileHighlight, fileDefault);

    _functions.push_back((APanel::funcs)&JoinPanel::back);
    _functions.push_back((APanel::funcs)&JoinPanel::join);
}

void    JoinPanel::join()
{
  // ANetwork *net = Client::getNetwork();
  // ANetwork::t_frame sender = CreateRequest::create((unsigned char)3, CRC::calcCRC(ID_ROOM), 0, ID_ROOM);
  // net->write(sender);
}

void    JoinPanel::back()
{
  RenderWindow::getInstance()->back();
}
