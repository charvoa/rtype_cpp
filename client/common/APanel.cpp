//
// APanel.cpp for APanel in /home/barnea_v/rendu/rtype_cpp/client/common
//
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
//
// Started on  Mon Nov 30 09:51:09 2015 Viveka BARNEAUD
// Last update Thu Dec  3 11:59:08 2015 Serge Heitzler
//

#include "APanel.hh"
#include "RenderWindow.hh"

APanel::APanel(){}

APanel::~APanel(){}

void		APanel::update()
{
  
}

void		APanel::render()
{
  unsigned int		i = 0;

  if (this->getElements().size() > 0)
    while (i++ < this->getElements().size())
      {
	(RenderWindow::getInstance())->draw(this->getSprites().at(i)->getSprite());
      }
}

void		APanel::hide()
{

}

std::vector<AMenuElement*>		APanel::getElements()
{
  return _elements;
}

std::vector<Sprite*>			APanel::getSprites()
{
  return _sprites;
}
