//
// RoomPanel.hh for RoomPanel in /home/barnea_v/rendu/rtype_cpp/client/common
//
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
//
// Started on  Mon Nov 30 09:51:46 2015 Viveka BARNEAUD
// Last update Wed Dec  9 06:17:51 2015 Serge Heitzler
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
  static void			playerLeft(std::vector<std::string> &vector);
  static void  		newPlayer(std::string &newUsername);
  void			launchGame();
  void			back();
  void			update();
  void			setUserInterface();
  void			updatePlayers(std::vector<std::string> &vector, int from);
  std::vector<Player*>	&getPlayers();
  
private:

  std::vector<Player*> _players;
  std::string		_idRoom;
};

#endif /* !ROOMPANEL_HH_ */
