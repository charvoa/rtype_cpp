//
// Client.hh for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Dec  1 14:21:37 2015 Nicolas Charvoz
// Last update Mon Dec  7 01:15:55 2015 Antoine Garcia
//

#ifndef CLIENT_HH_
# define CLIENT_HH_

# include <ISocket.hpp>

class Client {

private:

  ISocket *_socket;

public:
  Client();
  Client(ISocket *);
  ~Client();
  ISocket *getSocket() const;
  bool operator==(const Client&) const;
};

#endif
