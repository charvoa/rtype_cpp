//
// Button.cpp for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Thu Dec  3 13:22:09 2015 Serge Heitzler
// Last update Tue Dec  8 05:05:35 2015 Serge Heitzler
//

#include <iostream>
#include "Button.hh"

Button::Button()
{
  _normal = new Texture();
  _highlight = new Texture();
  _select = new Texture();
}

Button::~Button()
{

}

void			Button::setState(StateButton state)
{
  _state = state;
}

Texture			&Button::getNormalTexture()
{
  return *_normal;
}

Texture			&Button::getHighlightTexture()
{
  return *_highlight;
}

Texture			&Button::getSelectTexture()
{
  return *_select;
}

void			Button::updateOnMove(std::pair<unsigned int, unsigned int> pair)
{
  std::pair<std::pair<unsigned int, unsigned int>, std::pair<unsigned int, unsigned int>> rect = this->getSprite().getGlobalBounds();
  
  if (pair.first >= rect.first.first && pair.first <= (rect.first.first + rect.second.first) && pair.second >= rect.first.second && pair.second <= (rect.first.second + rect.second.second))
    this->getSprite().setTexture(this->getHighlightTexture());
  else
    this->getSprite().setTexture(this->getNormalTexture());
}

bool			Button::updateOnPress(std::pair<unsigned int, unsigned int> pair)
{
  std::pair<std::pair<unsigned int, unsigned int>, std::pair<unsigned int, unsigned int>> rect = this->getSprite().getGlobalBounds();
  
  if (pair.first >= rect.first.first && pair.first <= (rect.first.first + rect.second.first) && pair.second >= rect.first.second && pair.second <= (rect.first.second + rect.second.second))
    {
      this->getSprite().setTexture(this->getHighlightTexture());
      return true;
    }
  else
    {
      this->getSprite().setTexture(this->getNormalTexture());
      return false;
    }
}

void			Button::render()
{

}
