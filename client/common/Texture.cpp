//
// Texture.cpp for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Wed Dec  2 00:29:28 2015 Serge Heitzler
// Last update Wed Dec  2 04:46:11 2015 Serge Heitzler
//

#include "Texture.hh"

Texture::Texture()
{
  _texture.setSmooth(true);
}

Texture::~Texture()
{}

bool		Texture::loadFromFile(const std::string& path)
{
  _texture.loadFromFile(path);
}

bool		Texture::loadFromFile(const std::string& path, unsigned int posX, unsigned int posY, unsigned int width, unsigned int height)
{
  _texture.loadFromFile(path, posX, posY, width, height);
}

IVector2    	Texture::getSize()
{
  sf::Vector2	size = _texture.getSize();
  return IVector2(size.x, size.y);
}

void		Texture::setSmooth(bool value)
{
  _texture.setSmooth(value);
}

sf::Texture	Texture::getTexture()
{
  return _texture;
}
