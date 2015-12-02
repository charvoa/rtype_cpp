//
// Text.cpp for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Wed Dec  2 00:59:53 2015 Serge Heitzler
// Last update Wed Dec  2 02:19:22 2015 Serge Heitzler
//

#include "Text.hh"

Text::Text()
{

}

Text::Text(const String &string, const IFont &font, unsigned int characterSize)
{
  _text.setString(string);
  _text.setSize(characterSize);
  _text.setFont(font.getFont());
}

Text::~Text()
{

}

void			Text::setFont(IFont& font)
{
  _text.setFont(font.getFont());
}

void			Text::setColor(IColor& color)
{
  _text.setColor(color);
}

void			Text::setSize(unsigned int size)
{
  _fontSize = size;
}

void			Text::setString(const std::string& title)
{
  _text.setString(title);
}
