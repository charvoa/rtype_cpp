//
// RoomPanel.hh for RoomPanel in /home/barnea_v/rendu/rtype_cpp/client/common
//
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
//
// Started on  Mon Nov 30 09:51:46 2015 Viveka BARNEAUD
// Last update Thu Dec 10 02:14:43 2015 Serge Heitzler
//

#ifndef ROOMPANEL_H
#define ROOMPANEL_H

#include <map>
#include <string>
#include <Button.hh>
#include <Settings.hh>
#include <APanel.hh>
#include <Player.hh>

class RoomPanel : public APanel
{
public:
  
  RoomPanel();
  ~RoomPanel();

  void			difficulty(Settings::Difficulty);
  static void  		playerLeft(std::vector<std::string> &vector);
  static void  		newPlayer(std::string &newUsername);
  void			launchGame();
  void			back();
  void			update();
  void			setUserInterface();
  void			updatePlayers(std::vector<std::string> &vector, int from);
  void			createPlayers();
  std::vector<Player*>	&getPlayers();
  unsigned int		getNbPlayers();
  void			minusNbPlayers();
  void			addNbPlayers();

  
private:

  std::vector<Player*> _players;
  std::string		_idRoom;
  std::vector<Texture*>	_spaceShipsTextures;
  unsigned int		_nbPlayers;
};

#endif /* !ROOMPANEL_HH_ */
