//
// Client.cpp for R-Type in /home/nicolas/rendu/rtype_cpp/client/common
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Sat Dec  5 10:16:26 2015 Nicolas Girardot
// Last update Mon Dec  7 11:17:12 2015 Serge Heitzler
//

#include "Client.hh"
#include <SFML/Audio.hpp>

Network	*Client::_network = NULL;
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
  //  _network->connect("10.16.253.141");
  window->setWindow(sf::VideoMode(1920, 1080, 32), "R-Pint");
  window->clear();

  std::cout << "TEST" << std::endl;
  window->getPanels().push(static_cast<StartPanel*>(PanelFactory::createPanel(PanelFactory::PanelType::START_PANEL)));
  std::cout << "TEST" << std::endl;
  window->getPanels().top()->setUserInterface();
  std::cout << window->getPanels().size() << std::endl;
  sf::Music Music;
  if (!Music.openFromFile("../common/misc/menuMusic.ogg"))
    return;
  Music.play();
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
