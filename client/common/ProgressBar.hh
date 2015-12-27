//
// ProgressBar.hh for ProgressBar in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Tue Dec  1 14:05:18 2015 Serge Heitzler
// Last update Sun Dec 27 08:07:06 2015 Serge Heitzler
//

#ifndef PROGRESSBAR_HH_
#define PROGRESSBAR_HH_

#include <AMenuElement.hh>

class	        ProgressBar : public AMenuElement
{

public:

  ProgressBar(unsigned int x, unsigned int y, unsigned int width, unsigned int height);
  ~ProgressBar();

  void			setProgression(unsigned int progressValue);
  unsigned int 		getProgression();
  sf::RectangleShape	getShape();
  
private:

  unsigned int		_progressValue;
  IText			_valueLabel;
  sf::RectangleShape	_valueShape;
  
};

#endif /* !PROGRESSBAR_HH_ */
