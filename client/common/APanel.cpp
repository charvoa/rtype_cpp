//
// APanel.cpp for APanel in /home/barnea_v/rendu/rtype_cpp/client/common
//
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
//
// Started on  Mon Nov 30 09:51:09 2015 Viveka BARNEAUD
// Last update Tue Dec 15 11:07:03 2015 Serge Heitzler
//

#include <iostream>
#include <map>
#include <APanel.hh>
#include <RenderWindow.hh>

APanel::APanel()
{
  std::cout << "CONSTRUCTOR APANEL" << std::endl;
  RenderWindow *window = RenderWindow::getInstance();
  window->setMouseCursorVisible(true);
}

APanel::~APanel()
{
  std::cout << "DESTRUCTOR APANEL" << std::endl;
}

void		APanel::update(){}

void		APanel::setUserInterface(){}

void		APanel::updateOnMove(std::pair<unsigned int, unsigned int> pair)
{
  unsigned int		i = 0;
  while (i < this->_userInterface.size() && this->_userInterface.size() > 0)
    {
      this->_userInterface.at(i)->updateOnMove(pair);
      i++;
    }
}

bool		APanel::updateOnPress(std::pair<unsigned int, unsigned int> pair)
{
  unsigned int		i = 0;
  while (i < this->_userInterface.size() && this->_userInterface.size() > 0)
    {
      if (this->_userInterface.at(i)->updateOnPress(pair))
	{
	  (*this.*_functions.at(i))();
	  return true;
	}
      i++;
    }
  return false;
}

void		APanel::setKeyButton(sf::Event event)
{
	unsigned int		i = 0;
	while (i < this->_userInterface.size() && this->_userInterface.size() > 0)
	{
		this->_userInterface.at(i)->setBind(event);
		i++;
	}
}

void		APanel::updateOnRelease(std::pair<unsigned int, unsigned int> pair)
{
	unsigned int		i = 0;
	while (i < this->_userInterface.size() && this->_userInterface.size() > 0)
	{
		this->_userInterface.at(i)->updateOnRelease(pair);
		i++;
	}
}

void		APanel::render()
{
  this->drawBackgrounds();
  this->drawUserInterface();
  this->drawLabels();
  this->drawInGame();
}

void					APanel::drawBackgrounds()
{
  unsigned int		i = 0;

  while (i < this->_backgrounds.size() && this->_backgrounds.size() > 0)
    {
      (RenderWindow::getInstance())->draw(this->_backgrounds.at(i).getSprite());
      i++;
    }
}

void					APanel::drawUserInterface()
{
  unsigned int		i = 0;

  while (i < this->_userInterface.size() && this->_userInterface.size() > 0)
    {
      (RenderWindow::getInstance())->draw(this->_userInterface.at(i)->getSprite().getSprite());
      i++;
    }
}

void					APanel::drawLabels()
{
  unsigned int		i = 0;

  i = 0;
  while (i < this->_labels.size() && this->_labels.size() > 0)
    {
      (RenderWindow::getInstance())->draw(this->_labels.at(i).getText());
      i++;
    }
}

void					APanel::drawInGame()
{
  unsigned int		i = 0;

  i = 0;
  while (i < this->_inGame.size() && this->_inGame.size() > 0)
    {
      (RenderWindow::getInstance())->draw(this->_inGame.at(i).getSprite());
      i++;
    }
}


void		APanel::hide(){}

std::vector<AMenuElement*>		&APanel::getUserInterface()
{
  return _userInterface;
}

std::vector<Sprite>			&APanel::getBackgrounds()
{
  return _backgrounds;
}

std::vector<Text>			&APanel::getLabels()
{
  return _labels;
}

std::vector<Sprite>			&APanel::getInGame()
{
  return _inGame;
}

InputManager	&APanel::getInputManager()
{
  return _inputManager;
}

void			APanel::setEffectsVolume(int vol)
{
	(void)vol;
}

void			APanel::setGlobalVolume(int vol)
{
	(void)vol;
}

void			APanel::setMusicVolume(int vol)
{
	(void)vol;
}

typedef void(APanel::*funcs)();
std::vector<funcs>	&APanel::getFunctions()
{
  return _functions;
}

int	APanel::getType()
{
	return _type;
}