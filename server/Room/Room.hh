//
// Room.hh for Room in /home/antoinegarcia/rendu/rtype_cpp/server/Room
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Mon Nov 30 08:52:59 2015 Antoine Garcia
// Last update Tue Dec  1 15:00:53 2015 Nicolas Charvoz
//

#ifndef _ROOM_HH_
# define _ROOM_HH_

#include <string>

class	Room
{
  std::string	_id;
public:
  Room();
  Room(const std::string &id);
  ~Room();
  const std::string&	getId() const;
};


#endif
