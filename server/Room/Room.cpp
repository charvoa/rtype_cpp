//
// Room.cpp for Room in /home/antoinegarcia/rendu/rtype_cpp/server/Room
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Tue Dec  1 05:29:21 2015 Antoine Garcia
// Last update Wed Dec  2 04:36:35 2015 Antoine Garcia
//

#include "Room.hh"

Room::Room() {}

Room::Room(const std::string &id, Client &client):_id(id)
{
  (void)client;
}

Room::~Room()
{}

const std::string &Room::getId() const
{
  return (_id);
}

void	Room::addPlayer(Client &client)
{
  (void)client;
}
