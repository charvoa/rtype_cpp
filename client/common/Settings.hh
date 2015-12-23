//
// Settings.hh for Settings in /home/barnea_v/rendu/rtype_cpp/client/common
//
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
//
// Started on  Mon Nov 30 09:51:49 2015 Viveka BARNEAUD
// Last update Sun Dec 27 08:06:26 2015 Serge Heitzler
//

#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>
#include <vector>
#include <Bind.hh>
#include <Volume.hh>

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
    Settings(Volume, std::vector<Bind*>, Settings::Difficulty);
Settings(Volume, std::vector<Bind*>, Settings::Difficulty, std::string const&, int);
    ~Settings();

    Volume getVolume() const;
    std::vector<Bind*> getBinds() const;
    Settings::Difficulty getDefaultDifficulty() const;
    Settings::Difficulty getCurrentDifficulty() const;
	std::string		getIP() const;
	int			getPort() const;

    void update(Settings const&);
    void setVolume(Volume const&);
    void setBind(Bind*);
	void setKey(Bind::BindType, sf::Keyboard::Key);
	void setJoystick(Bind::BindType, JoystickEvent&);
    void setDefaultDifficulty(Settings::Difficulty);
    void setDifficulty(Settings::Difficulty);
	void setIP(std::string const&);
	void setPort(int);

	void dumpBinds() const;
    void loadSettings();
    void resetDefault();
    void save() const;

private:
    std::vector<Bind*> _binds;
    Volume  _volume;
    Settings::Difficulty _defaultDifficulty;
    Settings::Difficulty _difficulty;
	std::string	_ip;
	int			_port;
};

#endif /* !SETTINGS_HH */
