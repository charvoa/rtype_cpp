//
// SettingsPanel.cpp for SettingsPanel in /home/barnea_v/rendu/rtype_cpp/client/common
// 
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
// 
// Started on  Mon Nov 30 09:50:13 2015 Viveka BARNEAUD
// Last update Thu Dec  3 14:01:46 2015 Serge Heitzler
//

#include "RenderWindow.hh"
#include "PanelFactory.hh"
#include "SettingsPanel.hh"

SettingsPanel::SettingsPanel()
{
    _tmp = new Settings(*(RenderWindow::getInstance())->getSettings());
}

SettingsPanel::~SettingsPanel()
{
    delete _tmp;
}

void	SettingsPanel::setUserInterface()
{
	RenderWindow *window = RenderWindow::getInstance();
	getInputManager().setInputType(InputType::SETTINGS_INPUT);
	(void)window;
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
	(RenderWindow::getInstance())->back();
}

void    SettingsPanel::save()
{
	(RenderWindow::getInstance())->setSettings(_tmp);
}
