//
// Room.cpp for Room in /home/antoinegarcia/rendu/rtype_cpp/server/Room
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Tue Dec  1 05:29:21 2015 Antoine Garcia
// Last update Sat Dec 12 13:44:17 2015 Joris Bertomeu
//

#include <Room.hh>
#include <sstream>

Room::Room() {}

std::string		IntToString(int a)
{
  std::ostringstream	temp;
  temp << a;
  return (temp.str());
}

Room::Room(const std::string &id, Client *client, std::list<Bot*> botList):_id(id)
{
  _clientManager = new ClientManager();
  _clientManager->addClients(client);
  this->_botList = botList;
  sendFileToClient(client, botList);
  //_owner = client;
}

void			Room::sendFileToClient(Client *client, std::list<Bot*> list) {
  std::ostringstream	tmp;
  int			port = Random(6000, 7000).generate<int>();
  int			first = true;

  tmp << list.size();
  for (std::list<Bot*>::iterator it = list.begin(); it != list.end(); ++it) {
    std::cout << ">> " << (*it)->_sprite << std::endl;
    File	file(std::string("../libs/" + (*it)->_sprite));
    if (first) {
      client->getSocket()->write((void*) CreateRequest::create(S_FILE_TOTAL_SIZE, CRC::calcCRC(std::string(IntToString(port)  + ";" + tmp.str())), std::string(IntToString(port) + ";" + tmp.str()).size(), std::string(IntToString(port)  + ";" + tmp.str()), true), sizeof(ANetwork::t_frame));
      first = false;
    }
    file.sendMe(port++);
  }

}

Room::~Room()
{}

const std::string &Room::getId() const
{
  return (_id);
}

void	Room::sendPlayerJoin(Client *client)
{
  std::string sendData;
  for (unsigned int i = 0; i < getAllPlayers().size(); i++)
    {
      sendData += std::string("player") + std::to_string(i + 1) + ";";
    }
  sendData +=  _id + ";" + "1";
  ANetwork::t_frame frame = CreateRequest::create(S_JOIN_SUCCESS, CRC::calcCRC(sendData), 0, sendData);
  client->getSocket()->write(reinterpret_cast<void *>(&frame), sizeof(ANetwork::t_frame));
}

void	Room::sendRoomPlayerJoin(Client *client)
{
  std::vector<Client *>::iterator	it;
  std::vector<Client *> clients = getAllPlayers();
  int	clientPos = _clientManager->getClientPosition(client) + 1;
  for (it = clients.begin(); it != clients.end(); ++it)
    {
      std::string sendData = "player" + std::to_string(clientPos);
      ANetwork::t_frame frame = CreateRequest::create(S_NEW_PLAYER_CONNECTED, CRC::calcCRC(sendData), 0, sendData);
      if ((*it)->getSocket()->getFd() != client->getSocket()->getFd())
	{
	  int test = (*it)->getSocket()->write(reinterpret_cast<void *>(&frame), sizeof(ANetwork::t_frame));
	  std::cout << "I WROTE " << test << "to FD" << (*it)->getSocket()->getFd() << std::endl;
	}
    }
}

void	Room::sendError(Client *client)
{
  std::string sendData = "Too many players";

  ANetwork::t_frame frame = CreateRequest::create(S_JOIN_ERROR, CRC::calcCRC(sendData), 0, sendData);
  client->getSocket()->write(reinterpret_cast<void *>(&frame), sizeof(ANetwork::t_frame));
}

void	Room::addPlayer(Client *client)
{
  if (this->getAllPlayers().size() < 4)
    {
      _clientManager->addClients(client);
      sendPlayerJoin(client);
      sendRoomPlayerJoin(client);
      sendFileToClient(client, this->_botList);
    }
  else
    sendError(client);
  for (std::vector<Client *>::const_iterator it = getAllPlayers().begin(); it != getAllPlayers().end(); ++it)
    {
      std::cout << (*it)->getSocket()->getFd() << std::endl;
    }
}

void	Room::sendPlayerLeft(int playerID)
{
  std::vector<Client *>::iterator	it;
  std::vector<Client *>	clients = getAllPlayers();

  for (it = clients.begin(); it != clients.end(); ++it)
    {
      std::string sendData = "player" + std::to_string(playerID);
      sendData += ";player" + std::to_string(_clientManager->getClientPosition(*it) + 1);
      ANetwork::t_frame frame = CreateRequest::create(S_PLAYER_LEFT, CRC::calcCRC(sendData), 0, sendData);
      (*it)->getSocket()->write(reinterpret_cast<void *>(&frame), sizeof(ANetwork::t_frame));
    }
}

void	Room::deletePlayer(Client *client)
{
  int playerID = _clientManager->getClientPosition(client) + 1;
  _clientManager->deleteClient(client);
   sendPlayerLeft(playerID);
}

std::vector<Client *>&	Room::getAllPlayers()
{
  return _clientManager->getAllClients();
}

void	Room::setParameters(Parameters &params)
{
  _parameter = params;
}

const Parameters&	Room::getParameters() const
{
  return _parameter;
}
