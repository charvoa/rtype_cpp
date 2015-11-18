//
// RoomPanel.cpp for RoomPanel in /home/barnea_v/rendu/rtype_cpp/client/common
// 
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
// 
// Started on  Mon Nov 30 09:50:28 2015 Viveka BARNEAUD
// Last update Mon Nov 30 09:50:28 2015 Viveka BARNEAUD
//

#include "RoomPanel.hh"

RoomPanel::RoomPanel(RenderWindow *parent) : APanel(parent)
{
}

RoomPanel::~RoomPanel() {}

void    RoomPanel::difficulty(Settings::Difficulty diff)
{
    _parent->getSettings->setDifficulty(diff);
}

void    RoomPanel::start()
{

}

void    RoomPanel::back()
{

}
