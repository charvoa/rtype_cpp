//
// ISprite.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Mon Nov 23 08:18:52 2015 Serge Heitzler
// Last update Wed Nov 25 06:32:13 2015 Serge Heitzler
//

#ifndef ISPRITE_HH_
#define ISPRITE_HH_

#include "ITexture.hh"
#include "IColor.hh"

class		      ISprite
{

  ISprite(const ITexture& texture);
  ~ISprite();

  virtual void		setTexture(const ITexture& texture) = 0;
  virtual void		setColor(const IColor& color) = 0;
  virtual void		setPosition(float x, float y) = 0;
  virtual void		scale(float ratio) = 0;
  virtual void		setOrigin(float x, float y) = 0;
  virtual void		move (float x, float y) = 0;
  virtual void		rotate(float angle) = 0;

};

#endif /* !ISPRITE_HH_ */
