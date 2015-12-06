//
// Font.cpp for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Wed Dec  2 02:02:22 2015 Serge Heitzler
// Last update Thu Dec  3 13:53:21 2015 Serge Heitzler
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

sf::Font		Font::getFont()
{
  return _font;
}
