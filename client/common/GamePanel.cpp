//
// GamePanel.cpp for RTypoe in /home/nicolas/rendu/rtype_cpp/client/common
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri Dec 11 14:06:17 2015 Nicolas Girardot
// Last update Sun Dec 13 13:00:18 2015 Serge Heitzler
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
  getInputManager().setInputType(InputType::GAME_INPUT);

  window->setActive(false);

  std::unique_ptr<AThread> t(new Thread(1));
  char str1[] = "";
  (void) str1;
  t->attach(&readUDP, (void *)str1);
  t->run();

  //  for (int i = 0; i != 3; i++)
  //    _players.push_back(new OtherPlayer());
  //init all sprites with the textures;

  window->setMouseCursorVisible(false);

  Sound *s = Client::getSound();
  s->stopMusic("mainMenu");
  s->playMusic("gameIntro", 0);

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
  waveNumber->setPosition(Vector2(window->getSize()._x * 0.88, window->getSize()._y * 0.92));
  waveNumber->setColor(Color::WHITE);
  _labels.push_back(*waveNumber);


  Sprite *backgroundSpace1 = new Sprite;

backgroundSpace1->setTexture(*((RenderWindow::getInstance())->_ressources->_backgroundGame2));
  backgroundSpace1->setPosition(0, 0);
  _backgrounds.push_back(*backgroundSpace1);


  Sprite *backgroundSpace2 = new Sprite;

backgroundSpace2->setTexture(*((RenderWindow::getInstance())->_ressources->_backgroundGame2));
  backgroundSpace2->setPosition(backgroundSpace2->getGlobalBounds().second.first, 0);
  _backgrounds.push_back(*backgroundSpace2);


  Sprite *hud = new Sprite;

  hud->setTexture(*((RenderWindow::getInstance())->_ressources->_hud));
  hud->setPosition(0, 0);
  _backgrounds.push_back(*hud);


//   Sprite *planet = new Sprite;

// planet->setTexture(*((RenderWindow::getInstance())->_ressources->_planet->getTexture()));
//   planet->setPosition(0, 0);
//   _backgrounds.push_back(*planet);




  // INIT EN DUR POUR TEST

  int i = 1;
  while (i <=4)
    {
      Sprite	*ship = new Sprite();
      switch (i)
	{
	case 1:
	  ship->setTexture(*((RenderWindow::getInstance())->_ressources->_blueShip));
	  break;
	case 2:
	  ship->setTexture(*((RenderWindow::getInstance())->_ressources->_redShip));
	  break;
	case 3:
	  ship->setTexture(*((RenderWindow::getInstance())->_ressources->_greenShip));
	  break;
	case 4:
	  ship->setTexture(*((RenderWindow::getInstance())->_ressources->_yellowShip));
	  break;
	default:
	  ship->setTexture(*((RenderWindow::getInstance())->_ressources->_blackShip));
	  break;

	}
      ship->scale(0.2);
      _dicoSprites.insert(std::make_pair(i, ship));
      i++;
    }





  /* USER INTERFACE HUD */

  _mainPlayer = new MainPlayer(1);

  OtherPlayer	*other1 = new OtherPlayer(1, 2);
  OtherPlayer	*other2 = new OtherPlayer(2, 3);
  OtherPlayer	*other3 = new OtherPlayer(3, 4);

  _otherPlayers.push_back(other1);
  _otherPlayers.push_back(other2);
  _otherPlayers.push_back(other3);


}

GamePanel::~GamePanel() {}

void		GamePanel::newEnemy(std::vector<std::string> &vector)
{
  (void) vector;
}

void		GamePanel::die()
{

}

void		GamePanel::display(std::vector<std::string> &vector)
{
  RenderWindow *window = RenderWindow::getInstance();
  int  	id;
  float	posX = (std::atoi(vector.at(1).c_str()) / 255) * 1920;
  float	posY = (std::atoi(vector.at(2).c_str()) / 255) * 1080;
  //   int	scale = std::atoi(vector.at(3).c_str());

  id = std::atoi(vector.at(0).c_str());

  ((static_cast<GamePanel*>(window->getPanels().top())->getDicoSprites())[id])->setPosition(posX, posY);
  
}

std::map<int, Sprite*>		&GamePanel::getDicoSprites()
{
  return _dicoSprites;
}

std::map<std::string, Texture*>		&GamePanel::getDicoTextures()
{
  return _dicoTextures;
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
  for (std::vector<OtherPlayer *>::iterator it = _otherPlayers.begin(); it != _otherPlayers.end(); it++)
    {
      if ((*it)->getUsername() == name)
	return (*it);
    }
  return NULL;
}

MainPlayer		*GamePanel::getMainPlayer()
{
  return _mainPlayer;
}

void		GamePanel::setScore(const std::string &name, int score)
{
  RenderWindow *window = RenderWindow::getInstance();

  if (static_cast<GamePanel*>(window->getPanels().top())->getMainPlayer()->getUsername() == name)
    {
      static_cast<GamePanel*>(window->getPanels().top())->getMainPlayer()->setScore(score);
    }
  else
    {
      OtherPlayer *player;
      player = static_cast<GamePanel*>(window->getPanels().top())->getPlayerByName(name);
      if (player == NULL)
	{
	  std::cout << "Player does not exist" << std::endl;
	  return ;
	}
      player->setScore(score);
    }
}

void		GamePanel::setLife(const std::string &name, int life)
{
  RenderWindow *window = RenderWindow::getInstance();

  if (static_cast<GamePanel*>(window->getPanels().top())->getMainPlayer()->getUsername() == name)
    {
      static_cast<GamePanel*>(window->getPanels().top())->getMainPlayer()->setNbLife(life);
    }
  else
    {
      OtherPlayer *player;
      player = static_cast<GamePanel*>(window->getPanels().top())->getPlayerByName(name);
      if (player == NULL)
	{
	  std::cout << "Player does not exist" << std::endl;
	  return ;
	}
      player->setLife(life);
    }
}



void		GamePanel::render()
{
  Sound *s = Client::getSound();
  if (s->isPlaying("gameIntro") || s->isPlaying("gameLoop"));
  else
    s->playMusic("gameLoop", 1);
  this->drawBackgrounds();
  this->drawUserInterface();
  this->drawLabels();
  this->drawInGame();
  this->_mainPlayer->render();
  this->drawOtherPlayer();


  RenderWindow *window = RenderWindow::getInstance();
  for (std::map<int, Sprite*>::iterator it = _dicoSprites.begin(); it != _dicoSprites.end(); ++it)
    {
      window->draw((*it).second->getSprite());
    }

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

void		GamePanel::update()
{
  static unsigned int i = 0;

  if (i > 492)
    {
      _backgrounds.at(0).move(-1, 0);
      _backgrounds.at(1).move(-1, 0);
    }
  if (_backgrounds.at(0).getGlobalBounds().first.first == -(_backgrounds.at(0).getGlobalBounds().second.first))
    {
      _backgrounds.at(0).setPosition(_backgrounds.at(0).getGlobalBounds().second.first, 0);
    }
  if (_backgrounds.at(1).getGlobalBounds().first.first == -(_backgrounds.at(1).getGlobalBounds().second.first))
    {
      _backgrounds.at(1).setPosition(_backgrounds.at(1).getGlobalBounds().second.first, 0);
    }
  i++;

}
