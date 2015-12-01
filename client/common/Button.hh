//
// Button.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Mon Nov 23 08:19:49 2015 Serge Heitzler
// Last update Tue Dec  1 14:46:43 2015 Serge Heitzler
//

#ifndef BUTTON_HH_
#define BUTTON_HH_

#include "IText.hh"
#include "ISprite.hh"
#include "AMenuElement.hh"

typedef enum StateButton
  {
    NORMAL,
    SELECTED,
    DISABLED
  };

class	        Button : public AMenuElement
{

  Button(unsigned int x, unsigned int y, unsigned int width, unsigned int height);
  ~Button();

private:

  StateButton	       	_state;
  IText			_title;
  ISprite		_backgroundNormal;
  ISprite		_backgroundSelected;
  
public:
  
  bool			mousePressEvent(sf::Event& event);
  bool			mouseReleaseEvent(sf::Event& event);
  bool			mouseEntered(sf::Event& event);
  bool			mouseLeft(sf::Event& event);

};

#endif /* !BUTTON_HH_ */
