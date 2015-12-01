//
// Color.cpp for rtype in /home/nicolas/rendu/rtype_cpp/client/common
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Mon Nov 30 16:56:12 2015 Nicolas Girardot
// Last update Mon Nov 30 16:59:39 2015 Nicolas Girardot
//

#include "Color.hh"

sf::Color		Color::_black = sf::Color::Black;
sf::Color		Color::_white = sf::Color::White;
sf::Color		Color::_red = sf::Color::Red;
sf::Color		Color::_green = sf::Color::Green;
sf::Color		Color::_blue = sf::Color::Blue;
sf::Color		Color::_yellow = sf::Color::Yellow;
sf::Color		Color::_magenta = sf::Color::Magenta;
sf::Color		Color::_cyan = sf::Color::Cyan;


Color::Color()
{

}

Color::~Color()
{

}

sf::Color	Color::getColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
  return (sf::Color(r, g, b, a));
}
