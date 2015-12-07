//
// Texture.cpp for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Wed Dec  2 00:29:28 2015 Serge Heitzler
// Last update Sat Dec  5 07:25:39 2015 Serge Heitzler
//

#include "Texture.hh"
#include <iostream>

Texture::Texture()
{
  _texture.setSmooth(true);
}

Texture::~Texture()
{}

void		Texture::loadFromFile(const std::string& path)
{
  _texture.loadFromFile(path);
}

void		Texture::loadFromFile(const std::string& path, unsigned int posX, unsigned int posY, unsigned int width, unsigned int height)
{
  _texture.loadFromFile(path, sf::IntRect(posX, posY, width, height));
}

Vector2    	Texture::getSize()
{
  sf::Vector2<unsigned int> size = _texture.getSize();
  return Vector2(size.x, size.y);
}

void		Texture::setSmooth(bool value)
{
  _texture.setSmooth(value);
}

sf::Texture	&Texture::getTexture()
{
  return _texture;
}
