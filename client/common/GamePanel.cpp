//
// GamePanel.cpp for RTypoe in /home/nicolas/rendu/rtype_cpp/client/common
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri Dec 11 14:06:17 2015 Nicolas Girardot
// Last update Sat Dec 12 11:11:20 2015 Serge Heitzler
//

#ifdef _WIN32
#include "../NetworkWin.hpp"
#include <ThreadWin.hpp>
#else
#include "../Network.hpp"
#include <ThreadUnix.hpp>
#endif

#include <memory>
#include <iostream>
#include <GamePanel.hh>
#include <Client.hh>
#include <ProtocoleClient.hh>
#include <AThread.hpp>


void	*readUDP(void *s)
{
ANetwork::t_frame a;
  ProtocoleClient x;
  while (true)
    {
      std::cout << "Thread UDP" << std::endl;
      std::cout << "MICH MICH !" << std::endl;
      try
	{
	  a = Client::getUDPNetwork()->read();
	  std::cout << "Data UDP is " << a.data << std::endl;
	  x.methodChecker(a);
	}
      catch (const std::exception &e)
	{
	  std::cout << e.what() << std::endl;
	}
    }
  return s;  
}

GamePanel::GamePanel()
{
  RenderWindow *window = RenderWindow::getInstance();
  //getInputManager().setInputType(InputType::GAME_INPUT);
  // std::unique_ptr<AThread> t(new Thread(1));
  // char str1[] = "";
  // (void) str1;
  // t->attach(&readUDP, (void *)str1);
  // t->run();
  
  //  for (int i = 0; i != 3; i++)
  //    _players.push_back(new OtherPlayer());
  //init all sprites with the textures;

  std::cout << "MA BITE"  << std::endl;
  Text	*teamScore = new Text();

  teamScore->setString("0");
  teamScore->setSize(60);
  teamScore->setStyle(1);
  teamScore->setOrigin(teamScore->getText().getGlobalBounds().width / 2, teamScore->getText().getGlobalBounds().height / 2);
  teamScore->setPosition(Vector2(window->getSize()._x / 2, window->getSize()._y * 0.05));
  teamScore->setColor(Color::WHITE);
  _labels.push_back(*teamScore);

  Text	*waveNumber = new Text();

  
  waveNumber->setString("0");
  waveNumber->setSize(60);
  waveNumber->setStyle(1);
  waveNumber->setOrigin(waveNumber->getText().getGlobalBounds().width / 2, waveNumber->getText().getGlobalBounds().height / 2);
  waveNumber->setPosition(Vector2(window->getSize()._x * 0.9, window->getSize()._y * 0.95));
  waveNumber->setColor(Color::WHITE);
  _labels.push_back(*waveNumber);


  Sprite *backgroundSpace = new Sprite;

backgroundSpace->setTexture(*((RenderWindow::getInstance())->_ressources->_backgroundBlack));
  backgroundSpace->setPosition(0, 0);
  _backgrounds.push_back(*backgroundSpace);

  Sprite *hud = new Sprite;

hud->setTexture(*((RenderWindow::getInstance())->_ressources->_hud));
  hud->setPosition(0, 0);
  _backgrounds.push_back(*hud);

//   Sprite *planet = new Sprite;

// planet->setTexture(*((RenderWindow::getInstance())->_ressources->_planet->getTexture()));
//   planet->setPosition(0, 0);
//   _backgrounds.push_back(*planet);




  // INIT EN DUR POUR TEST
  
  Sprite *flag = new Sprite;
  flag->setTexture(*((RenderWindow::getInstance())->_ressources->_blueShip));
  flag->setPosition(0, 0);
  flag->scale(0.2);
  _inGame.push_back(*flag);
}

GamePanel::~GamePanel() {}

void		GamePanel::display(std::vector<std::string> &vector)
{
  RenderWindow *window = RenderWindow::getInstance();

  int	id = std::atoi(vector.at(0).c_str());
  int	posX = std::atoi(vector.at(1).c_str());
  int	posY = std::atoi(vector.at(2).c_str());
  int	scale = std::atoi(vector.at(3).c_str());
  
  static_cast<GamePanel*>(window->getPanels().top())->getInGame().at(id).setPosition(posX, posY);
  if (!static_cast<GamePanel*>(window->getPanels().top())->getInGame().at(id).isScale())
    static_cast<GamePanel*>(window->getPanels().top())->getInGame().at(id).scale(scale);
  window->draw(static_cast<GamePanel*>(window->getPanels().top())->getInGame().at(id).getSprite());
}

std::vector<Sprite *> &GamePanel::getSprites()
{
  return _sprites;
}

Text		&GamePanel::getTeamScore()
{
  return _labels.at(0);
}

Text		&GamePanel::getCurrentWave()
{
  return _labels.at(1);
}

void		GamePanel::setCurrentWave(unsigned int value)
{
  RenderWindow *window = RenderWindow::getInstance();

static_cast<GamePanel*>(window->getPanels().top())->getCurrentWave().setString(std::to_string(value));
}

void		GamePanel::setTeamScore(unsigned int value)
{
  RenderWindow *window = RenderWindow::getInstance();

static_cast<GamePanel*>(window->getPanels().top())->getTeamScore().setString(std::to_string(value));
}

OtherPlayer	*GamePanel::getPlayerByName(const std::string &name)
{
(void)name;
  // for (std::vector<PlayerIG *>::iterator it = _players.begin(); it != _players.end(); it++)
  //   {
  //     if ((*it)->getUsername() == name)
  // 	return (*it);
  //   }
return NULL;
}

void		GamePanel::setLife(const std::string &name, int life)
{
(void)name;
(void)life;
// RenderWindow *window = RenderWindow::getInstance();

// PlayerIG *player;
// player = static_cast<GamePanel*>(window->getPanels().top())->getPlayerByName(name);
// if (player == NULL)
  //   {
  //     std::cout << "Player does not exist" << std::endl;
  //     return ;
  //   }
  // player->setLife(life);
}

void		GamePanel::render()
{
this->drawBackgrounds();
this->drawUserInterface();
this->drawLabels();
this->drawInGame();
this->_mainPlayer->render();
this->drawOtherPlayer();
}

void		GamePanel::drawOtherPlayer()
{
unsigned int		i = 0;

  i = 0;
  while (i < this->_otherPlayers.size() && this->_otherPlayers.size() > 0)
    {
this->_otherPlayers.at(i)->render();
      i++;
    }
}
