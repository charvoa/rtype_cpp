//
// Game.hh for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Dec  1 17:36:09 2015 Nicolas Charvoz
// Last update Wed Dec  2 02:37:35 2015 Louis Audibert
//

#ifndef GAME_HH_
# define GAME_HH_

# include "E_Command.hh"
# include "Parameters.hh"
# include "EntityManager.hh"
# include <queue>

class Game {

private:

  int _id;
  EntityManager _eM;
  std::queue<E_COMMAND> _commandQueue;
  Parameters _params;

  public:

  Game();
  ~Game();
  void addPlayers(std::vector<Player> &);
  void setParameters(Parameters &);
  bool run();
  void addCommandToQueue(ANetwork::t_frame);

};

#endif
