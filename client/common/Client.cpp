//
// Client.cpp for R-Type in /home/nicolas/rendu/rtype_cpp/client/common
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Sat Dec  5 10:16:26 2015 Nicolas Girardot
// Last update Sat Dec  5 15:57:59 2015 Nicolas Girardot
//

#include "Client.hh"


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
  _network->connect("127.0.0.1");
  window->setWindow(sf::VideoMode(1920, 1080, 32), "R-Pint");
  window->clear();
  window->getPanels().push(static_cast<StartPanel*>(PanelFactory::createPanel(PanelFactory::PanelType::START_PANEL)));
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
