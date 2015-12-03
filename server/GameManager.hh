//
// GameManager.hh for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Nov 25 16:41:04 2015 Nicolas Charvoz
// Last update Thu Dec  3 05:17:23 2015 Louis Audibert
//

#ifndef GAMEMANAGER_HH_
# define GAMEMANAGER_HH_

# include <Game.hh>

class GameManager {

private:

  std::vector<Game> _games;

  public:

  GameManager();
  ~GameManager();
  Game &createGame();
  Game &getGameById(const std::string&);
  Game &getGameByClient(Client &);
};

#endif
