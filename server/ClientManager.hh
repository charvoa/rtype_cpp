//
// ClientManager.hh for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Nov 25 16:43:04 2015 Nicolas Charvoz
// Last update Thu Dec  3 05:10:49 2015 Louis Audibert
//

#ifndef CLIENTMANAGER_HH_
# define CLIENTMANAGER_HH_

# include <vector>
# include <Client.hh>

class ClientManager {
  std::vector<Client>	_clients;
public:
  ClientManager();
  ~ClientManager();
  bool	clientExists(Client &);
  void	addClients(Client &);
  std::vector<Client>&	getAllClients();
  Client&	getClientByFd(int fd);
};

#endif
