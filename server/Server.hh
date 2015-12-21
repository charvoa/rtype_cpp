//
// Server.hh for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Nov 25 16:32:18 2015 Nicolas Charvoz

// Last update Tue Dec 15 05:33:24 2015 Joris Bertomeu
//

#ifndef SERVER_HH_
# define SERVER_HH_

# include <iostream>
# include <string>
# include <memory>
# include <ANetwork.hpp>
# ifdef _WIN32
#  include <NetworkWin.hpp>
# else
#  include <Network.hpp>
# endif
# include <RoomManager.hh>
# include <GameManager.hh>
# include <ClientManager.hh>
# include <CommandManager.hpp>
# include <ThreadFactory.hh>
# include <CreateRequest.hpp>
# include <sstream>
# include <BotManager.hpp>
# include <Monitoring.hpp>

class Server {

public:
  struct serializeThread {
    Server *server;
    Client *client;
    ANetwork::t_frame frame;
    int port;
  };

public:

  Server();
  ~Server();
  void init(int);
  void run();
  bool handshake(ANetwork::t_frame frame, void *data);
  bool createGame(ANetwork::t_frame frame, void *data);
  bool createRoom(ANetwork::t_frame frame, void *data);
  bool joinRoom(ANetwork::t_frame frame, void *data);
  bool	playerLeftRoom(ANetwork::t_frame frame, void *data);

  RoomManager _roomManager;
  GameManager _gameManager;
  int _port;
  BotManager	*_botManager;

private:
  Monitoring	_monitoring;
  ANetwork *_network;
  //ClientManager _clientManager;
  CommandManager _commandManager;
};

void sendMessage(std::list<Client>&, unsigned char);
void *newGameThread(void*);

#endif
