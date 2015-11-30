//
// Settings.hh for Settings in /home/barnea_v/rendu/rtype_cpp/client/common
// 
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
// 
// Started on  Mon Nov 30 09:51:49 2015 Viveka BARNEAUD
// Last update Mon Nov 30 09:51:50 2015 Viveka BARNEAUD
//

#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>
#include <vector>
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
    Settings(Settings const&);
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
    void save() const;

private:
    std::vector<Bind> _binds;
    Volume  _volume;
    Settings::Difficulty _defaultDifficulty;
    Settings::Difficulty _difficulty;
};

#endif // SETTINGS_H
