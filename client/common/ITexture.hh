//
// ITexture.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Mon Nov 23 08:18:47 2015 Serge Heitzler
// Last update Tue Dec  1 02:57:05 2015 Serge Heitzler
//

#ifndef ITEXTURE_HH_
#define ITEXTURE_HH_

#include <string>
#include "IVector2u.hh"

class		      ITexture
{

  virtual bool		loadFromFile(const std::string& path, unsigned int posX, unsigned int posY, unsigned int width, unsigned int height) = 0;
  virtual IVector2    	getSize() = 0;
  virtual void		setSmooth(bool value) = 0;

};

#endif /* !ITEXTURE_HH_ */
