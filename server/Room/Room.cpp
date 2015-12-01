//
// Room.cpp for Room in /home/antoinegarcia/rendu/rtype_cpp/server/Room
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Tue Dec  1 05:29:21 2015 Antoine Garcia
// Last update Tue Dec  1 15:00:39 2015 Nicolas Charvoz
//

#include "Room.hh"

Room::Room() {}

Room::Room(const std::string &id):_id(id)
{}

Room::~Room()
{}

const std::string &Room::getId() const
{
  return (_id);
}
