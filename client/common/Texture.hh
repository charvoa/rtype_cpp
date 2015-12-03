//
// Texture.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Mon Nov 23 08:18:31 2015 Serge Heitzler
// Last update Thu Dec  3 11:35:06 2015 Serge Heitzler
//

#ifndef		TEXTURE_HH_
#define		TEXTURE_HH_

#include	<SFML/Graphics.hpp>
#include	<string>
#include	"ITexture.hh"
#include	"Vector2.hh"

class	        Texture : public ITexture
{

public:
  
  Texture();
  ~Texture();

  bool		loadFromFile(const std::string& path);
  bool		loadFromFile(const std::string& path, unsigned int posX, unsigned int posY, unsigned int width, unsigned int height);
  Vector2    	getSize();
  void		setSmooth(bool value);
  sf::Texture  	getTexture();

private:

  sf::Texture	_texture;

};

#endif /* !TEXTURE_HH_ */
