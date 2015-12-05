//
// ITexture.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Mon Nov 23 08:18:47 2015 Serge Heitzler
// Last update Fri Dec  4 03:31:37 2015 Serge Heitzler
//

#ifndef ITEXTURE_HH_
#define ITEXTURE_HH_

#include <string>
#include "Vector2.hh"

class		      ITexture
{

public:
  virtual void		loadFromFile(const std::string& path) = 0;
  virtual void		loadFromFile(const std::string& path, unsigned int posX, unsigned int posY, unsigned int width, unsigned int height) = 0;
  virtual Vector2    	getSize() = 0;
  virtual void		setSmooth(bool value) = 0;

};

#endif /* !ITEXTURE_HH_ */
