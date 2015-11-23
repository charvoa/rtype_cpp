#ifndef BUTTON_HH_
#define BUTTON_HH_

#include "IText.hh"

typedef enum StateButton
  {
    NORMAL,
    SELECTED,
    DISABLED
  };

class	        Button
{

  Button();
  ~Button();

private:

  StateButton	       	_state;
  IText			_title;
  ISprite		_backgroundNormal;
  ISprite		_backgroundSelected;
  
public:

  unsigned int		getWidth();
  unsigned int		getHeight();

};

#endif /* !BUTTON_HH_ */
