//
// Game.hh for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Dec  1 17:36:09 2015 Nicolas Charvoz
// Last update Wed Dec  2 11:33:51 2015 Nicolas Charvoz
//

#ifndef GAME_HH_
# define GAME_HH_

# include "E_Command.hh"
# include "Parameters.hh"
# include "EntityManager.hh"
# include "Client.hh"
# include "E_EntityType.hh"
# include <queue>

class Game {

private:

  int _id;
  EntityManager _eM;
  std::queue<E_COMMAND> _commandQueue;
  Parameters _params;
  Client _client;

  public:

  Game(const Parameters&, const Client&, int);
  ~Game();
  void addClients(std::vector<Client> &);
  void setParameters(Parameters &);
  bool run();
  void addCommandToQueue(ANetwork::t_frame);

};

#endif
