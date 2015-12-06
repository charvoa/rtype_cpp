//
// PlayerFactory.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Tue Dec  1 07:49:08 2015 Louis Audibert
// Last update Thu Dec  3 05:27:23 2015 Louis Audibert
//

#include <PlayerFactory.hh>

PlayerFactory::PlayerFactory()
{

}

PlayerFactory::~PlayerFactory()
{
  std::cout << "Player Factory destroyed" << std::endl;
}

Player	*PlayerFactory::createPlayer(int &id, const Client &client)
{
  std::cout << "New Player created !" << std::endl;
  id += 1;
  return (new Player(id, client));
}
