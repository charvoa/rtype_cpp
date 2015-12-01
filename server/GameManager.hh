//
// GameManager.hh for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Nov 25 16:41:04 2015 Nicolas Charvoz
// Last update Tue Dec  1 17:38:53 2015 Nicolas Charvoz
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
  Game &getGameById() const;
  Game &getGameByClient(Client &) const;

};

#endif
