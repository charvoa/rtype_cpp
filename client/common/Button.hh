//
// Button.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Mon Nov 23 08:19:49 2015 Serge Heitzler
// Last update Mon Nov 30 09:56:56 2015 Viveka BARNEAUD
//

#ifndef BUTTON_HH_
#define BUTTON_HH_

#include "IText.hh"
#include "ISprite.hh"

typedef enum StateButton
  {
    NORMAL,
    SELECTED,
    DISABLED
  };

class	        Button : public AMenuElement
{

  Button();
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
