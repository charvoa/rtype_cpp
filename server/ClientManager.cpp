//
// ClientManager.cpp for ClientManager in /home/antoinegarcia/rendu/rtype_cpp/server
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Wed Dec  2 04:54:25 2015 Antoine Garcia
// Last update Thu Dec 10 03:19:19 2015 Antoine Garcia
//

# include <iostream>
# include <algorithm>
# include <iterator>
# include <stdexcept>
# include <ClientManager.hh>

ClientManager::ClientManager()
{}

ClientManager::~ClientManager()
{}

bool	ClientManager::clientExists(Client *client)
{
  (void)client;
  return (true);
}

void	ClientManager::addClients(Client *client)
{
  _clients.push_back(client);
}

void	ClientManager::deleteClient(Client *client)
{
  for (std::vector<Client *>::iterator it = _clients.begin(); it != _clients.end(); ++it)
    {
      if (*(*it) == *client)
	{
	  it = _clients.erase(it);
	  return;
	}
    }
}

std::vector<Client*>&	ClientManager::getAllClients()
{
  return (_clients);
}

Client*		ClientManager::getClientByFd(int fd)
{
  for(std::vector<Client*>::iterator it = _clients.begin(); it != _clients.end();++it)
    {
      if ((*it)->getSocket()->getFd() == fd)
	return (*it);
    }
throw std::logic_error("No client with this fd found");
}

int		ClientManager::getClientPosition(Client *client)
{
  std::vector<Client *>::iterator	it;
  int	i = 0;
  for (it = _clients.begin(); it != _clients.end(); ++it)
    {
      if (*(*it) == client)
	return i;
      i++;
    }
  return 0;
}
