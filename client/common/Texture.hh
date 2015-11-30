//
// Texture.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Mon Nov 23 08:18:31 2015 Serge Heitzler
// Last update Wed Nov 25 06:34:33 2015 Serge Heitzler
//

#ifndef TEXTURE_HH_
#define TEXTURE_HH_

#include <string>
#include "IVector2u.hh"
#include "ITexture.hh"

class	        Texture : public ITexture
{

  Texture();
  ~Texture();

  bool		loadFromFile(const std::string& path, unsigned int posX, unsigned int posY, unsigned int width, unsigned int height);
  IVector2u    	getSize();
  void		setSmooth(bool value);

};

#endif /* !TEXTURE_HH_ */
