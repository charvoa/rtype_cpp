//
// Sprite.cpp for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Wed Dec  2 05:56:26 2015 Serge Heitzler
// Last update Fri Dec  4 08:31:36 2015 Serge Heitzler
//

#include "Sprite.hh"

Sprite::Sprite()
{
}

Sprite::~Sprite()
{

}

void			Sprite::setTexture(Texture& texture)
{
  _sprite.setTexture(texture.getTexture());
}

void			Sprite::setColor(Color::Tint tint)
{
  _sprite.setColor(Color::getSFColor(tint));
}

void			Sprite::setPosition(float x, float y)
{
  _sprite.setPosition(x, y);
}

void			Sprite::scale(float ratio)
{
  _sprite.scale(ratio, ratio);
}

void			Sprite::setOrigin(float x, float y)
{
  // Get size texture x/2 && y/2
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

sf::Sprite     		Sprite::getSprite()
{
  return _sprite;
}
