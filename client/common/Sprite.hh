//
// Sprite.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Wed Dec  2 05:57:07 2015 Serge Heitzler
// Last update Fri Dec  4 03:25:26 2015 Serge Heitzler
//

#ifndef SPRITE_HH_
#define SPRITE_HH_

#include "ISprite.hh"
#include "Color.hh"

class		      Sprite : public ISprite
{

public:
  Sprite();
  ~Sprite();

  void			setTexture(Texture& texture);
  void			setColor(Color::Tint color);
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
