//
// Font.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Mon Nov 23 08:19:43 2015 Serge Heitzler
// Last update Tue Nov 24 04:45:41 2015 Serge Heitzler
//

#ifndef FONT_HH_
#define FONT_HH_

#include <SFML/Graphics.hpp>
#include <string>

class	        Font : public IFont
{

  Font();
  ~Font();

  void		loadFromFile(const std::string &filename);

public:
  
  sf::Font	_font;

};

#endif /* !FONT_HH_ */
