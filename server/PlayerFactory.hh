//
// PlayerFactory.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Tue Dec  1 07:49:14 2015 Louis Audibert
// Last update Thu Dec  3 05:27:18 2015 Louis Audibert
//

#ifndef _PLAYERFACTORY_HH_
# define _PLAYERFACTORY_HH_

# include <iostream>
# include <Client.hh>
# include <Player.hh>

class PlayerFactory
{

public:
  PlayerFactory();
  ~PlayerFactory();

  Player	*createPlayer(int &id, const Client &client);
};

#endif /* _PLAYERFACTORY_HH_ */
