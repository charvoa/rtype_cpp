//
// AMenuElement.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Mon Nov 23 08:19:58 2015 Serge Heitzler
// Last update Tue Dec  1 14:46:28 2015 Serge Heitzler
//

#ifndef AMENUELEMENT_HH_
#define AMENUELEMENT_HH_

#include <SFML/Graphics.hpp>
#include "Position.hh"
#include "Size.hh"

class	        AMenuElement
{
public:
  AMenuElement(unsigned int x, unsigned int y, unsigned int width, unsigned int height);
  ~AMenuElement();

  Position		&getPosition();
  Size			&getSize();
  virtual void			render();

private:

  Position		_position;
  Size			_size;
  
};

#endif /* !AMENUELEMENT_HH_ */
