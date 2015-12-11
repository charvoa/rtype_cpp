//
// Text.cpp for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Wed Dec  2 00:59:53 2015 Serge Heitzler
// Last update Thu Dec 10 23:22:06 2015 Serge Heitzler
//

#include <iostream>
#include <Text.hh>
#include <RenderWindow.hh>

Text::Text()
{
  _text.setFont(((RenderWindow::getInstance())->_ressources->_fontFirst->getFont()));
}

Text::Text(const std::string &string, SFont &font, unsigned int characterSize)
{
  (void)font;

  _text.setString(string);
  _text.setCharacterSize(characterSize);
}

Text::~Text()
{

}

void			Text::setFont(SFont& font)
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

void			Text::setPosition(Vector2 pos)
{
  _text.setPosition(sf::Vector2f(pos._x, pos._y));
}

void		        Text::setOrigin(float x, float y)
{
  _text.setOrigin(x, y);
}

void		        Text::setStyle(uint32_t style)
{
  _text.setStyle(style);
}

sf::Text	       	&Text::getText()
{
  return _text;
}
