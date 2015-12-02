//
// APanel.cpp for APanel in /home/barnea_v/rendu/rtype_cpp/client/common
// 
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
// 
// Started on  Mon Nov 30 09:51:09 2015 Viveka BARNEAUD
// Last update Wed Dec  2 07:48:43 2015 Serge Heitzler
//

#include "APanel.hh"

APanel::APanel(){}

APanel::~APanel(){}

void		APanel::render()
{
  int		i = -1;
  
  if (this->getElements().size() >= 0)
    while (++i < this->getElements().size())
      (RenderWindow::getInstance())->draw(this->getElements().at(i));
}

void		APanel::hide()
{

}

std::vector<AMenuElement*>		APanel::getElements()
{
  return _elements;
}
