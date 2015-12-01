//
// PlayerManager.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Tue Dec  1 05:44:36 2015 Louis Audibert
// Last update Tue Dec  1 15:31:30 2015 Nicolas Charvoz
//

#include "PlayerManager.hh"

PlayerManager::PlayerManager()
{
}

PlayerManager::~PlayerManager()
{
  std::cout << "PlayerManager destroyed" << std::endl;
}

bool	PlayerManager::createPlayer(Client &client)
{
  _players.push_back(Player(client));
  return (true);
}

std::vector<Player>	&PlayerManager::getAllPlayers()
{
  return (_players);
}

Player			&PlayerManager::getPlayerById(int id)
{
  for (std::vector<Player>::iterator it = _players.begin();
       it != _players.end(); ++it)
    {
      if (id == (*it).getId())
	return (*it);
    }
  throw new std::exception();
}
