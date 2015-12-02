//
// GameManager.hh for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Nov 25 16:41:04 2015 Nicolas Charvoz
// Last update Wed Dec  2 13:19:38 2015 Nicolas Charvoz
//

#ifndef GAMEMANAGER_HH_
# define GAMEMANAGER_HH_

# include "Game.hh"

class GameManager {

private:

  std::vector<Game> _games;

  public:

  GameManager();
  ~GameManager();
  Game &createGame();
  Game &getGameById();
  Game &getGameByClient(Client &);
};

#endif
