//
// Client.hh for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Dec  1 14:21:37 2015 Nicolas Charvoz
// Last update Tue Dec  1 14:52:11 2015 Nicolas Charvoz
//

#ifndef CLIENT_HH_
# define CLIENT_HH_

# include "ANetwork.hpp"

class Client {

private:

  ANetwork *_network;

  public:

  Client();
  ~Client();
  ANetwork *getNetwork() const;

};

#endif
