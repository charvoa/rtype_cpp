//
// Server.hh for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Nov 25 16:32:18 2015 Nicolas Charvoz
// Last update Tue Dec  8 15:16:58 2015 Nicolas Charvoz
//

#ifndef SERVER_HH_
# define SERVER_HH_

# include <iostream>
# include <string>
# include <memory>
# include <ANetwork.hpp>
# include <RoomManager.hh>
# include <GameManager.hh>
# include <ClientManager.hh>
# include <CommandManager.hpp>
# include <ThreadFactory.hh>

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

  RoomManager _roomManager;
  GameManager _gameManager;

private:

  ANetwork *_network;
  ClientManager _clientManager;
  CommandManager _commandManager;

};

#endif
