//
// RoomManager.hh for RoomManager in /home/antoinegarcia/rendu/rtype_cpp/server/Room
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Mon Nov 30 08:51:49 2015 Antoine Garcia
// Last update Thu Dec  3 05:29:06 2015 Louis Audibert
//

#ifndef _ROOMMANAGER_HH_
# define _ROOMMANAGER_HH_

# include <string>
# include <vector>
# include <Room.hh>
# include <Client.hh>

class	RoomManager
{
  std::vector<Room>	_rooms;
  std::string	generateId();
public:
  RoomManager();
  ~RoomManager();
  void	createNewRoom(Client&);
  Room&	getRoombyId(const std::string &id);
  bool	roomExists(const std::string &id);
  void	deleteRoom(const std::string &id);
};

#endif
