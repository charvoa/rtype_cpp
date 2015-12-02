//
// Text.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Mon Nov 23 08:18:36 2015 Serge Heitzler
// Last update Wed Dec  2 02:22:28 2015 Serge Heitzler
//

#ifndef TEXT_HH_
#define TEXT_HH_

#include <SFML/Graphics.hpp>
#include <string>
#include "IText.hh"
#include "IFont.hh"
#include "IColor.hh"

class	        Text : public IText
{

  Text();
  Text(const String &string, const IFont &font, unsigned int characterSize=30);
  ~Text();

  void			setFont(IFont& font);
  void			setColor(IColor& color);
  void			setSize(unsigned int size);
  void			setString(const std::string& title);

private :

  const std::string&	_string;
  sf::Text		_text;

};

#endif /* !TEXT_HH_ */
