//
// Client.cpp for R-Type in /home/nicolas/rendu/rtype_cpp/client/common
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Sat Dec  5 10:16:26 2015 Nicolas Girardot
// Last update Mon Dec  7 15:18:47 2015 Nicolas Girardot
//

#include "Client.hh"
#include <SFML/Audio.hpp>

Network	*Client::_network = NULL;
Sound *Client::_sound = NULL;
Client::Client()
{

}

Client::~Client()
{

}

void	Client::Start()
{
  RenderWindow *window = RenderWindow::getInstance();
  _network = new Network();
  _network->init(4253, ANetwork::TCP_MODE);
  //_network->connect("127.0.0.1");
  window->setWindow(sf::VideoMode(1920, 1080, 32), "R-Pint");
  window->clear();
  window->getPanels().push(static_cast<StartPanel*>(PanelFactory::createPanel(PanelFactory::PanelType::START_PANEL)));
  _sound = new Sound();
  _sound->registerMusic("../common/misc/menuMusic.ogg", "mainMenu");
  _sound->playMusic("mainMenu");
  while(window->isOpen())
    {
      window->getPanels().top()->update();
      window->getPanels().top()->render();
      window->display();
      sf::Event event;
      while (window->pollEvent(event))
	{
	  window->getPanels().top()->getInputManager().methodChecker(event);
	}
    }
  _network->close();
}

Network	*Client::getNetwork()
{
  if (!_network)
    _network = new Network();
  return _network;
}

Sound		*Client::getSound()
{
  if (!_sound)
    _sound = new Sound();
  return _sound;
}
