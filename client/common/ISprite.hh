#ifndef ISPRITE_HH_
#define ISPRITE_HH_

#include "ITexture.hh"
#include "IColor.hh"

class	        ISprite
{

  ISprite(const ITexture& texture);
  ~ISprite();

  void		setTexture(const ITexture& texture) = 0;
  void		setColor(const IColor& color) = 0;
  void		setPosition(float x, float y) = 0;
  void		scale(float ratio) = 0;
  void		setOrigin(float x, float y) = 0;
  void		move (float x, float y) = 0;
  void		rotate(float angle) = 0;

};

#endif /* !ISPRITE_HH_ */
