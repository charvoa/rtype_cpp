#include "Settings.hh"
#include "SettingsLoader.hh"

Settings::Settings(std::string const& filepath)
{
    SettingsLoader loader(filepath);

    this = loader.parseSettings();
}

Settings::Settings(Volume vol, std::vector<Bind> binds, Settings::Difficulty difficulty)
{
    _volume = vol;
    _binds = binds;
    _defaultDifficulty = difficulty;
}

Settings::Settings(Settings const& copy)
{
    _volume = copy._volume;
    _binds = copy._binds;
    _defaultDifficulty = copy._defaultDifficulty;
}

Settings::~Settings(){}

Volume  Settings::getVolume() const
{
    return _volume;
}

std::vector<Bind>   Settings::getBinds() const
{
    return _binds;
}

Settings::Difficulty    Settings::getDefaultDifficulty() const
{
    return _defaultDifficulty;
}

Settings::Difficulty    Settings::getCurrentDifficulty() const
{
    return _difficulty;
}

void    Settings::setBind(Bind bind)
{
    std::vector<Bind>::iterator it = _binds.begin();
    std::vector<Bind>::iterator end = _binds.end();

    while (it != end)
    {
        if (bind.getType() == (*it)->getType())
        {
            *it = bind;
            return;
        }
        it++;
    }
}

void    Settings::save() const
{
}

void    Settings::setDefaultDifficulty(Settings::Difficulty diff)
{
    _defaultDifficulty = diff;
}

void    Settings::setDifficulty(Settings::Difficulty diff)
{
    _difficulty = diff;
}

void    Settings::loadSettings()
{
    SettingsLoader  loader("PersonnalConfig.ini");

    this = loader.parseSettings();
}

void    Settings::resetDefault()
{
    SettingsLoader  loader("DefaultConfig.ini");

    this = loader.parseSettings();
}
