//
// RoomPanel.hh for RoomPanel in /home/barnea_v/rendu/rtype_cpp/client/common
//
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
//
// Started on  Mon Nov 30 09:51:46 2015 Viveka BARNEAUD
// Last update Tue Dec  8 08:18:11 2015 Serge Heitzler
//

#ifndef ROOMPANEL_H
#define ROOMPANEL_H

#include <map>
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
  void			start();
  void			back();
  void			update();
  void			setUserInterface();
  void			updatePlayers(std::vector<std::string> &vector, int from);

private:

  std::vector<Player*> _players;
  
};

#endif // ROOMPANEL_H
