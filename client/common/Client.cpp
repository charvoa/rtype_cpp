//
// Client.cpp for R-Type in /home/nicolas/rendu/rtype_cpp/client/common
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Sat Dec  5 10:16:26 2015 Nicolas Girardot
// Last update Sat Dec  5 06:04:52 2015 Serge Heitzler
//

#include "Client.hh"

Client::Client()
{

}

Client::~Client()
{

}

void	Client::Start()
{
  RenderWindow *window = RenderWindow::getInstance();
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
}
