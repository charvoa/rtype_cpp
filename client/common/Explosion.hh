//
// Explosion.hh for RTYPE in /home/nicolas/rendu/rtype_cpp/client/build
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed Dec 16 11:53:49 2015 Nicolas Girardot
// Last update Wed Dec 16 15:44:50 2015 Nicolas Girardot
//

#ifndef EXPLOSION_HH_
#define EXPLOSION_HH_

#include <Sprite.hh>

class	Explosion : public ISprite
{
public:
  Explosion();
  ~Explosion();

  void	setTexture(Texture& texture);
  void	setColor(Color::Tint color);
  void	setPosition(float x, float y);
  void	scale(float ration);
  void	setOrigin(float x, float y);
  void	move(float x, float y);
  bool	getState();
  void	rotate(float angle);
  void	setTextureRect(float posX, float posY, float width, float height);
  sf::Sprite	&getSprite();
  void	update();

private:
  sf::Sprite	_sprite;
  int		_nbrSprite;
  int		_spriteWidth = 256;
  int		_spriteHeight = 256;
  bool		_delete;
};

#endif
