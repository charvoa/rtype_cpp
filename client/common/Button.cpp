//
// Button.cpp for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Thu Dec  3 13:22:09 2015 Serge Heitzler
// Last update Mon Dec  7 01:44:45 2015 Serge Heitzler
//

#include <iostream>
#include "Button.hh"

Button::Button(Vector2 pos, Vector2 size, const std::string &title, const std::string &normal, const std::string &highlight, const std::string &select)
{
  _normal = new Texture();
  _highlight = new Texture();
  _select = new Texture();
  _title = new Text();
  
  this->setTitle(title);
  this->setState(StateButton::NORMAL);
  _normal->loadFromFile(normal);
  _highlight->loadFromFile(highlight);
  _select->loadFromFile(select);
  
  _sprite->setTexture(*_normal);
  _sprite->scale(1.8);
  _sprite->setOrigin(size._x / 2, size._y / 2);
  _sprite->setPosition(pos._x, pos._y);
  //_sprite->setTextureRect(pos._x, pos._y, size._x, size._y);
  std::cout << pos._x << " " << pos._y << " " << size._x << " " << size._y << " " << std::endl;
}

Button::~Button()
{

}

void			Button::setState(StateButton state)
{
  _state = state;
}

void			Button::setTitle(const std::string &title)
{
  _title->setString(title);
}

Texture			&Button::getNormalTexture()
{
  return *_normal;
}

// Texture			&Button::getHighlightTexture()
// {
//   return *_highlight;
// }

Texture			&Button::getSelectTexture()
{
  return *_select;
}

void			Button::update(std::pair<unsigned int, unsigned int> pair)
{
  std::pair<std::pair<unsigned int, unsigned int>, std::pair<unsigned int, unsigned int>> rect = this->getSprite().getGlobalBounds();
  
  if (pair.first >= rect.first.first && pair.first <= (rect.first.first + rect.second.first) && pair.second >= rect.first.second && pair.second <= (rect.first.second + rect.second.second))
    this->getSprite().setTexture(this->getHighlightTexture());
  else
    this->getSprite().setTexture(this->getNormalTexture());
}

void			Button::render()
{

}
