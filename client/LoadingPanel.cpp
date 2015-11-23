#include "LoadingPanel.hh"
#include "SettingsLoader.hh"

LoadingPanel::LoadingPanel(Window *parent) : APanel(parent)
{
    Settings    *settings = new Settings("PersonnalConfig.ini");

    // create InputManager with settings
}

LoadingPanel::~LoadingPanel() {}
