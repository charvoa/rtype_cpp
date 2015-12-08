//
// Room.cpp for Room in /home/antoinegarcia/rendu/rtype_cpp/server/Room
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Tue Dec  1 05:29:21 2015 Antoine Garcia
// Last update Tue Dec  8 02:08:24 2015 Antoine Garcia
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

void	Room::sendPlayerJoin(Client &client)
{
  std::string sendData;
  for (unsigned int i = 0; i < getAllPlayers().size(); i++)
    {
      sendData += std::string("player") + std::to_string(i) + ";" + _id + ";" + "1;";
    }
  ANetwork::t_frame frame = CreateRequest::create((unsigned char)101, CRC::calcCRC(sendData), 0, sendData);
  client.getSocket()->write(reinterpret_cast<void *>(&frame), sizeof(ANetwork::t_frame));
}

void	Room::addPlayer(Client &client)
{
  if (this->getAllPlayers().size() < 4)
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
