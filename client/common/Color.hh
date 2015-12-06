//
// Color.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Mon Nov 23 08:20:04 2015 Serge Heitzler
// Last update Thu Dec  3 12:51:41 2015 Serge Heitzler
//

#ifndef COLOR_HH_
#define COLOR_HH_

#include <SFML/Graphics.hpp>
#include "IColor.hh"

class	        Color : public IColor
{
public:
  
  typedef enum Tint
    {
      BLACK,
      WHITE,
      RED,
      GREEN,
      BLUE,
      YELLOW,
      MAGENTA,
      CYAN
    }		Tint;
  
  Color();
  ~Color();
  
  static sf::Color	getColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
  static Color::Tint	blackColor();
  static Color::Tint	whiteColor();
  static Color::Tint	redColor();
  static Color::Tint	greenColor();
  static Color::Tint	blueColor();
  static Color::Tint	yellowColor();
  static Color::Tint	magentaColor();
  static Color::Tint	cyanColor();
  static sf::Color      getSFColor(Color::Tint color);

};

#endif /* !COLOR_HH_ */
