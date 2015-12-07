//
// AMenuElement.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Mon Nov 23 08:19:58 2015 Serge Heitzler
// Last update Mon Dec  7 01:08:47 2015 Serge Heitzler
//

#ifndef AMENUELEMENT_HH_
#define AMENUELEMENT_HH_

#include <SFML/Graphics.hpp>
#include "Sprite.hh"
#include "Texture.hh"

class	        AMenuElement
{
public:
  AMenuElement();
  ~AMenuElement();

  virtual void			render();
  virtual void			update(std::pair<unsigned int, unsigned int> pair);
  Sprite			&getSprite();
  Texture			&getHighlightTexture();
  
protected:

    Sprite		*_sprite;
    Texture		*_highlight;

};

#endif /* !AMENUELEMENT_HH_ */
