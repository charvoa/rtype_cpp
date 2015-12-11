//
// GamePanel.cpp for RTypoe in /home/nicolas/rendu/rtype_cpp/client/common
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri Dec 11 14:06:17 2015 Nicolas Girardot
// Last update Sat Dec 12 02:12:05 2015 Serge Heitzler
//

#include <GamePanel.hh>
#include <iostream>

GamePanel::GamePanel()
{
  //  for (int i = 0; i != 3; i++)
  //    _players.push_back(new PlayerIG());
  //init all sprites with the textures;






  
}

GamePanel::~GamePanel() {}

void		GamePanel::render()
{

}

void		GamePanel::display(std::vector<std::string> &vector)
{
  RenderWindow *window = RenderWindow::getInstance();

  static_cast<GamePanel*>(window->getPanels().top())->getSprites().at(std::atoi(vector.at(0).c_str()))->setPosition(std::atoi(vector.at(1).c_str()), std::atoi(vector.at(2).c_str()));
  static_cast<GamePanel*>(window->getPanels().top())->getSprites().at(std::atoi(vector.at(0).c_str()))->scale(std::atoi(vector.at(3).c_str()));
  window->draw(static_cast<GamePanel*>(window->getPanels().top())->getSprites().at(std::atoi(vector.at(0).c_str()))->getSprite());
}

std::vector<Sprite *> &GamePanel::getSprites()
{
  return _sprites;
}

Text		*GamePanel::getTeamScore()
{
  return _teamScore;
}

void		GamePanel::setTeamScore(int a)
{
  RenderWindow *window = RenderWindow::getInstance();

  static_cast<GamePanel*>(window->getPanels().top())->getTeamScore()->setString(std::to_string(a));
}

PlayerIG	*GamePanel::getPlayerByName(const std::string &name)
{
  for (std::vector<PlayerIG *>::iterator it = _players.begin(); it != _players.end(); it++)
    {
      if ((*it)->getUsername() == name)
	return (*it);
    }
  return NULL;
}

void		GamePanel::setLife(const std::string &name, int life)
{
  RenderWindow *window = RenderWindow::getInstance();

  PlayerIG *player;
  player = static_cast<GamePanel*>(window->getPanels().top())->getPlayerByName(name);
  if (player == NULL)
    {
      std::cout << "Player does not exist" << std::endl;
      return ;
    }
  player->setLife(life);
}
