//
// Font.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Mon Nov 23 08:19:43 2015 Serge Heitzler
// Last update Thu Dec  3 21:30:48 2015 Nicolas Girardot
//

#ifndef FONT_HH_
#define FONT_HH_

#include <SFML/Graphics.hpp>
#include <string>
#include "IFont.hh"

class	        Font : public IFont
{
public:
  Font();
  Font(const std::string &filename);
  ~Font();

  void		loadFromFile(const std::string &filename);
  sf::Font     	getFont();

public:

  sf::Font	_font;

};

#endif /* !FONT_HH_ */
