//
// Server.hh for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Nov 25 16:32:18 2015 Nicolas Charvoz
// Last update Wed Dec  9 17:01:01 2015 Nicolas Charvoz
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

class Server {

public:
  struct serializeThread {
    Server *server;
    Client *client;
    ANetwork::t_frame frame;
  };

public:

  Server();
  ~Server();
  void init(int);
  void run();
  bool createGame(ANetwork::t_frame frame, void *data);
  bool createRoom(ANetwork::t_frame frame, void *data);
  bool joinRoom(ANetwork::t_frame frame, void *data);
  bool	playerLeftRoom(ANetwork::t_frame frame, void *data);
  RoomManager _roomManager;
  GameManager _gameManager;

private:

  ANetwork *_network;
  ClientManager _clientManager;
  CommandManager _commandManager;

};

void sendMessage(std::vector<Client>&, unsigned char);
void *newGameThread(void*);

#endif
