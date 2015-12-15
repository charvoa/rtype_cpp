//
// GameManager.cpp for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Dec  1 17:26:52 2015 Nicolas Charvoz
// Last update Sat Dec 19 17:53:42 2015 Nicolas Charvoz
//

#include <GameManager.hh>

GameManager::GameManager() {}

GameManager::~GameManager() {}

bool GameManager::createGame(const Parameters &p_, std::list<Client *> &clients_,
			     const std::string &id_, int port_,
			     std::list<Bot*> botList_)
{
  try {
    _games.push_back(Game(p_, clients_, id_, port_, botList_));
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
    return false;
  }
  return true;
}

Game &GameManager::getGameById(const std::string &s)
{
  for (std::list<Game>::iterator it = _games.begin();
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
  // for (std::list<Game>::iterator it = _games.begin();
  //      it != _games.end() ; ++it)
  //   {
  //     if ((*it).getClient().getSocket()->getFd() == c.getSocket()->getFd()) {
  // 	return (*it);
  //     }
  //   }
  // throw std::logic_error("Game with this ID not found");


  (void) c;
  Game *g = new Game();

  return *g;

}
