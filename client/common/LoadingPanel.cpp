//
// LoadingPanel.cpp for LoadingPanel in /home/barnea_v/rendu/rtype_cpp/client/common
// 
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
// 
// Started on  Mon Nov 30 09:51:31 2015 Viveka BARNEAUD
// Last update Mon Nov 30 09:51:32 2015 Viveka BARNEAUD
//

#include "LoadingPanel.hh"
#include "SettingsLoader.hh"

LoadingPanel::LoadingPanel(RenderWindow *parent) : APanel(parent)
{
    Settings    *settings = new Settings("PersonnalConfig.ini");

    // create InputManager with settings
}

LoadingPanel::~LoadingPanel() {}
