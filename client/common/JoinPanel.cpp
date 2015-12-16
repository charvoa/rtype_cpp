//
// JoinPanel.cpp for Rtype in /home/nicolas/rendu/rtype_cpp/client/build
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed Dec  2 16:53:07 2015 Nicolas Girardot
// Last update Tue Dec 15 07:26:43 2015 Serge Heitzler
//

#include <JoinPanel.hh>
#include <PanelFactory.hh>
#include <RenderWindow.hh>
#include <ButtonFactory.hh>
#include <ANetwork.hpp>
#include <CreateRequest.hpp>
#include <CRC.hpp>
#include <Client.hh>
#include <iostream>

JoinPanel::JoinPanel()
{
}

JoinPanel::~JoinPanel() {}

void	        JoinPanel::setUserInterface()
{
  RenderWindow *window = RenderWindow::getInstance();
  _type = PanelFactory::JOIN_PANEL;
  window->getSettings()->dumpBinds();
  getInputManager().setInputType(InputType::JOIN_INPUT);

  Sprite *backgroundSpace = new Sprite;
  Sprite *earth = new Sprite;
  Sprite *cockpit = new Sprite;
  Sprite *logo = new Sprite;
  Sprite *black = new Sprite;

  earth->setOrigin((RenderWindow::getInstance())->_ressources->_earth->getSize()._x / 2, (RenderWindow::getInstance())->_ressources->_earth->getSize()._y / 2);
  logo->setOrigin((RenderWindow::getInstance())->_ressources->_logo->getSize()._x / 2, (RenderWindow::getInstance())->_ressources->_logo->getSize()._y / 2);

  backgroundSpace->setTexture(*((RenderWindow::getInstance())->_ressources->_backgroundStartPanel));
  earth->setTexture(*((RenderWindow::getInstance())->_ressources->_earth));
  cockpit->setTexture(*((RenderWindow::getInstance())->_ressources->_cockpit));
  logo->setTexture(*((RenderWindow::getInstance())->_ressources->_logo));
  black->setTexture(*((RenderWindow::getInstance())->_ressources->_backgroundBlack));

  backgroundSpace->setPosition(0, 0);
  earth->setPosition(window->getSize()._x + (RenderWindow::getInstance())->_ressources->_earth->getSize()._x / 6, window->getSize()._y + (RenderWindow::getInstance())->_ressources->_earth->getSize()._y / 6);
  cockpit->setPosition(0, 0);
  black->setPosition(0, 0);
  logo->setPosition(window->getSize()._x / 2, window->getSize()._y / 6);
  logo->scale(0.5);

  backgroundSpace->scale(1.1);

  _backgrounds.push_back(*backgroundSpace);
  _backgrounds.push_back(*earth);
  _backgrounds.push_back(*cockpit);
  _backgrounds.push_back(*logo);
  _backgrounds.push_back(*black);

  // Button

  std::string name = "BACK";
  ButtonFactory::create(Vector2(window->getSize()._x * 0.25, window->getSize()._y * 0.7), name);
  name = "ACCESS";
  ButtonFactory::create(Vector2(window->getSize()._x * 0.75, window->getSize()._y * 0.7), name);

  _functions.push_back((APanel::funcs)&JoinPanel::back);
  _functions.push_back((APanel::funcs)&JoinPanel::join);
  

  Text		       	*id = new Text();
  
  id->setString("");
  id->setSize(60);
  id->setStyle(1);
  id->setOrigin(id->getText().getGlobalBounds().width / 2, id->getText().getGlobalBounds().height / 2);
  id->setPosition(Vector2(window->getSize()._x * 0.5, window->getSize()._y * 0.5));
  id->setFont(*((RenderWindow::getInstance())->_ressources->_fontSecond));
  id->setColor(Color::WHITE);
  _labels.push_back(*id);

  Text		       	*text = new Text();
  
  text->setString("ENTER ROOM ID TO JOIN :");
  text->setSize(80);
  text->setStyle(1);
  text->setOrigin(text->getText().getGlobalBounds().width / 2, text->getText().getGlobalBounds().height / 2);
  text->setPosition(Vector2(window->getSize()._x * 0.5, window->getSize()._y * 0.3));
  text->setColor(Color::WHITE);
  _labels.push_back(*text);


  Text		       	*error = new Text();
  
  error->setString("");
  error->setSize(40);
  error->setStyle(1);
  error->setOrigin(text->getText().getGlobalBounds().width / 2, text->getText().getGlobalBounds().height / 2);
  error->setFont(*((RenderWindow::getInstance())->_ressources->_fontSecond));
  error->setPosition(Vector2(window->getSize()._x * 0.5, window->getSize()._y * 0.4));
  error->setColor(Color::RED);
  _labels.push_back(*error);


  _alpha = 0;
}

int		JoinPanel::getType()
{
	return (PanelFactory::PanelType)_type;
}

void    JoinPanel::join()
{
  ANetwork *net = Client::getNetwork();
  ANetwork::t_frame sender = CreateRequest::create((unsigned char)C_JOIN_ROOM, CRC::calcCRC(_room), 0, _room);
  net->write(sender);
}

void    JoinPanel::back()
{
  RenderWindow::getInstance()->back();
}

void    JoinPanel::updateOnTextEntered(int key)
{
  RenderWindow *window = RenderWindow::getInstance();
  if (_room.size() < 4)
    {
      if (key >= sf::Keyboard::A && key <= sf::Keyboard::Z)
	_room += static_cast<char>(key + 65);
      if (key >= sf::Keyboard::Num0 && key <= sf::Keyboard::Num9)
	_room += static_cast<char>(key + 22);
    }
  if (key == sf::Keyboard::BackSpace && _room.size() > 0)
    _room.pop_back();
  if (key == sf::Keyboard::Return)
    if (_room.size() == 4)
      this->join();
  
  _labels.at(2).setString(_room);
  _labels.at(2).setOrigin(_labels.at(2).getText().getGlobalBounds().width / 2, _labels.at(2).getText().getGlobalBounds().height / 2);
  _labels.at(2).setPosition(Vector2(window->getSize()._x * 0.5, window->getSize()._y * 0.5));
}

void	JoinPanel::setError(const std::string &error)
{

  Sound *s = Client::getSound();
  RenderWindow *window = RenderWindow::getInstance();
  static_cast<JoinPanel*>(window->getPanels().top())->setAlpha(255);
  static_cast<JoinPanel*>(window->getPanels().top())->getLabels().at(4).setString(error);


  static_cast<JoinPanel*>(window->getPanels().top())->getLabels().at(4).setOrigin(static_cast<JoinPanel*>(window->getPanels().top())->getLabels().at(4).getText().getGlobalBounds().width / 2, static_cast<JoinPanel*>(window->getPanels().top())->getLabels().at(4).getText().getGlobalBounds().height / 2);

  
  static_cast<JoinPanel*>(window->getPanels().top())->getLabels().at(4).getText().setColor(sf::Color(255, 0, 0, static_cast<JoinPanel*>(window->getPanels().top())->getAlpha()));

  s->playSound("denied");  
}

void	        JoinPanel::update()
{
  if (_alpha > 0)
    {
      _labels.at(4).getText().setColor(sf::Color(255, 0, 0, _alpha));
      _alpha--;
    } 
}

int	JoinPanel::getAlpha()
{
  return _alpha;
}

void	JoinPanel::setAlpha(int value)
{
  _alpha = value;
}
