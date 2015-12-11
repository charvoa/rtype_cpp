//
// Client.cpp for R-Type in /home/nicolas/rendu/rtype_cpp/client/common
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Sat Dec  5 10:16:26 2015 Nicolas Girardot
// Last update Thu Dec 10 23:25:14 2015 Serge Heitzler
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
#include <Ressources.hh>


ANetwork	*Client::_network = NULL;
ANetwork	*Client::_UDPnetwork = NULL;
Sound *Client::_sound = NULL;

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
  RenderWindow *window = RenderWindow::getInstance();

  _network = new Network();
  _UDPnetwork = new Network();
  _network->init(4253, ANetwork::TCP_MODE);
  _network->connect("0");
  ANetwork::t_frame sender = CreateRequest::create((unsigned char)C_HANDSHAKE, CRC::calcCRC("Bonjour 1.0"), 0, "Bonjour 1.0");

  
  _network->write(sender);
  //  _network->connect("10.16.252.241");
  _UDPnetwork->init(4254, ANetwork::UDP_MODE);
  //_UDPnetwork->connect("0");

  Texture	*splashScreenTexture = new Texture();
  Sprite	*splashScreen = new Sprite();

  splashScreenTexture->loadFromFile("../common/misc/background.png");
  splashScreen->setTexture(*splashScreenTexture);
  splashScreen->setPosition(0, 0);
  splashScreen->scale(1.1);

  
  window->setWindow(sf::VideoMode(1920, 1080, 32), "R-Pint");
  window->clear();

  window->draw(splashScreen->getSprite());
  window->display();

  window->_ressources = new Ressources();


  //sleep(2);
  int i = 255;
  while (i >= 0)
    {
      splashScreen->getSprite().setColor(sf::Color(i, i, i, 255));
      window->draw(splashScreen->getSprite());
      window->display();
      i--;
    }

  std::cout << "IIL" << std::endl;
  window->getPanels().push(static_cast<StartPanel*>(PanelFactory::createPanel(PanelFactory::PanelType::START_PANEL)));
  std::cout << "IIL" << std::endl;
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
