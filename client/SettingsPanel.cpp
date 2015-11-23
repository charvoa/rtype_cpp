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

}

void    SettingsPanel::save()
{
    _parent->setSettings(_tmp);
}
