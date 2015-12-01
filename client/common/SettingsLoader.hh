//
// SettingsLoader.hh for SettingsLoader in /home/barnea_v/rendu/rtype_cpp/client/common
// 
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
// 
// Started on  Mon Nov 30 09:51:54 2015 Viveka BARNEAUD
// Last update Mon Nov 30 16:57:17 2015 Viveka BARNEAUD
//

#ifndef SETTINGSLOADER_HH
#define SETTINGSLOADER_HH

#include <SFML/Graphics.hpp>
#include <SFML/Event.hpp>
#include "IParser.hh"
#include "Settings.hh"

class SettingsLoader : public IParser
{
public:
  SettingsLoader(std::string const& filepath);
  ~SettingsLoader();

  std::string getValueOf(std::string const&) const;
  std::string getValueOfKey(std::string const&) const;
  std::string setValueOfJoystick(std::string const&) const;

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
  void		createDefaultBinds() const;

  void    saveSettings(Settings *) const;

  int     stringToInteger(std::string const&) const;
  sf::Event::key  stringToKey(std::string const&) const;
  sf::Event::joystick stringToJoystick(std::string const&) const;

  std::string keyToString(sf::Event) const;
  std::string joystickToString(sf::Event) const;
  std::string bindTypeToString(Bind::BindType) const;

private:
  const std::string _filepath;
  bool    _fileExists;
  std::ifstream   *_ifs;
  std::ofstream   *_ofs;
};

#endif // SETTINGSLOADER_HH
