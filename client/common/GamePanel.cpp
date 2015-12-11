//
// GamePanel.cpp for RTypoe in /home/nicolas/rendu/rtype_cpp/client/common
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri Dec 11 14:06:17 2015 Nicolas Girardot
// Last update Fri Dec 11 17:33:27 2015 Nicolas Girardot
//

#include <GamePanel.hh>
#include <iostream>

GamePanel::GamePanel() : APanel()
{
  for (int i = 0; i != 3; i++)
    _players.push_back(new PlayerIG());
}

GamePanel::~GamePanel() {}

void		GamePanel::render()
{

}

Text		*GamePanel::getScore()
{
  return _score;
}

void		GamePanel::setScore(int	a)
{
  RenderWindow *window = RenderWindow::getInstance();

  static_cast<GamePanel*>(window->getPanels().top())->getScore()->setString(std::to_string(a));
}

PlayerIG	*GamePanel::getPlayerByName(const std::string &name)
{
  for (std::vector<PlayerIG *>::iterator it = _players.begin(); it != _players.end(); it++)
    {
      if ((*it)->getName() == name)
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
