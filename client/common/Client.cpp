//
// Client.cpp for R-Type in /home/nicolas/rendu/rtype_cpp/client/common
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Sat Dec  5 10:16:26 2015 Nicolas Girardot
// Last update Sun Jan  3 02:28:12 2016 Serge Heitzler
//

#ifdef _WIN32
#include <NetworkWin.hpp>
#include <ThreadWin.hpp>
#else
#include <Network.hpp>
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
#include <GamePanel.hh>

ANetwork	*Client::_network = NULL;
ANetwork	*Client::_UDPnetwork = NULL;
Sound		*Client::_sound = NULL;

void	*readdisp(void *s)
{
  RenderWindow *window = RenderWindow::getInstance();
  ProtocoleClient x;
  void	*data;
  while (true)
    {
      if (!(data = Client::getNetwork()->read(sizeof(ANetwork::t_frame)))) { //Client Disconnected
	{
	  static_cast<GamePanel*>(window->getPanels().top())->getLabels().at(2).getText().setColor(sf::Color::Red);
	  static_cast<GamePanel*>(window->getPanels().top())->getLabels().at(2).getText().setString("Connection lost !");
	  static_cast<GamePanel*>(window->getPanels().top())->getLabels().at(2).getText().setOrigin(static_cast<GamePanel*>(window->getPanels().top())->getLabels().at(2).getText().getGlobalBounds().width / 2, static_cast<GamePanel*>(window->getPanels().top())->getLabels().at(2).getText().getGlobalBounds().height / 2);
	  try
	    {
	      Client::getNetwork()->connect(RenderWindow::getInstance()->getSettings()->getIP());
	    }
	  catch (const std::exception & e)
	    {

	    }
	}
      }
      else
		x.methodChecker(*reinterpret_cast<ANetwork::t_frame*>(data));
    }
  return s;
}

Client::Client(int port) : _port(port)
{

}

Client::~Client()
{

}

void	Client::Start()
{
  //Creating Everything

  RenderWindow *window = RenderWindow::getInstance();
  _network = new Network();
  _UDPnetwork = new Network();
  _sound = new Sound();

  //Connecting to server

  _network->init(window->getSettings()->getPort(), ANetwork::TCP_MODE);
  std::cout << "Connecting to : " << window->getSettings()->getIP() << ":" << window->getSettings()->getPort() << std::endl;
  try {
	  _network->connect(window->getSettings()->getIP());
  }
  catch (const std::exception &e)
  {
	  std::cerr << e.what() << std::endl;
  }
  //Sending Handshake

  ANetwork::t_frame sender = CreateRequest::create((unsigned char)C_HANDSHAKE, CRC::calcCRC("Bonjour 1.0"), 0, "Bonjour 1.0");
  _network->write(sender);

  //Creating SF::window

  window->setWindow(sf::VideoMode(1920, 1080, 32), "R-Pint");
  window->setFramerateLimit(60);
  window->clear();

  //Creating Textures for splash screen

  Texture	*splashScreenTexture = new Texture();
  Sprite	*splashScreen = new Sprite();

  splashScreenTexture->loadFromFile("../common/misc/splash_screen.png");
  splashScreen->setTexture(*splashScreenTexture);
  splashScreen->setPosition(0, 0);

  //Display Splash screen and loading Ressources

  window->draw(splashScreen->getSprite());
  window->display();
  window->_ressources = new Ressources();

  window->getPanels().push(static_cast<StartPanel*>(PanelFactory::createPanel(PanelFactory::PanelType::START_PANEL)));
  window->getPanels().top()->setUserInterface();

  //Adding & playing music for Menu

  _sound->registerSound("../common/misc/mouseHover.ogg", "hover");
  _sound->registerSound("../common/misc/accessDenied.ogg", "denied");
  _sound->registerSound("../common/misc/metalDoorOpen.ogg", "door");
  _sound->registerMusic("../common/misc/laserSound.ogg", "riffle");
  _sound->registerSound("../common/misc/rocketSound.ogg", "missile");
  _sound->registerSound("../common/misc/megaLaser1.ogg", "laser");
  _sound->registerMusic("../common/misc/menuMusic1.ogg", "mainMenu");
  _sound->registerSound("../common/misc/explosion1.ogg", "explosion1");
  _sound->registerSound("../common/misc/gameOver.ogg", "endGame");
  _sound->registerMusic("../common/misc/GameMusicIntro.ogg", "gameIntro");
  _sound->registerMusic("../common/misc/GameMusicLoop.ogg", "gameLoop");
  _sound->registerSound("../common/misc/BimBamBoum.ogg", "logoSound");
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
