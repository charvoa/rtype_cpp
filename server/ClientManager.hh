//
// ClientManager.hh for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Nov 25 16:43:04 2015 Nicolas Charvoz
// Last update Tue Dec  8 01:11:07 2015 Antoine Garcia
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
  int		getClientPosition(Client &);
};

#endif
