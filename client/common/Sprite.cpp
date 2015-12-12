//
// Sprite.cpp for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Wed Dec  2 05:56:26 2015 Serge Heitzler
// Last update Sat Dec 12 06:08:39 2015 Serge Heitzler
//

#include "Sprite.hh"

Sprite::Sprite()
{
  _isScale = false;
}

Sprite::~Sprite()
{

}

void			Sprite::setTexture(Texture& texture)
{
  _sprite.setTexture(texture.getTexture());
}

void			Sprite::setTextureRect(float posX, float posY, float width, float height)
{
  _sprite.setTextureRect(sf::IntRect(posX, posY, width, height));
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
  _isScale = true;
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

void			Sprite::setIfScale(bool value)
{
  _isScale = value;
}

bool			Sprite::isScale()
{
  return _isScale;
}

sf::Sprite     		&Sprite::getSprite()
{
  return _sprite;
}

std::pair<std::pair<unsigned int, unsigned int>, std::pair<unsigned int, unsigned int>>     		Sprite::getGlobalBounds()
{
  unsigned int	posX = _sprite.getGlobalBounds().left;
  unsigned int	posY = _sprite.getGlobalBounds().top;
  unsigned int  width = _sprite.getGlobalBounds().width;
  unsigned int  height = _sprite.getGlobalBounds().height;

  return std::make_pair(std::make_pair(posX, posY), std::make_pair(width, height));
}
