//
// Client.hh for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Dec  1 14:21:37 2015 Nicolas Charvoz
// Last update Thu Dec  3 05:08:39 2015 Louis Audibert
//

#ifndef CLIENT_HH_
# define CLIENT_HH_

# include <ISocket.hpp>

class Client {

private:

  ISocket *_socket;

public:
  Client();
  ~Client();
  ISocket *getSocket() const;
};

#endif
