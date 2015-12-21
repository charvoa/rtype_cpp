//
// SoundManager.hh for SoundManager in /home/antgar/rendu/cpp_bomberman/Sound
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Wed May 13 03:58:34 2015 Antoine Garcia
// Last update Sun Dec 13 12:22:25 2015 Nicolas Girardot
//

#ifndef SOUNDMANAGER_HH_
# define SOUNDMANAGER_HH_

#include <map>
#include <string>
#include <SFML/Audio.hpp>

class	Sound
{
  std::map<std::string, sf::SoundBuffer> _sounds;
  std::map<std::string, sf::Music *> _music;

public:
  Sound();
  ~Sound();
  void		initialize();
  bool		isPlaying(const std::string &title);
  void		registerSound(const std::string &filename, const std::string &title);
  void		registerMusic(const std::string &filename, const std::string &title);
  void		playMusic(const std::string &title, int repeat = 0);
  void		playSound(const std::string &title);
  void		pauseMusic(const std::string &title);
  void		stopMusic(const std::string &title);
  void		setMusicVolume(int);
  void		setEffectsVolume(int);
};

#endif
