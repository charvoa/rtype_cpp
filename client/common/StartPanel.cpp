//
// StartPanel.cpp for StartPanel in /home/barnea_v/rendu/rtype_cpp/client/common
// 
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
// 
// Started on  Mon Nov 30 09:52:01 2015 Viveka BARNEAUD
// Last update Mon Nov 30 17:26:39 2015 Viveka BARNEAUD
//

#include "PanelFactory.hh"
#include "StartPanel.hh"

StartPanel::StartPanel(RenderWindow *parent) : APanel(parent)
{

}

StartPanel::~StartPanel() {}

void        StartPanel::play()
{
  // _parent->changeDePanel(PLAY_PANEL)
}

void        StartPanel::demo()
{
  // _parent->changeDePanel(DEMO_PANEL)
}

void        StartPanel::exit()
{

}

void        StartPanel::settings()
{
  // _parent->changeDePanel(SETTINGS_PANEL)
}
