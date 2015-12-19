//
// Game.hh for  in /home/nicolaschr/rendu/rtype_cpp/server
//
 // Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Dec  1 17:36:09 2015 Nicolas Charvoz
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
# include <thread>
# include <BotManager.hpp>

class Game {

typedef std::chrono::duration<int, std::ratio<1, 60>> frame_duration;
  typedef void(Game::*Func)(void*, Client*);
  std::map<E_Command, Func> _funcMap;

public:

  enum scoreDef {
    HIT = 10,
    BOSS_HIT = 25,
    KILLED = 50,
    BOSS_KILLED = 75
  };

  enum sizeInGame {
    LENGHT_MIN = 0,
    HEIGHT_MIN = 35,
    HEIGHT_MAX = 855,
    LENGHT_MAX = 1920
  };

  struct dataThread {
    Game *game;
    ANetwork *network;
  };

  // METHODS
  Game();
  Game(const Parameters&, std::list<Client *>&, const std::string&,
       int port, std::list<Bot*>);
  ~Game();
  bool run();
  const Client &getClient() const;
  const std::string &getId() const;
  void handleCommand(void*, Client*);
  void deletePlayer();
  // ATTRIBUTES
  std::list<Client *> _clients;
  ANetwork *_network;

private:

  // ATTRIBUTES
  Parameters _params;
  std::string _id;
  EntityManager _eM;
  std::queue<ANetwork::t_frame> _commandQueue;
  AMutex *_mutex;
  int	_stage;
  int	_nbDisplay;
  std::chrono::time_point<std::chrono::system_clock> _start;
  std::list<Bot*> _botList;
  bool _isRunning;
  int _nbLeft;

  // METHODS
  Player *getPlayerByClient(Client*);
  Client *getClientBySocket(ISocket*) const;
  int  getNumberEnemyMax();
  void sendNewEntity(const std::string &, int id);
  void sendNewEntity(int type, int id);
  void deleteEntity(AEntity *);
  void updateRiffle();
  void addClients(std::list<Client *> &);
  void setParameters(Parameters &);
  void checkWall(Player*);
  void handleHandshakeUDP(void*, Client*);
  void handleMove(void*, Client*);
  void handleShoot(void*, Client*);
  void updateScore(Player*, Game::scoreDef);
  void updateLife(Player*, int);
  void addMonster();
  void updateMonster();
  void initPlayersPosition();
  void sendGameData();
  bool checkMove(int, int);
  std::pair<int, int> getDirections(const std::string &);

};

#endif
