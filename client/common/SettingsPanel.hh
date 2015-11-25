#ifndef SETTINGSPANEL_H
#define SETTINGSPANEL_H

#include "APanel.hh"
#include "Bind.hh"

class SettingsPanel : public APanel
{
public:
    SettingsPanel(RenderWindow *);
    ~SettingsPanel();

    void    setGlobalVolume(int);
    void    setEffectsVolume(int);
    void    setMusicVolume(int);
    void    setBind(Bind);
    void    defaultSettings();
    void    back();
    void    save();

private:
    Button  _effectsVolume;
    Button  _musicVolume;
    Button  _globalVolume;
    Button  _muteEffectsButton;
    Button  _muteMusicButton;
    Button  _muteGlobalButton;
    Button  _attackKeyButton;
    Button  _weapon1KeyButton;
    Button  _weapon2KeyButton;
    Button  _weapon3KeyButton;
    Button  _weapon1JoystickButton;
    Button  _weapon2JoystickButton;
    Button  _weapon3JoystickButton;
    Button  _moveUpKeyButton;
    Button  _moveDownKeyButton;
    Button  _moveLeftKeyButton;
    Button  _moveRightKeyButton;
    Button  _leaveGameKeyButton;
    Button  _attackJoystickButton;
    Button  _moveUpJoystickButton;
    Button  _moveDownJoystickButton;
    Button  _moveLeftJoystickButton;
    Button  _moveRightJoystickButton;
    Button  _leaveGameJoystickButton;
    Button  _defaultDifficultyButton;
    Button  _defaultSettingsButton;
    Button  _resetButton;
    Button  _backButton;
    Button  _saveButton;
    Settings    *_tmp;
};

#endif // SETTINGSPANEL_H
