//
// Color.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Mon Nov 23 08:20:04 2015 Serge Heitzler
// Last update Mon Nov 23 08:20:06 2015 Serge Heitzler
//

#ifndef COLOR_HH_
#define COLOR_HH_

#include <SFML/Graphics.hpp>
#include "IColor.hh"

class	        Color : public IColor
{

  Color(Uint8 r, Uint8 g, Uint8 b, Uint8 a);
  ~Color();

  sf::Color		_black = sf::Color::Black;
  sf::Color		_white = sf::Color::White;
  sf::Color		_red = sf::Color::Red;
  sf::Color		_green = sf::Color::Green;
  sf::Color		_blue = sf::Color::Blue;
  sf::Color		_yellow = sf::Color::Yellow;
  sf::Color		_magenta = sf::Color::Magenta;
  sf::Color		_cyan = sf::Color::Cyan;

};

#endif /* !COLOR_HH_ */
