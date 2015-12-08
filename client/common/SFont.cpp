//
// Font.cpp for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Wed Dec  2 02:02:22 2015 Serge Heitzler
// Last update Tue Dec  8 07:30:54 2015 Serge Heitzler
//

#include "SFont.hh"

SFont::SFont()
{

}

SFont::SFont(const std::string &filename)
{
  _font.loadFromFile(filename);
}

SFont::~SFont()
{

}

void			SFont::loadFromFile(const std::string &filename)
{
  _font.loadFromFile(filename);
}

sf::Font		SFont::getFont()
{
  return _font;
}
