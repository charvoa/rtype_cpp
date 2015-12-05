//
// Color.cpp for rtype in /home/nicolas/rendu/rtype_cpp/client/common
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Mon Nov 30 16:56:12 2015 Nicolas Girardot
// Last update Thu Dec  3 13:59:20 2015 Serge Heitzler
//

#include "Color.hh"

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

Color::Tint	Color::blackColor()
{
  return (Color::Tint::BLACK);
}

Color::Tint	Color::whiteColor()
{
  return (Color::Tint::WHITE);
}

Color::Tint	Color::redColor()
{
  return (Color::Tint::RED);
}

Color::Tint	Color::greenColor()
{
  return (Color::Tint::GREEN);
}

Color::Tint	Color::blueColor()
{
  return (Color::Tint::BLUE);
}

Color::Tint	Color::yellowColor()
{
  return (Color::Tint::YELLOW);
}

Color::Tint	Color::magentaColor()
{
  return (Color::Tint::MAGENTA);
}

Color::Tint	Color::cyanColor()
{
  return (Color::Tint::CYAN);
}

sf::Color	Color::getSFColor(Color::Tint color)
{
  switch (color)
    {
    case BLACK:
      return sf::Color::Black;
    case WHITE:
      return sf::Color::White;
    case RED:
      return sf::Color::Red;
    case GREEN:
      return sf::Color::Green;
    case BLUE:
      return sf::Color::Blue;
    case YELLOW:
      return sf::Color::Yellow;
    case MAGENTA:
      return sf::Color::Magenta;
    case CYAN:
      return sf::Color::Cyan;
    default:
      return sf::Color::Transparent;
    }
}
