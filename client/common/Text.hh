//
// Text.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Mon Nov 23 08:18:36 2015 Serge Heitzler
// Last update Thu Dec  3 13:35:19 2015 Serge Heitzler
//

#ifndef TEXT_HH_
#define TEXT_HH_

#include <SFML/Graphics.hpp>
#include <string>
#include "IText.hh"
#include "Font.hh"
#include "Color.hh"

class	        Text : public IText
{

public:
  Text(const std::string &string, Font &font, unsigned int characterSize=30);
  ~Text();

  void			setFont(Font& font);
  void			setColor(Color::Tint);
  void			setSize(unsigned int size);
  void			setString(const std::string& title);

private :

  std::string		_string;
  sf::Text		_text;
  unsigned int		_fontSize;
};

#endif /* !TEXT_HH_ */
