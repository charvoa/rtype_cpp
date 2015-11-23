#ifndef FONT_HH_
#define FONT_HH_

#include <SFML/Graphics.hpp>
#include <string>

class	        Font
{

  Font();
  ~Font();

  void		loadFromFile(const std::string &filename);

public:
  
  sf::Font	_font;

};

#endif /* !FONT_HH_ */
