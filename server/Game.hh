//
// Game.hh for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Dec  1 17:36:09 2015 Nicolas Charvoz
// Last update Tue Dec  1 17:44:09 2015 Nicolas Charvoz
//

#ifndef GAME_HH_
# define GAME_HH_

# include "E_Command.hh"
# include "Parameters.hh"
# include "EntityManager.hh"
# include "PlayerManager.hh"
# include <queue>

class Game {

private:

  int _id;
  EntityManager _eM;
  PlayerManager _pM;
  std::queue<E_COMMAND> _commandQueue;

  public:

  Game();
  ~Game();
  void addPlayers(std::vector<Player> &);
  void setParameters(Parameters &);
  bool run();
  void addCommandToQueue(ANetwork::t_frame);

};

#endif
