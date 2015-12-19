//
// Explosion.hh for RTYPE in /home/nicolas/rendu/rtype_cpp/client/build
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed Dec 16 11:53:49 2015 Nicolas Girardot
// Last update Sat Dec 19 05:33:54 2015 Serge Heitzler
//

#ifndef ASTEROID_HH_
#define ASTEROID_HH_

#include <Sprite.hh>
#include <Ressources.hh>
#include <RenderWindow.hh>

class	Asteroid : public ISprite
{
public:
  Asteroid();
  ~Asteroid();

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
  int		_spriteWidth = 128;
  int		_spriteHeight = 128;
  bool		_delete;
};

#endif
