//
// Room.cpp for Room in /home/antoinegarcia/rendu/rtype_cpp/server/Room
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Tue Dec  1 05:29:21 2015 Antoine Garcia
// Last update Wed Dec  9 06:53:50 2015 Antoine Garcia
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
      sendData += std::string("player") + std::to_string(i + 1) + ";";
    }
  sendData +=  _id + ";" + "1";
  ANetwork::t_frame frame = CreateRequest::create(S_JOIN_SUCCESS, CRC::calcCRC(sendData), 0, sendData);
  client.getSocket()->write(reinterpret_cast<void *>(&frame), sizeof(ANetwork::t_frame));
}

void	Room::sendRoomPlayerJoin(Client &client)
{
  std::vector<Client>::iterator	it;
  std::vector<Client> clients = getAllPlayers();
  int	clientPos = _clientManager.getClientPosition(client);
  for (it = clients.begin() ; it != clients.end() ; ++it)
    {
      std::string sendData = "player" + std::to_string(clientPos);
      ANetwork::t_frame frame = CreateRequest::create(S_NEW_PLAYER_CONNECTED, CRC::calcCRC(sendData), 0, sendData);
      if ((*it).getSocket()->getFd() != client.getSocket()->getFd())
	(*it).getSocket()->write(reinterpret_cast<void *>(&frame), sizeof(ANetwork::t_frame));
    }
}

void	Room::sendError(Client &client)
{
  std::string sendData = "Too many players";

  ANetwork::t_frame frame = CreateRequest::create(S_JOIN_ERROR, CRC::calcCRC(sendData), 0, sendData);
  client.getSocket()->write(reinterpret_cast<void *>(&frame), sizeof(ANetwork::t_frame));
}

void	Room::addPlayer(Client &client)
{
  if (this->getAllPlayers().size() < 4)
    {
      _clientManager.addClients(client);
      sendPlayerJoin(client);
      sendRoomPlayerJoin(client);
    }
  else
    sendError(client);
}

void	Room::sendPlayerLeft(int playerID)
{
  std::vector<Client>::iterator	it;
  std::vector<Client>	clients = getAllPlayers();
  for (it = clients.begin(); it != clients.end(); ++it)
    {
      std::string sendData = "player" + std::to_string(playerID);
      sendData += ";player" + std::to_string(_clientManager.getClientPosition(*it));
      ANetwork::t_frame frame = CreateRequest::create(S_PLAYER_LEFT, CRC::calcCRC(sendData), 0, sendData);
      (*it).getSocket()->write(reinterpret_cast<void *>(&frame), sizeof(ANetwork::t_frame));
    }
}

void	Room::deletePlayer(Client &client)
{
  int playerID = _clientManager.getClientPosition(client);
  _clientManager.deleteClient(client);
  sendPlayerLeft(playerID);
}

const std::vector<Client>&	Room::getAllPlayers() const
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
