//
// Client.cpp for R-Type in /home/nicolas/rendu/rtype_cpp/client/common
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Sat Dec  5 10:16:26 2015 Nicolas Girardot
// Last update Tue Dec  8 11:14:47 2015 Nicolas Girardot
//

#include <Client.hh>
#include <ANetwork.hpp>
#include <ThreadUnix.hpp>
#include <ProtocoleClient.hh>
#include <SFML/Audio.hpp>
#include <chrono>
#include <thread>


Network	*Client::_network = NULL;
Sound *Client::_sound = NULL;

void	*readdisp(void *s)
{
  ANetwork::t_frame a;
  ProtocoleClient x;
  while (true)
    {
      try
	{
	  a = Client::getNetwork()->read();
	  x.methodChecker(a);
	}
      catch (const std::exception &e)
	{
	  std::cout << e.what() << std::endl;
	}
    }
  return s;
}

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
  window->getPanels().top()->setUserInterface();
  _sound = new Sound();
  _sound->registerMusic("../common/misc/menuMusic.ogg", "mainMenu");
  _sound->playMusic("mainMenu");
  std::unique_ptr<AThread> t(new Thread(1));
  char str1[] = "";
  (void) str1;
  t->attach(&readdisp, (void *)str1);
  t->run();
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
