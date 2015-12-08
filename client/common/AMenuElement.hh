//
// AMenuElement.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Mon Nov 23 08:19:58 2015 Serge Heitzler
// Last update Mon Dec  7 10:54:17 2015 Serge Heitzler
//

#ifndef AMENUELEMENT_HH_
#define AMENUELEMENT_HH_

#include <SFML/Graphics.hpp>
#include "Sprite.hh"

class	        AMenuElement
{
public:
  AMenuElement();
  ~AMenuElement();

  virtual void			render();
  virtual void			update(std::pair<unsigned int, unsigned int> pair);

  Sprite			&getSprite();
  
protected:

  Sprite			*_sprite;

};

#endif /* !AMENUELEMENT_HH_ */
