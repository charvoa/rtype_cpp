//
// Asteroid.cpp for rtyoe in /home/nicolas/rendu/rtype_cpp/client/common
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed Dec 16 14:35:10 2015 Nicolas Girardot
// Last update Sat Dec 19 14:17:51 2015 Nicolas Girardot
//

#include <Asteroid.hh>
#include <Client.hh>

Asteroid::Asteroid()
{
  Sound *s = Client::getSound();
  _nbrSprite = 0;
  _delete = false;
  s->playSound("explosion1");
  this->setTexture(*(RenderWindow::getInstance()->_ressources->_asteroid));
}

Asteroid::~Asteroid()
{

}

sf::Sprite	&Asteroid::getSprite()
{
  return (_sprite);
}

bool	Asteroid::getState()
{
  return _delete;
}

void	Asteroid::setTexture(Texture &texture)
{
  _sprite.setTexture(texture.getTexture());
  _sprite.setOrigin(_spriteWidth / 2, _spriteHeight / 2);
  int	posX = (_nbrSprite % 8) * _spriteWidth;
  int	posY = (_nbrSprite / 8) * _spriteHeight;
  this->setTextureRect(posX, posY, _spriteWidth, _spriteHeight);
  _nbrSprite++;
}

void	Asteroid::setColor(Color::Tint tint)
{
  _sprite.setColor(Color::getSFColor(tint));
}

void	Asteroid::setTextureRect(float posX, float posY, float width, float height)
{
  _sprite.setTextureRect(sf::IntRect(posX, posY, width, height));
}

void	Asteroid::setPosition(float x, float y)
{
  _sprite.setPosition(x, y);
}

void   Asteroid::scale(float ratio)
{
  _sprite.scale(ratio, ratio);
}

void	Asteroid::setOrigin(float x, float y)
{
  _sprite.setOrigin(x, y);
}

void	Asteroid::move(float x, float y)
{
  _sprite.move(x, y);
}

void	Asteroid::rotate(float angle)
{
  _sprite.rotate(angle);
}

void	 Asteroid::update()
{
  static int i = 0;
  if (i % 2 == 0)
    {
      int	posX = (_nbrSprite % 8) * _spriteWidth;
      int	posY = ((_nbrSprite / 8) % 4) * _spriteHeight;
      this->setTextureRect(posX, posY, _spriteWidth, _spriteHeight);
      _nbrSprite++;
    }
  i++;
}
