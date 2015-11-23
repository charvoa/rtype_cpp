#ifndef TEXTURE_HH_
#define TEXTURE_HH_

#include <string>
#include "IVector2u.hh"

class	        Texture
{

  Texture();
  ~Texture();

  bool		loadFromFile(const std::string& path, unsigned int posX, unsigned int posY, unsigned int width, unsigned int height);
  IVector2u    	getSize();
  void		setSmooth(bool value);

};

#endif /* !TEXTURE_HH_ */
