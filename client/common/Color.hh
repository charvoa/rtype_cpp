//
// Color.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Mon Nov 23 08:20:04 2015 Serge Heitzler
// Last update Wed Dec  2 02:44:21 2015 Serge Heitzler
//

#ifndef COLOR_HH_
#define COLOR_HH_

#include <SFML/Graphics.hpp>
#include "IColor.hh"

class	        Color : public IColor
{
public:
  Color();
  ~Color();
  static sf::Color getColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);

  sf::Color		_black;
  sf::Color		_white;
  sf::Color		_red;
  sf::Color		_green;
  sf::Color		_blue;
  sf::Color		_yellow;
  sf::Color		_magenta;
  sf::Color		_cyan;

};

#endif /* !COLOR_HH_ */
