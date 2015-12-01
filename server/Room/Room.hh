//
// Room.hh for Room in /home/antoinegarcia/rendu/rtype_cpp/server/Room
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Mon Nov 30 08:52:59 2015 Antoine Garcia
// Last update Tue Dec  1 08:28:38 2015 Antoine Garcia
//

#ifndef _ROOM_HH_
# define _ROOM_HH_

# include <vector>
# include <string>
# include "../Client.hh"
# include "../ClientManager.hh"

class	Room
{
  std::string	_id;
  ClientManager	_clientManager;
public:
  Room();
  Room(const std::string &id, Client&);
  ~Room();
  const std::string&	getId() const;
};


#endif
