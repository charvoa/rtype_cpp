//
// RoomManager.cpp for RoomManager in /home/antoinegarcia/rendu/rtype_cpp/server/Room
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Tue Dec  1 01:37:26 2015 Antoine Garcia
// Last update Tue Dec  1 15:32:00 2015 Nicolas Charvoz
//

#include <cstdlib>
#include <ctime>
#include "RoomManager.hh"

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

void	RoomManager::createNewRoom()
{
  Room	room(generateId());
  _rooms.push_back(room);
}

Room&	RoomManager::getRoombyId(const std::string &id)
{
  for (std::vector<Room>::iterator it = _rooms.begin(); it != _rooms.end(); ++it)
    {
      if((*it).getId() == id)
	return (*it);
    }
  throw new std::exception();
}

bool	RoomManager::roomExists(const std::string &id) const
{
  return (true);
}
