//
// Player.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Tue Dec  8 02:14:08 2015 Serge Heitzler
// Last update Tue Dec  8 08:19:59 2015 Serge Heitzler
//

#ifndef PLAYER_HH_
#define PLAYER_HH_

#include <iostream>

class Player
{
public:
  
  Player();
  ~Player();
  void		        setUsername(std::string &username);
  void			setCurrentClient(bool is);
  void			setReadyToStart(bool is);
  std::string		&getUsername();
  bool			getCurrentClient();
  bool			getReadyToStart();

private:

  std::string		_username;
  bool			_isCurrentClient;
  bool			_isReadyToStart;

};

#endif /* PLAYER_HH_ */
