//
// SettingsPanel.hh for SettingsPanel in /home/barnea_v/rendu/rtype_cpp/client/common
// 
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
// 
// Started on  Mon Nov 30 09:51:58 2015 Viveka BARNEAUD
// Last update Thu Dec  3 14:00:33 2015 Serge Heitzler
//

#ifndef SETTINGSPANEL_H
#define SETTINGSPANEL_H

#include "Slider.hh"
#include "Volume.hh"
#include "Settings.hh"
#include "APanel.hh"
#include "Bind.hh"
#include "Button.hh"

class SettingsPanel : public APanel
{
public:
  SettingsPanel();
  ~SettingsPanel();

  void	  setUserInterface();
  void    setGlobalVolume(int);
  void    setEffectsVolume(int);
  void    setMusicVolume(int);
  void    setBind(Bind);
  void    defaultSettings();
  void    back();
  void    save();

private:
    Settings    *_tmp;
	Slider		*_global;
	Slider		*_effects;
	Slider		*_music;
};

#endif // SETTINGSPANEL_H
