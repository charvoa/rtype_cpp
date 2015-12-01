//
// SettingsPanel.cpp for SettingsPanel in /home/barnea_v/rendu/rtype_cpp/client/common
// 
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
// 
// Started on  Mon Nov 30 09:50:13 2015 Viveka BARNEAUD
// Last update Mon Nov 30 17:25:54 2015 Viveka BARNEAUD
//

#include "PanelFactory.hh"
#include "SettingsPanel.hh"

SettingsPanel::SettingsPanel(RenderWindow *parent) : APanel(parent)
{
    _tmp = new Settings(parent->getSettings());
}

SettingsPanel::~SettingsPanel()
{
    delete _tmp;
}

void    SettingsPanel::setGlobalVolume(int global)
{
    Volume vol = _tmp->getVolume();

    vol.setGlobal(global);
    _tmp->setVolume(vol);
}

void    SettingsPanel::setEffectsVolume(int effects)
{
    Volume vol = _tmp->getVolume();

    vol.setEffects(effects);
    _tmp->setVolume(vol);
}

void    SettingsPanel::setMusicVolume(int music)
{
    Volume vol = _tmp->getVolume();

    vol.setMusic(music);
    _tmp->setVolume(vol);
}

void    SettingsPanel::setBind(Bind bind)
{
    _tmp->setBind(bind);
}

void    SettingsPanel::defaultSettings()
{
    _tmp->resetDefault();
}

void    SettingsPanel::back()
{
    _parent->back();
}

void    SettingsPanel::save()
{
    _parent->setSettings(_tmp);
}
