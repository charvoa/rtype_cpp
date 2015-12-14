//
// Settings.cpp for Settings in /home/barnea_v/rendu/rtype_cpp/client/common
//
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
//
// Started on  Mon Nov 30 09:50:24 2015 Viveka BARNEAUD
// Last update Thu Dec  3 17:41:52 2015 Nicolas Girardot
//

#include <iostream>
#include "Settings.hh"
#include "SettingsLoader.hh"

Settings::Settings(std::string const& filepath)
{
    SettingsLoader loader(filepath);

    this->update(*loader.parseSettings());
}

Settings::Settings(Volume vol, std::vector<Bind*> binds, Settings::Difficulty difficulty)
{
    _volume = vol;
    _binds = binds;
	_defaultDifficulty = difficulty;
}

Settings::~Settings(){}

void	Settings::update(Settings const& copy)
{
    _volume = copy._volume;
    _binds = copy._binds;
    _defaultDifficulty = copy._defaultDifficulty;
}

Volume  Settings::getVolume() const
{
    return _volume;
}

void	Settings::setVolume(Volume const& vol)
{
	_volume = vol;
}

std::vector<Bind*>   Settings::getBinds() const
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

void	Settings::dumpBinds() const
{
	std::vector<Bind*>::const_iterator it = _binds.begin();
	std::vector<Bind*>::const_iterator end = _binds.end();
	SettingsLoader *loader = new SettingsLoader();

	while (it != end)
	{
		std::cout << loader->bindTypeToString((*it)->getType()) << " : " << loader->keyToString((*it)->getKey()) << ", " << loader->joystickToString((*it)->getJoystick()) << std::endl;
		++it;
	}
}

void    Settings::setBind(Bind *bind)
{
    std::vector<Bind*>::iterator it = _binds.begin();
    std::vector<Bind*>::iterator end = _binds.end();

    while (it != end)
    {
      if (bind->getType() == (*it)->getType())
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

    this->update(*loader.parseSettings());
}

void    Settings::resetDefault()
{
    SettingsLoader  loader("DefaultConfig.ini");

    this->update(*loader.parseSettings());
}
