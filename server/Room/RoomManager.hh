//
// RoomManager.hh for RoomManager in /home/antoinegarcia/rendu/rtype_cpp/server/Room
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Mon Nov 30 08:51:49 2015 Antoine Garcia
// Last update Tue Dec  1 05:48:48 2015 Antoine Garcia
//

#ifndef _ROOMMANAGER_HH_
# define _ROOMMANAGER_HH_

# include <string>
# include <vector>
# include "Room.hh"

class	RoomManager
{
  std::vector<Room>	_rooms;
  std::string	generateId();
public:
  RoomManager();
  ~RoomManager();
  void	createNewRoom();
  Room&	getRoombyId(const std::string &id) const;
  bool	roomExists(const std::string &id) const;
};

#endif
