//
// Font.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Mon Nov 23 08:19:43 2015 Serge Heitzler
// Last update Wed Dec  2 02:12:25 2015 Serge Heitzler
//

#ifndef FONT_HH_
#define FONT_HH_

#include <SFML/Graphics.hpp>
#include <string>

class	        Font : public IFont
{

  Font();
  Font(const std::string &filename);
  ~Font();

  void		loadFromFile(const std::string &filename);
  sf::Font     	getFont();

public:
  
  sf::Font	_font;

};

#endif /* !FONT_HH_ */
