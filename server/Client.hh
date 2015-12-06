//
// Client.hh for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Dec  1 14:21:37 2015 Nicolas Charvoz
// Last update Sat Dec  5 16:08:35 2015 Nicolas Charvoz
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
  bool operator==(const Client&) const;
};

#endif
