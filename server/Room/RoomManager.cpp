//
// RoomManager.cpp for RoomManager in /home/antoinegarcia/rendu/rtype_cpp/server/Room
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Tue Dec  1 01:37:26 2015 Antoine Garcia
// Last update Wed Dec  2 06:22:07 2015 Antoine Garcia
//

# include <cstdlib>
# include <ctime>
# include <stdexcept>
# include "RoomManager.hh"

RoomManager::RoomManager() : _rooms(0)
{}

RoomManager::~RoomManager()
{}

std::string	RoomManager::generateId()
{
  std::string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  std::string id;
  std::srand(std::time(0));
  for (int i = 0; i < 4; i++)
    {
      int	random_variable = std::rand() % str.size() + 1;
      id += str[random_variable];
    }
  return id;
}

void	RoomManager::createNewRoom(Client &client)
{
  Room	room(generateId(), client);
  _rooms.push_back(room);
}

Room&	RoomManager::getRoombyId(const std::string &id)
{
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
	  _rooms.erase(it);
	  return;
	}
    }
}
