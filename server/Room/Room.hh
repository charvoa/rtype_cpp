//
// Room.hh for Room in /home/antoinegarcia/rendu/rtype_cpp/server/Room
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Mon Nov 30 08:52:59 2015 Antoine Garcia
// Last update Tue Dec  1 05:31:48 2015 Antoine Garcia
//

#ifndef _ROOM_HH_
# define _ROOM_HH_

#include <string>

class	Room
{
  std::string	_id;
public:
  Room(const std::string &id);
  ~Room();
  std::string&	getId() const;
};


#endif
