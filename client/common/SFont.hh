//
// Font.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Mon Nov 23 08:19:43 2015 Serge Heitzler
// Last update Tue Dec  8 07:36:17 2015 Serge Heitzler
//

#ifndef FONT_HH_
#define FONT_HH_

#include <SFML/Graphics.hpp>
#include <string>
#include "IFont.hh"

class	        SFont : public IFont
{
public:
  SFont();
  SFont(const std::string &filename);
  ~SFont();

  void		loadFromFile(const std::string &filename);
  sf::Font     	getFont();

public:

  sf::Font	_font;

};

#endif /* !FONT_HH_ */
