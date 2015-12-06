//
// Button.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Mon Nov 23 08:19:49 2015 Serge Heitzler
// Last update Thu Dec  3 13:22:44 2015 Serge Heitzler
//

#ifndef BUTTON_HH_
#define BUTTON_HH_

#include "Text.hh"
#include "Sprite.hh"
#include "AMenuElement.hh"

class	        Button : public AMenuElement
{
public:
  Button();
  ~Button();

  typedef enum e_stateButton
    {
      NORMAL,
      SELECTED,
      DISABLED
    }		StateButton;


  bool			mousePressEvent(sf::Event& event);
  bool			mouseReleaseEvent(sf::Event& event);
  bool			mouseEntered(sf::Event& event);
  bool			mouseLeft(sf::Event& event);
  void			render();

private:

  StateButton	       	_state;
  Text			_title;
  Sprite		_backgroundNormal;
  Sprite		_backgroundSelected;
};

#endif /* !BUTTON_HH_ */
