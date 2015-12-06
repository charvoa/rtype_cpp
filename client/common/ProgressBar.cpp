//
// ProgressBar.cpp for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Tue Dec  1 14:32:10 2015 Serge Heitzler
// Last update Tue Dec  1 15:05:46 2015 Serge Heitzler
//

#include "ProgressBar.hh"

ProgressBar::ProgressBar(unsigned int x, unsigned int y, unsigned int width, unsigned int height)
{
  
}

ProgressBar::~ProgressBar()
{

}

void			ProgressBar::setProgression(unsigned int progressValue)
{
  std::string newValue = std::to_string(progressValue) + " %";
  unsigned int width = this.getSize().getWidth();
  
  _progressValue = progressValue;
  _valueLabel.setString(newValue);
  _valueShape.setSize(IVector((100 / width) * progressValue), 40));
}

unsigned int 		ProgressBar::getProgression()
{
  return _progressValue;
}

sf::RectangleShape	ProgressBar::getShape()
{
  return _valueShape;
}
