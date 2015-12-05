//
// Client.cpp for R-Type in /home/nicolas/rendu/rtype_cpp/client/common
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Sat Dec  5 10:16:26 2015 Nicolas Girardot
// Last update Sat Dec  5 10:51:27 2015 Nicolas Girardot
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
  StartPanel start;
  while(window->isOpen())
    {
      start.update();
      start.render();
      window->display();
      sf::Event event;
      while (window->pollEvent(event))
	{

	}
    }
}
