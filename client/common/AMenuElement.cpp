//
// AMenuElement.cpp for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Sat Dec  5 07:30:19 2015 Serge Heitzler
// Last update Mon Dec  7 11:10:03 2015 Serge Heitzler
//

#include <iostream>
#include "AMenuElement.hh"

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

void			AMenuElement::update(std::pair<unsigned int, unsigned int> pair)
{
  (void)pair;
}

Sprite			&AMenuElement::getSprite()
{
  return *_sprite;
}
