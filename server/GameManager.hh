//
// GameManager.hh for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Nov 25 16:41:04 2015 Nicolas Charvoz
//

#ifndef GAMEMANAGER_HH_
# define GAMEMANAGER_HH_

# include <Game.hh>

class GameManager {

private:

  std::list<Game> _games;

public:

  GameManager();
  ~GameManager();
  bool createGame(const Parameters&, std::list<Client *>&,
		  const std::string&, int, std::list<Bot*>);
  Game &getGameById(const std::string&);
  Game *getGameByClient(Client *);
  int	getNbGames() const {
    return (this->_games.size());
  };
  std::list<Game>	getGames() const {
    return (this->_games);
  };
};

#endif
