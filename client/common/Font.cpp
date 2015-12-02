//
// Font.cpp for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Wed Dec  2 02:02:22 2015 Serge Heitzler
// Last update Wed Dec  2 02:22:58 2015 Serge Heitzler
//

#include "Font.hh"

Font::Font()
{

}

Font::Font(const std::string &filename)
{
  _font.loadFromFile(filename);
}

Font::~Font()
{

}

void			Font::loadFromFile(const std::string &filename)
{
  _font.loadFromFile(filename);
}

sf::font		Font::getFont()
{
  return _font;
}
