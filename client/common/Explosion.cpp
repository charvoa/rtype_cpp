//
// Explosion.cpp for rtyoe in /home/nicolas/rendu/rtype_cpp/client/common
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed Dec 16 14:35:10 2015 Nicolas Girardot
// Last update Wed Dec 16 09:39:29 2015 Serge Heitzler
//

#include <Explosion.hh>
#include <Client.hh>

Explosion::Explosion()
{
  Sound *s = Client::getSound();
  _nbrSprite = 0;
  _delete = false;
  s->playSound("explosion1");
}

Explosion::~Explosion()
{

}

sf::Sprite	&Explosion::getSprite()
{
  return (_sprite);
}

bool	Explosion::getState()
{
  return _delete;
}

void	Explosion::setTexture(Texture &texture)
{
  _sprite.setTexture(texture.getTexture());
  _sprite.setOrigin(_spriteWidth / 2, _spriteHeight / 2);
  int	posX = (_nbrSprite % 8) * _spriteWidth;
  int	posY = (_nbrSprite / 8) * _spriteHeight;
  this->setTextureRect(posX, posY, _spriteWidth, _spriteHeight);
  _nbrSprite++;
}

void	Explosion::setColor(Color::Tint tint)
{
  _sprite.setColor(Color::getSFColor(tint));
}

void	Explosion::setTextureRect(float posX, float posY, float width, float height)
{
  _sprite.setTextureRect(sf::IntRect(posX, posY, width, height));
}

void	Explosion::setPosition(float x, float y)
{
  _sprite.setPosition(x, y);
}

void   Explosion::scale(float ratio)
{
  _sprite.scale(ratio, ratio);
}

void	Explosion::setOrigin(float x, float y)
{
  _sprite.setOrigin(x, y);
}

void	Explosion::move(float x, float y)
{
  _sprite.move(x, y);
}

void	Explosion::rotate(float angle)
{
  _sprite.rotate(angle);
}

void	 Explosion::update()
{
  int	posX = (_nbrSprite % 8) * _spriteWidth;
  int	posY = (_nbrSprite / 8) * _spriteHeight;
  this->setTextureRect(posX, posY, _spriteWidth, _spriteHeight);
  _nbrSprite++;
  if (_nbrSprite > 32)
    _delete = true;
}
