//
// Sprite.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Wed Dec  2 05:57:07 2015 Serge Heitzler
// Last update Thu Dec  3 20:46:16 2015 Nicolas Girardot
//

#ifndef SPRITE_HH_
#define SPRITE_HH_

#include "ISprite.hh"

class		      Sprite : public ISprite
{

public:
  Sprite();
  ~Sprite();

  void			setTexture(const Texture& texture);
  void			setColor(const IColor& color);
  void			setPosition(float x, float y);
  void			scale(float ratio);
  void			setOrigin(float x, float y);
  void			move(float x, float y);
  void			rotate(float angle);
  sf::Sprite		getSprite();

private:

  sf::Sprite		_sprite;

};

#endif /* !SPRITE_HH_ */
