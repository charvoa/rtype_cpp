//
// RoomPanel.hh for RoomPanel in /home/barnea_v/rendu/rtype_cpp/client/common
//
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
//
// Started on  Mon Nov 30 09:51:46 2015 Viveka BARNEAUD
// Last update Thu Dec  3 16:38:02 2015 Nicolas Girardot
//

#ifndef ROOMPANEL_H
#define ROOMPANEL_H

#include <map>
#include "Button.hh"
#include "Settings.hh"
#include "APanel.hh"
//#include "Player.hh"

class RoomPanel : public APanel
{
public:
  RoomPanel();
  ~RoomPanel();

  void    difficulty(Settings::Difficulty);
  void    start();
  void    back();
  void	render();

private:
  Button  _startButton;
  Button  _easyButton;
  Button  _mediumButton;
  Button  _hardButton;
  Button  _backButton;
  //std::map<Player*, Component*> _playersList;
};

#endif // ROOMPANEL_H
