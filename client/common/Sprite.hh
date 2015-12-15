//
// Sprite.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Wed Dec  2 05:57:07 2015 Serge Heitzler
// Last update Sat Dec 19 09:35:33 2015 Serge Heitzler
//

#ifndef SPRITE_HH_
#define SPRITE_HH_

#include <map>
#include <ISprite.hh>
#include <Color.hh>

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
  void			setTextureRect(float posX, float posY, float width, float height);
  std::pair<std::pair<int, int>, std::pair<int, int>>			getGlobalBounds();
  sf::Sprite		&getSprite();
  void		        setIfScale(bool value);
  bool		        isScale();
  float			getPosX() const;
  float			getPosY() const;
  float			getWidth() const;
  float			getHeight() const;

private:

  sf::Sprite		_sprite;
  bool			_isScale;

};

#endif /* !SPRITE_HH_ */
