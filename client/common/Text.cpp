//
// Text.cpp for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Wed Dec  2 00:59:53 2015 Serge Heitzler
// Last update Sat Dec  5 07:47:30 2015 Serge Heitzler
//

#include "Text.hh"

Text::Text()
{
}

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
  _text.setCharacterSize(size);
}

void			Text::setString(const std::string& title)
{
  _text.setString(title);
}

sf::Text		&Text::getText()
{
  return _text;
}
