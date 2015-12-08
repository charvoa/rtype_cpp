//
// RoomPanel.hh for RoomPanel in /home/barnea_v/rendu/rtype_cpp/client/common
//
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
//
// Started on  Mon Nov 30 09:51:46 2015 Viveka BARNEAUD
// Last update Tue Dec  8 01:33:37 2015 Serge Heitzler
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

  void			difficulty(Settings::Difficulty);
  void			start();
  void			back();
  void			render();
  void			update();
  void			setUserInterface();

private:
  // Button  _startButton;
  // Button  _easyButton;
  // Button  _mediumButton;
  // Button  _hardButton;
  // Button  _backButton;
  //std::map<Player*, Component*> _playersList;
};

#endif // ROOMPANEL_H
