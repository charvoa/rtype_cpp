//
// LoadingPanel.cpp for LoadingPanel in /home/barnea_v/rendu/rtype_cpp/client/common
//
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
//
// Started on  Mon Nov 30 09:51:31 2015 Viveka BARNEAUD
// Last update Thu Dec  3 16:00:58 2015 Nicolas Girardot
//

#include "LoadingPanel.hh"
#include "SettingsLoader.hh"

LoadingPanel::LoadingPanel() : APanel()
{
    Settings    *settings = new Settings("PersonnalConfig.ini");

    (void) settings;
    // create InputManager with settings
}

LoadingPanel::~LoadingPanel() {}

void		LoadingPanel::render()
{

}
