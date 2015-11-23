//
// ITexture.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Mon Nov 23 08:18:47 2015 Serge Heitzler
// Last update Mon Nov 23 08:18:48 2015 Serge Heitzler
//

#ifndef ITEXTURE_HH_
#define ITEXTURE_HH_

#include <string>
#include "IVector2u.hh"

class	        ITexture
{

  ITexture();
  ~ITexture();

  bool		loadFromFile(const std::string& path, unsigned int posX, unsigned int posY, unsigned int width, unsigned int height) = 0;
  IVector2u    	getSize() = 0;
  void		setSmooth(bool value) = 0;

};

#endif /* !ITEXTURE_HH_ */
