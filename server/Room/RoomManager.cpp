//
// RoomManager.cpp for RoomManager in /home/antoinegarcia/rendu/rtype_cpp/server/Room
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Tue Dec  1 01:37:26 2015 Antoine Garcia
// Last update Tue Dec  1 02:06:11 2015 Antoine Garcia
//

#include <cstdlib>
#include <ctime>
#include <string>
#include "RoomManager.hh"

RoomManager::RoomManager()_room(0)
{}

RoomManager::~RoomManager()
{}

std::string&	RoomManager::generateId()
{
  std::string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  std::string id;
  std::srand(std::time(0));
  for (int i = 0; i < 4; i++)
    {
      int	random_variable = std::rand() % str.size() + 1;
      id += str[random_variable];
    }
}

void	RoomManager::createNewRoom()
{
  Room	room(generateId());
  _rooms.push_back(room);
}
