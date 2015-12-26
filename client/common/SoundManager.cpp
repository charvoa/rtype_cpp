//
// SoundManager.cpp for SoundManager in /home/antgar/rendu/cpp_bomberman/Sound
//
// Made by Antoine Garcia
// Login   <antgar@epitech.net>
//
// Started on  Wed May 13 03:57:20 2015 Antoine Garcia
// Last update Sun Dec 13 12:23:10 2015 Nicolas Girardot
//

#include <iostream>
#include "SettingsPanel.hh"
#include "RenderWindow.hh"
#include "SoundManager.hh"

Sound::Sound()
{

}

Sound::~Sound()
{

}

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
	RenderWindow *window = RenderWindow::getInstance();
	int			global = window->getSettings()->getVolume().getGlobal();
	int			music = window->getSettings()->getVolume().getMusic();

	if (repeat == 1)
    _music[title]->setLoop(true);
  _music[title]->setVolume((global * music) / 100);
  _music[title]->play();
}

void	Sound::playSound(const std::string &title)
{
	RenderWindow *window = RenderWindow::getInstance();
	int			global;
	int			effects;

	sf::Sound *sound = new sf::Sound();
	if ((PanelFactory::PanelType)window->getPanels().top()->getType() == PanelFactory::SETTINGS_PANEL)
	{
		global = dynamic_cast<SettingsPanel*>(window->getPanels().top())->getTemporarySettings()->getVolume().getGlobal();
		effects = dynamic_cast<SettingsPanel*>(window->getPanels().top())->getTemporarySettings()->getVolume().getEffects();
	}
	else
	{
		global = window->getSettings()->getVolume().getGlobal();
		effects = window->getSettings()->getVolume().getEffects();
	}
	sound->setBuffer(_sounds[title]);
  sound->setVolume((global * effects) / 100);
  sound->play();
}

bool	Sound::isPlaying(const std::string &title)
{
  if (_music[title]->getStatus() == sf::SoundSource::Status::Playing)
    return true;
  else
    return false;
}

void	Sound::pauseMusic(const std::string &title)
{
  _music[title]->pause();
}

void	Sound::stopMusic(const std::string &title)
{
  _music[title]->stop();
}

void	Sound::setEffectsVolume(int vol)
{
	(void)vol;
}

void	Sound::setMusicVolume(int vol)
{
	std::map< std::string, sf::Music *>::iterator it = _music.begin();
	std::map< std::string, sf::Music *>::iterator end = _music.end();

	while (it != end)
	{
		it->second->setVolume(vol);
		++it;
	}
}