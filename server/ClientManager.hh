//
// ClientManager.hh for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Nov 25 16:43:04 2015 Nicolas Charvoz
// Last update Wed Dec  9 12:01:57 2015 Antoine Garcia
//

#ifndef CLIENTMANAGER_HH_
# define CLIENTMANAGER_HH_

# include <list>
# include <Client.hh>

class ClientManager {
  std::list<Client *>	_clients;
public:
  ClientManager();
  ~ClientManager();
  bool	clientExists(Client *);
  void	addClients(Client *);
  void	deleteClient(Client *);
  std::list<Client *>&	getAllClients();
  Client	*getClientByFd(int fd);
  int		getClientPosition(Client *);
};

#endif
