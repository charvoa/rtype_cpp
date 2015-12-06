//
// Text.cpp for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Wed Dec  2 00:59:53 2015 Serge Heitzler
// Last update Thu Dec  3 21:59:06 2015 Nicolas Girardot
//

#include "Text.hh"

Text::Text(const std::string &string, Font &font, unsigned int characterSize)
{
  _text.setString(string);
  _text.setCharacterSize(characterSize);
  _text.setFont(font.getFont());
}

Text::~Text()
{

}

void			Text::setFont(Font& font)
{
  _text.setFont(font.getFont());
}

void			Text::setColor(Color::Tint color)
{
  _text.setColor(Color::getSFColor(color));
}

void			Text::setSize(unsigned int size)
{
  _fontSize = size;
}

void			Text::setString(const std::string& title)
{
  _text.setString(title);
}
