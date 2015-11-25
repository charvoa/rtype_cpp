//
// Server.hh for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Nov 25 16:32:18 2015 Nicolas Charvoz
// Last update Wed Nov 25 16:50:59 2015 Nicolas Charvoz
//

#ifndef SERVER_HH_
# define SERVER_HH_

# include <iostream>
# include <string>
# include "ANetwork.hh"
# include "RoomManager.hh"
# include "GameManager.hh"
# include "ClientManager.hh"
# include "CommandManager.hh"

class Server {

public:

  Server();
  ~Server();
  void init();
  void run();
  bool createGame();
  bool createRoom();

  private:

  ANetwork *_network;
  RoomManager *_roomManager;
  GameManager *_gameManager;
  ClientManager *_clientManager;
  CommandManager *_commandManager;

};

#endif
