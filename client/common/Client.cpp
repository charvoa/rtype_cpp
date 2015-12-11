//
// Client.cpp for R-Type in /home/nicolas/rendu/rtype_cpp/client/common
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Sat Dec  5 10:16:26 2015 Nicolas Girardot
// Last update Fri Dec 11 11:57:18 2015 Nicolas Girardot
//

#ifdef _WIN32
#include "../NetworkWin.hpp"
#include <ThreadWin.hpp>
#else
#include "../Network.hpp"
#include <ThreadUnix.hpp>
#endif

#include <CreateRequest.hpp>
#include <CRC.hpp>
#include <Client.hh>
#include <ProtocoleClient.hh>
#include <SFML/Audio.hpp>
#include <chrono>
#include <thread>


ANetwork	*Client::_network = NULL;
ANetwork	*Client::_UDPnetwork = NULL;
Sound		*Client::_sound = NULL;

void	*readdisp(void *s)
{
  ANetwork::t_frame a;
  ProtocoleClient x;
  while (true)
    {
      std::cout << "Thread" << std::endl;
      try
	{
	  a = Client::getNetwork()->read();
	  std::cout << "Data Is " << a.data << std::endl;
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
  //Creating Everything;
  RenderWindow *window = RenderWindow::getInstance();

  _network = new Network();
  _UDPnetwork = new Network();
  _network->init(4253, ANetwork::TCP_MODE);
  _sound = new Sound();

  //Sending Handshake

  ANetwork::t_frame sender = CreateRequest::create((unsigned char)C_HANDSHAKE, CRC::calcCRC("Bonjour 1.0"), 0, "Bonjour 1.0");
  _network->write(sender);
  _network->connect("10.16.253.14");

  //Creating SF::window

  window->setWindow(sf::VideoMode(1920, 1080, 32), "R-Pint");
  window->setFramerateLimit(60);
  window->clear();

  //Panels Queue

  window->getPanels().push(static_cast<StartPanel*>(PanelFactory::createPanel(PanelFactory::PanelType::START_PANEL)));
  window->getPanels().top()->setUserInterface();


  //Adding & playing music for Menu

  _sound->registerMusic("../common/misc/menuMusic.ogg", "mainMenu");
  _sound->playMusic("mainMenu");

  //Threading the Read

  std::unique_ptr<AThread> t(new Thread(1));
  char str1[] = "";
  (void) str1;
  t->attach(&readdisp, (void *)str1);
  t->run();

  //Main Loop

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

  //Closing Thread and Window

  t->cancel();
  _network->close();
}

ANetwork	*Client::getNetwork()
{
  if (!_network)
    _network = new Network();
  return _network;
}

ANetwork	*Client::getUDPNetwork()
{
  if (!_UDPnetwork)
    _UDPnetwork = new Network();
  return _UDPnetwork;
}

Sound		*Client::getSound()
{
  if (!_sound)
    _sound = new Sound();
  return _sound;
}
