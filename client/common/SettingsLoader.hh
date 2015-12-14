//
// SettingsLoader.hh for SettingsLoader in /home/barnea_v/rendu/rtype_cpp/client/common
//
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
//
// Started on  Mon Nov 30 09:51:54 2015 Viveka BARNEAUD
// Last update Thu Dec  3 16:47:07 2015 Nicolas Girardot
//

#ifndef SETTINGSLOADER_HH
#define SETTINGSLOADER_HH

#include <fstream>
#include <SFML/Graphics.hpp>
#include "IParser.hh"
#include "Settings.hh"

class SettingsLoader : public IParser
{
public:
	SettingsLoader();
  SettingsLoader(const std::string & filepath);
  ~SettingsLoader();

  std::string getValueOf(const std::string &) const;
  std::string getValueOfKey(const std::string &) const;
  std::string getValueOfJoystick(const std::string &) const;

  std::string removeSpaces(std::string const&) const;

  Settings    *parseSettings() const;
  Volume      getVolume() const;
  int         getGlobalVolume() const;
  int         getEffectsVolume() const;
  int         getMusicVolume() const;
  std::vector<std::string>	getKeys() const;
  std::vector<std::string>	getJoysticks() const;
  std::vector<Bind>   getBinds() const;

  Settings::Difficulty    getDefaultDifficulty() const;
  std::vector<Bind>		createDefaultBinds() const;

  void    saveSettings(Settings *) const;

  int     stringToInteger(std::string const&) const;
  sf::Keyboard::Key	stringToKey(std::string const&) const;
  JoystickEvent	stringToJoystick(std::string const&) const;

  bool	keyExists(std::string const&) const;
  bool	axisExists(std::string const&) const;
  bool	joystickIsEqual(JoystickEvent const&, JoystickEvent const&) const;

  std::string keyToString(sf::Keyboard::Key) const;
  std::string joystickToString(JoystickEvent) const;
  std::string bindTypeToString(Bind::BindType) const;
  std::string bindToString(Bind) const;
  std::string settingsToString(Settings const&) const;


private:
  const std::string _filepath;
  bool    _fileExists;
  std::map<std::string, sf::Keyboard::Key> _stringKeys;
  std::map<std::string, JoystickEvent> _stringAxis;
  std::ifstream   *_ifs;
  std::ofstream   *_ofs;
};

#endif // SETTINGSLOADER_HH
