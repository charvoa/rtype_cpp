//
// Server.hh for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Nov 25 16:32:18 2015 Nicolas Charvoz
// Last update Sat Dec  5 07:04:44 2015 Antoine Garcia
//

#ifndef SERVER_HH_
# define SERVER_HH_

# include <iostream>
# include <string>
# include <ANetwork.hpp>
# include <RoomManager.hh>
# include <GameManager.hh>
# include <ClientManager.hh>
# include <CommandManager.hpp>

class Server {

public:

  Server();
  ~Server();
  void init();
  void run();
  bool createGame(ANetwork::t_frame frame, void *data);
  bool createRoom(ANetwork::t_frame frame, void *data);

private:

  ANetwork *_network;
  RoomManager _roomManager;
  GameManager _gameManager;
  ClientManager _clientManager;
  CommandManager _commandManager;

};

#endif
