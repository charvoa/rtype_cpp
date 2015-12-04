//
// APanel.cpp for APanel in /home/barnea_v/rendu/rtype_cpp/client/common
//
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
//
// Started on  Mon Nov 30 09:51:09 2015 Viveka BARNEAUD
// Last update Fri Dec  4 03:40:57 2015 Serge Heitzler
//

#include "APanel.hh"
#include "RenderWindow.hh"
#include <iostream>
APanel::APanel(){}

APanel::~APanel(){}

void		APanel::update()
{

}

void		APanel::render()
{
  unsigned int		i = 0;

  if (this->getSprites().size() > 0)
    while (i < this->getSprites().size())
      {
	std::cout << "toto" << std::endl;
	(RenderWindow::getInstance())->draw(this->_sprites.at(i).getSprite());
	std::cout << this->_sprites.at(i).getSprite().getPosition().x << std::endl;
	i++;
      }
  std::cout << this->getSprites().size() << std::endl;
}

void		APanel::hide()
{

}

std::vector<AMenuElement*>		APanel::getElements()
{
  return _elements;
}

std::vector<Sprite>			APanel::getSprites()
{
  return _sprites;
}
