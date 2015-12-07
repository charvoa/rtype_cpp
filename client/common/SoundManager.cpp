//
// SoundManager.cpp for SoundManager in /home/antgar/rendu/cpp_bomberman/Sound
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Wed May 13 03:57:20 2015 Antoine Garcia
// Last update Mon Dec  7 15:10:44 2015 Nicolas Girardot
//

#include <iostream>
#include "SoundManager.hh"

void	Sound::initialize()
{
}

void	Sound::registerSound(const std::string &filename, const std::string&title)
{
  sf::SoundBuffer buffer;
  buffer.loadFromFile(filename);

  _sounds[title] = buffer;
}

void	Sound::registerMusic(const std::string &filename, const std::string&title)
{
  _music[title] = new sf::Music();
  sf::Music *m = _music[title];
  m->openFromFile(filename);
}

void	Sound::playMusic(const std::string &title, int repeat)
{
  if (repeat == 1)
    _music[title]->setLoop(true);
  _music[title]->play();
}

void	Sound::playSound(const std::string &title)
{
  sf::Sound *sound = new sf::Sound();
  sound->setBuffer(_sounds[title]);

  sound->play();
}

void	Sound::pauseMusic(const std::string &title)
{
  _music[title]->pause();
}

void	Sound::stopMusic(const std::string &title)
{
  _music[title]->stop();
}
