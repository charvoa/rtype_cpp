//
// GameManager.cpp for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Dec  1 17:26:52 2015 Nicolas Charvoz
// Last update Sat Dec  5 16:03:03 2015 Nicolas Charvoz
//

#include <GameManager.hh>

GameManager::GameManager() {}

GameManager::~GameManager() {}

Game &GameManager::createGame() {
  Game *g = new Game();
  return *g;
}

Game &GameManager::getGameById(const std::string &s)
{
  for (std::vector<Game>::iterator it = _games.begin();
       it != _games.end() ; ++it)
    {
      if ((*it).getId() == s) {
	return (*it);
      }
    }
  throw std::logic_error("Game with this ID not found");
}

Game &GameManager::getGameByClient(const Client &c)
{
  for (std::vector<Game>::iterator it = _games.begin();
       it != _games.end() ; ++it)
    {
      if ((*it).getClient() == c) {
	return (*it);
      }
    }
  throw std::logic_error("Game with this ID not found");
}
