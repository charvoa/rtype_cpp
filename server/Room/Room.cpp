//
// Room.cpp for Room in /home/antoinegarcia/rendu/rtype_cpp/server/Room
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Tue Dec  1 05:29:21 2015 Antoine Garcia
// Last update Tue Dec  1 05:32:12 2015 Antoine Garcia
//

#include "Room.hh"

Room::Room(const std::string &id):_id(id)
{}

Room::~Room();
{}

std::string&	Room::getId() const
{
  return (_id);
}
