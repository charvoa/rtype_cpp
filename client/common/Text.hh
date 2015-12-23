//
// Text.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Mon Nov 23 08:18:36 2015 Serge Heitzler
// Last update Sun Dec 27 08:02:47 2015 Serge Heitzler
//

#ifndef		TEXT_HH_
#define		TEXT_HH_

#include	<SFML/Graphics.hpp>
#include	<string>
#include	<Vector2.hh>
#include	<IText.hh>
#include	<SFont.hh>
#include	<Color.hh>
#include	<AMenuElement.hh>

class	        Text : public IText
{

public:
  Text();
  Text(const std::string &string, SFont &font, unsigned int characterSize=30);
  ~Text();

  void	       	setFont(SFont& font);
  void 		setColor(Color::Tint);
  void 		setSize(unsigned int size);
  void 		setString(const std::string& title);
  void 		setPosition(Vector2 pos);
  void 	        setOrigin(float x, float y);
  void 	        setStyle(uint32_t style);
  sf::Text     	&getText();

private :

  sf::Text     	_text;

};

#endif /* !TEXT_HH_ */
