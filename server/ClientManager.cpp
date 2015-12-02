//
// ClientManager.cpp for ClientManager in /home/antoinegarcia/rendu/rtype_cpp/server
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Wed Dec  2 04:54:25 2015 Antoine Garcia
// Last update Wed Dec  2 05:00:26 2015 Antoine Garcia
//

# include "ClientManager.hh"

ClientManager::ClientManager()
{}

ClientManager::~ClientManager()
{}

bool	ClientManager::clientExists(Client &client)
{
  (void)client;
  return (true);
}

void	ClientManager::addClients(Client &client)
{
  _clients.push_back(client);
}
