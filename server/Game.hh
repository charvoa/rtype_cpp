//
// Game.hh for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Dec  1 17:36:09 2015 Nicolas Charvoz
// Last update Sat Dec  5 16:45:32 2015 Nicolas Charvoz
//

#ifndef _GAME_HH_
# define _GAME_HH_

# include <E_Command.hh>
# include <Parameters.hh>
# include <EntityManager.hh>
# include <Client.hh>
# include <E_EntityType.hh>
# include <stdexcept>
# include <queue>

class Game {

private:

  Parameters _params;
  std::string _id;
  EntityManager _eM;
  std::queue<E_COMMAND> _commandQueue;

public:

  Game();
  Game(const Parameters &, std::vector<Client> &, const std::string&);
  ~Game();
  void addClients(std::vector<Client> &);
  void setParameters(Parameters &);
  const std::string &getId() const;
  const Client &getClient() const;
  bool run();
  void addCommandToQueue(ANetwork::t_frame);

};

#endif
