//
// AMenuElement.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Mon Nov 23 08:19:58 2015 Serge Heitzler
// Last update Wed Nov 25 06:02:56 2015 Serge Heitzler
//

#ifndef AMENUELEMENT_HH_
#define AMENUELEMENT_HH_

#include <SFML/Graphics.hpp>
#include "Position.hh"
#include "Size.hh"

class	        AMenuElement
{

  AMenuElement();
  ~AMenuElement();

  Position		&getPosition();
  Size			&getSize();

private:

  Position		_position;
  Size			_size;
  
};

#endif /* !AMENUELEMENT_HH_ */
