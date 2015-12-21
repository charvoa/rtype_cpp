//
// PlayerFactory.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Tue Dec  1 07:49:08 2015 Louis Audibert
// Last update Mon Dec 21 01:29:17 2015 Louis Audibert
//

#include <PlayerFactory.hh>

PlayerFactory::PlayerFactory()
{

}

PlayerFactory::~PlayerFactory()
{
}

Player	*PlayerFactory::createPlayer(int &id, const Client &client)
{
  id += 1;
  return (new Player(id, client));
}
