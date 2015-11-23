#ifndef SETTINGS_H
#define SETTINGS_H

#include "Bind.hh"
#include "Volume.hh"

class Settings
{
public:
    typedef enum e_difficulty
    {
        EASY_MODE,
        MEDIUM_MODE,
        HARD_MODE
    } Difficulty;

    Settings(std::string const& filepath);
    Settings(Volume, std::vector<Bind>, Settings::Difficulty);
    Settings(Settings const&)
    ~Settings();

    Volume getVolume() const;
    std::vector<Bind> getBinds() const;
    Settings::Difficulty getDefaultDifficulty() const;
    Settings::Difficulty getCurrentDifficulty() const;

    void setVolume(Volume);
    void setBind(Bind);
    void setDefaultDifficulty(Settings::Difficulty);
    void setDifficulty(Settings::Difficulty);

    void loadSettings();
    void resetDefault();

private:
    std::vector<Bind> _binds;
    Volume  _volume;
    Settings::Difficulty _defaultDifficulty;
    Settings::Difficulty _difficulty;
};

#endif // SETTINGS_H
