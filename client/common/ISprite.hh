//
// ISprite.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Mon Nov 23 08:18:52 2015 Serge Heitzler
// Last update Mon Nov 23 08:18:53 2015 Serge Heitzler
//

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
