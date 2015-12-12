//
// Client.hh for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Dec  1 14:21:37 2015 Nicolas Charvoz
// Last update Sat Dec 12 16:31:06 2015 Nicolas Charvoz
//

#ifndef CLIENT_HH_
# define CLIENT_HH_

# include <ISocket.hpp>

class Client {

private:

  ISocket *_socket;
  ISocket *_socketUDP;

public:
  Client();
  Client(ISocket *);
  ~Client();
  ISocket *getSocket() const;
  ISocket *getUDPSocket() const;
  void setUDPSocket(ISocket*);
  bool operator==(const Client&) const;
  bool operator !=(const Client &) const;
};

#endif
