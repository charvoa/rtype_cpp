//
// PlayerManager.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Tue Dec  1 05:44:31 2015 Louis Audibert
// Last update Tue Dec  1 15:37:57 2015 Nicolas Charvoz
//

#ifndef _PLAYERMANAGER_HH_
# define _PLAYERMANAGER_HH_

# include "Client.hh"
# include "Player.hh"
# include <vector>
# include <stdexcept>

class PlayerManager
{
private:
  std::vector<Player>	_players;

public:
  PlayerManager();
  ~PlayerManager();

  bool			createPlayer(Client &client);
  std::vector<Player>	&getAllPlayers();
  Player		&getPlayerById(int  id);
};

#endif /* _PLAYERMANAGER_HH_ */
