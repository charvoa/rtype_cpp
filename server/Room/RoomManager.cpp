//
// RoomManager.cpp for RoomManager in /home/antoinegarcia/rendu/rtype_cpp/server/Room
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Tue Dec  1 01:37:26 2015 Antoine Garcia
// Last update Wed Dec 23 01:42:08 2015 Joris Bertomeu
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
  std::cout << "Create Room With Id" << room.getId() << std::endl;
}

Room&	RoomManager::getRoombyId(const std::string &id)
{
  // return _rooms.front();
  for (std::list<Room>::iterator it = _rooms.begin(); it != _rooms.end(); ++it)
    {
      if((*it).getId() == id)
	return (*it);
    }
  throw std::logic_error("No room with this id found");
}

Room&	RoomManager::getRoomByClient(Client *c)
{
  for (std::list<Room>::iterator it = _rooms.begin();
       it != _rooms.end();
       ++it)
    {
      std::list<Client*> myList = (*it).getAllPlayers();
      for (std::list<Client*>::iterator it2 = myList.begin();
	   it2 != myList.end();
	   it2++)
	{
	  if ((*it2)->getSocket()->getFd() == c->getSocket()->getFd())
	    return (*it);
	}
    }
  throw std::logic_error("Room with this client not found");
}

bool	RoomManager::roomExists(const std::string &id)
{
  for (std::list<Room>::iterator it = _rooms.begin(); it != _rooms.end(); ++it)
    {
      if((*it).getId() == id)
	return (true);
    }
  return (false);
}

void	RoomManager::deleteRoom(const std::string &id)
{
  for (std::list<Room>::iterator it = _rooms.begin(); it != _rooms.end(); ++it)
    {
      if((*it).getId() == id)
	{
	  std::cout << "RoomManager :: DeleteRoom \"" << id << "\"" << std::endl;
	  _rooms.erase(it);
	  return;
	}
    }
}

void		RoomManager::setBotManager(std::list<Bot*> bots)
{
  this->_botManager = bots;
}
