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
    } StateButton;


  bool			mousePressEvent(sf::Event& event);
  bool			mouseReleaseEvent(sf::Event& event);
  bool			mouseEntered(sf::Event& event);
  bool			mouseLeft(sf::Event& event);

private:

	StateButton	       	_state;
	IText			_title;
	ISprite		_backgroundNormal;
	ISprite		_backgroundSelected;
};

#endif /* !BUTTON_HH_ */
