//
// Sprite.cpp for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Wed Dec  2 05:56:26 2015 Serge Heitzler
// Last update Thu Dec  3 10:49:09 2015 Serge Heitzler
//

#include "Sprite.hh"

Sprite::Sprite()
{
  _sprite.setOrigin(0.5, 0.5);
}

Sprite::~Sprite()
{

}

void			setTexture(const ITexture& texture)
{
  _sprite.setTexture(texture.getTexture());
}

void			setColor(const IColor& color)
{
  _sprite.setColor(color);
}

void			setPosition(float x, float y)
{
  _sprite.setPosition(x, y);
}

void			scale(float ratio)
{
  _sprite.scale(ratio);
}

void			setOrigin(float x, float y)
{
  _sprite.setOrigin(x, y);
}

void			move(float x, float y)
{
  _sprite.move(x, y);
}

void			rotate(float angle)
{
  _sprite.rotate(angle);
}

