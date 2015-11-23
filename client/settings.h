#ifndef SETTINGS_H
#define SETTINGS_H

class Settings
{
public:
    Settings();
    ~Settings();

    Volume getVolume() const;
    Bind getBinds() const;
    int getDefaultDifficulty() const;
    int getCurrentDifficulty() const;

    void setVolume(int, int, int);
    void setVolume(Volume);
    void setBind(Bind);
    void setDefaultDifficulty(int);
    void setDifficulty(int);

    void loadSettings();
    void resetDefault();

    class SettingsLoader : public IParser
    {

    };

private:
    std::vector<Bind> _binds;
    Volume  _volume;
    int _defaultDifficulty;
    int _difficulty;
    Settings *_defaultSettings;

};

#endif // SETTINGS_H
