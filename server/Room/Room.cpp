//
// Room.cpp for Room in /home/antoinegarcia/rendu/rtype_cpp/server/Room
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Tue Dec  1 05:29:21 2015 Antoine Garcia
// Last update Mon Dec  7 03:02:11 2015 Antoine Garcia
//

#include <Room.hh>

Room::Room() {}

Room::Room(const std::string &id, Client &client):_id(id)
{
  _clientManager.addClients(client);
  _owner = client;
}

Room::~Room()
{}

const std::string &Room::getId() const
{
  return (_id);
}

void	Room::addPlayer(Client &client)
{
  if (this->getAllPlayers < 4)
    {
      _clientManager.addClients(client);
    }
}

std::vector<Client>&	Room::getAllPlayers()
{
  return _clientManager.getAllClients();
}

void	Room::setParameters(Parameters &params)
{
  params = _parameter;
}

const Parameters&	Room::getParameters() const
{
  return _parameter;
}
