//
// GameManager.cpp for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Dec  1 17:26:52 2015 Nicolas Charvoz
// Last update Sat Dec  5 17:19:24 2015 Nicolas Charvoz
//

#include <GameManager.hh>

GameManager::GameManager() {}

GameManager::~GameManager() {}

void GameManager::createGame(const Parameters &p_, std::vector<Client> &clients_,
			     const std::string &id_) {
  Game *g = new Game(p_, clients_, id_);

  _games.push_back(*g);
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
  // for (std::vector<Game>::iterator it = _games.begin();
  //      it != _games.end() ; ++it)
  //   {
  //     if ((*it).getClient() == c) {
  // 	return (*it);
  //     }
  //   }
  // throw std::logic_error("Game with this ID not found");
  (void)c;
  Game *g = new Game();
  return *g;
}
