//
// Sprite.cpp for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Wed Dec  2 05:56:26 2015 Serge Heitzler
<<<<<<< HEAD
// Last update Thu Dec  3 20:46:11 2015 Nicolas Girardot
=======
// Last update Thu Dec  3 10:49:09 2015 Serge Heitzler
>>>>>>> bc6b45cebd27936c0cb9f6e5071edd2993d0d62f
//

#include "Sprite.hh"

Sprite::Sprite()
{
  _sprite.setOrigin(0.5, 0.5);
}

Sprite::~Sprite()
{

}

void			Sprite::setTexture(const Texture& texture)
{
  _sprite.setTexture(texture.getTexture());
}

void			Sprite::setColor(const IColor& color)
{
  _sprite.setColor(color);
}

void			Sprite::setPosition(float x, float y)
{
  _sprite.setPosition(x, y);
}

void			Sprite::scale(float ratio)
{
  _sprite.scale(ratio);
}

void			Sprite::setOrigin(float x, float y)
{
  _sprite.setOrigin(x, y);
}

void			Sprite::move(float x, float y)
{
  _sprite.move(x, y);
}

void			Sprite::rotate(float angle)
{
  _sprite.rotate(angle);
}
