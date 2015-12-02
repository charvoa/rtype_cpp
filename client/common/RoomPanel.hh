//
// RoomPanel.hh for RoomPanel in /home/barnea_v/rendu/rtype_cpp/client/common
// 
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
// 
// Started on  Mon Nov 30 09:51:46 2015 Viveka BARNEAUD
// Last update Mon Nov 30 09:58:27 2015 Viveka BARNEAUD
//

#ifndef ROOMPANEL_H
#define ROOMPANEL_H

#include <map>
#include "Button.hh"
#include "Settings.hh"
#include "APanel.hh"

class RoomPanel : public APanel
{
public:
    RoomPanel();
    ~RoomPanel();

    void    difficulty(Settings::Difficulty);
    void    start();
    void    back();

private:
    Button  _startButton;
    Button  _easyButton;
    Button  _mediumButton;
    Button  _hardButton;
    Button  _backButton;
    std::map<Player*, Component*> _playersList;
};

#endif // ROOMPANEL_H
