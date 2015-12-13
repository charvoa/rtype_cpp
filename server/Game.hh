//
// Game.hh for  in /home/nicolaschr/rendu/rtype_cpp/server
//
 // Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Dec  1 17:36:09 2015 Nicolas Charvoz
// Last update Sun Dec 13 11:20:26 2015 Nicolas Charvoz
//

#ifndef _GAME_HH_
# define _GAME_HH_

# include <ProtocoleEnum.hh>
# include <Player.hh>
# include <Parameters.hh>
# include <EntityManager.hh>
# include <Client.hh>
# include <E_EntityType.hh>
# include <ThreadFactory.hh>
# include <Mutex.hpp>
# include <memory>
# include <CreateRequest.hpp>
# ifdef _WIN32
#	include <NetworkWin.hpp>
# else
#	include <Network.hpp>
# endif
# include <stdexcept>
# include <queue>
# include <CRC.hpp>
# include <sstream>
# include <map>

class Game {

  typedef void(Game::*Func)(void*, Client*);
  std::map<E_Command, Func> _funcMap;

private:

  Parameters _params;
  std::string _id;
  EntityManager _eM;
  std::queue<ANetwork::t_frame> _commandQueue;
  AMutex *_mutex;
  int	_stage;
  int	_nbDisplay;
public:

  struct dataThread {
    Game *game;
    ANetwork *network;
  };

  Game();
  Game(const Parameters&, std::vector<Client *>&, const std::string&, int port);
  ~Game();
  void addClients(std::vector<Client *> &);
  void setParameters(Parameters &);
  const std::string &getId() const;
  const Client &getClient() const;
  bool run();
  void addCommandToQueue(ANetwork::t_frame);
  Client *getClientBySocket(ISocket*) const;
  Player *getPlayerByClient(Client*);
  void handleHandshakeUDP(void*, Client*);
  void handleMove(void*, Client*);
  void handleCommand(void*, Client*);
  int  getNumberEnemyMax();
  void addMonster();
  void initPlayersPosition();
  std::vector<Client *> _clients;
  ANetwork *_network;

};

#endif
