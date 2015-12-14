//
// AMenuElement.cpp for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Sat Dec  5 07:30:19 2015 Serge Heitzler
// Last update Wed Dec  9 13:41:41 2015 Nicolas Girardot
//

#include <iostream>
#include <AMenuElement.hh>

AMenuElement::AMenuElement()
{
  _sprite = new Sprite();
}

AMenuElement::~AMenuElement()
{

}

void			AMenuElement::render()
{

}

void			AMenuElement::updateOnMove(std::pair<unsigned int, unsigned int> pair)
{
  (void)pair;
}

bool			AMenuElement::updateOnPress(std::pair<unsigned int, unsigned int> pair)
{
  (void)pair;
  return true;
}

void			AMenuElement::updateOnRelease(std::pair<unsigned int, unsigned int> pair)
{
	(void)pair;
}

void			AMenuElement::setBind(sf::Event event)
{
	(void)event;
}

Sprite			&AMenuElement::getSprite()
{
  return *_sprite;
}
