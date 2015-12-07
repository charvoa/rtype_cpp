//
// APanel.cpp for APanel in /home/barnea_v/rendu/rtype_cpp/client/common
//
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
//
// Started on  Mon Nov 30 09:51:09 2015 Viveka BARNEAUD
// Last update Mon Dec  7 01:03:50 2015 Serge Heitzler
//

#include <iostream>
#include <map>
#include "APanel.hh"
#include "RenderWindow.hh"

APanel::APanel(){}

APanel::~APanel(){}

void		APanel::update()
{
  // unsigned int		i = 0;
  // if (this->getElements().size() > 0)
  //   while (i < this->getElements().size())
  //     {
  // 	this->getElements().at(i)
  // 	// 
  // 	i++;
  //     }  
}

void		APanel::render()
{
  unsigned int		i = 0;

  if (this->getSprites().size() > 0)
    while (i < this->getSprites().size())
      {
	(RenderWindow::getInstance())->draw(this->_sprites.at(i).getSprite());
	i++;
      }
  i = 0;
  if (this->getElements().size() > 0)
    while (i < this->getElements().size())
      {
	(RenderWindow::getInstance())->draw(this->getElements().at(i)->getSprite().getSprite());
	i++;
      }
}

void		APanel::hide()
{

}

std::vector<AMenuElement*>		&APanel::getElements()
{
  return _elements;
}

std::vector<Sprite>			&APanel::getSprites()
{
  return _sprites;
}

InputManager	&APanel::getInputManager()
{
  return _inputManager;
}
