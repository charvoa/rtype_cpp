//
// RoomManager.cpp for RoomManager in /home/antoinegarcia/rendu/rtype_cpp/server/Room
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Tue Dec  1 01:37:26 2015 Antoine Garcia
// Last update Sat Dec 12 06:14:14 2015 Joris Bertomeu
//


# include <CRC.hpp>
# include <CreateRequest.hpp>
# include <ANetwork.hpp>
# include <cstdlib>
# include <ctime>
# include <stdexcept>
# include <algorithm>
# include <random>
# include <RoomManager.hh>
# include <Random.hpp>

RoomManager::RoomManager() : _rooms(0)
{}

RoomManager::~RoomManager()
{}

std::string	RoomManager::generateId()
{
  std::string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  std::string id;
  Random	random(str);
  for (int i = 0; i < 4; i++)
    {

      id += random.generate<char>();
    }
  return id;
}

void	RoomManager::createNewRoom(Client *client)
{
  Room	room(generateId(), client, this->_botManager);
  _rooms.push_back(room);
  std::string	sendData = "player1;" + room.getId() + ";1";
  ANetwork::t_frame frame = CreateRequest::create(S_JOIN_SUCCESS,
						  CRC::calcCRC(sendData),
						  0, sendData);
  client->getSocket()->write(reinterpret_cast<void *>(&frame),
			     sizeof(ANetwork::t_frame));
  std::cout << "Create Room With Id" << room.getId() << std::endl;
}

Room&	RoomManager::getRoombyId(const std::string &id)
{
  // return _rooms.front();
  for (std::vector<Room>::iterator it = _rooms.begin(); it != _rooms.end(); ++it)
    {
      if((*it).getId() == id)
	return (*it);
    }
  throw std::logic_error("No room with this id found");
}

bool	RoomManager::roomExists(const std::string &id)
{
  for (std::vector<Room>::iterator it = _rooms.begin(); it != _rooms.end(); ++it)
    {
      if((*it).getId() == id)
	return (true);
    }
  return (false);
}

void	RoomManager::deleteRoom(const std::string &id)
{
  for (std::vector<Room>::iterator it = _rooms.begin(); it != _rooms.end(); ++it)
    {
      if((*it).getId() == id)
	{
	  std::cout << "DELETE ROOM" << std::endl;
	  _rooms.erase(it);
	  return;
	}
    }
}

void		RoomManager::setBotManager(std::list<Bot*> bots)
{
  this->_botManager = bots;
}
