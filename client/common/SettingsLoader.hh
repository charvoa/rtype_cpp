#ifndef SETTINGSLOADER_HH
#define SETTINGSLOADER_HH

#include "IParser.hh"
#include "Settings.hh"

class SettingsLoader : public IParser
{
public:
    SettingsLoader(std::string const& filepath);
    ~SettingsLoader();

    std::string getValueOf(std::string const&) const;
    void        setValueOf(std::string const&, std::string const&) const;

    Settings    *parseSettings() const;
    Volume      getVolume() const;
    int         getGlobalVolume() const;
    int         getEffectsVolume() const;
    int         getMusicVolume() const;
    std::vector<Bind>   getBinds() const;
    Settings::Difficulty    getDefaultDifficulty() const;

    void    saveSettings(Settings *) const;

    int     stringToInteger(std::string const&) const;
    sf::Event::key  stringToKey(std::string const&) const;
    sf::Event::joystick stringToJoystick(std::string const&) const;

    std::string keyToString(sf::Event::key) const;
    std::string joystickToString(sf::Event::Joystick) const;
    std::string bindTypeToString(Bind::BindType) const;

private:
    const std::string _filepath;
    bool    _fileExists;
    std::ifstream   *_ifs;
    std::ofstream   *_ofs;
};

#endif // SETTINGSLOADER_HH
