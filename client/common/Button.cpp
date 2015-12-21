//
// Button.cpp for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Thu Dec  3 13:22:09 2015 Serge Heitzler
// Last update Mon Dec 14 02:24:07 2015 Serge Heitzler
//

#include <iostream>
#include <Button.hh>
#include <Ressources.hh>
#include <RenderWindow.hh>
#include <Client.hh>

Button::Button()
{
  _sprite->setTexture(*(RenderWindow::getInstance())->_ressources->_buttonNormal);
  _hover = false;
}

Button::~Button()
{

}

void			Button::setState(StateButton state)
{
  _state = state;
}

void			Button::updateOnMove(std::pair<unsigned int, unsigned int> pair)
{
  std::pair<std::pair<unsigned int, unsigned int>, std::pair<unsigned int, unsigned int>> rect = this->getSprite().getGlobalBounds();

  if (pair.first >= rect.first.first && pair.first <= (rect.first.first + rect.second.first) && pair.second >= rect.first.second && pair.second <= (rect.first.second + rect.second.second))
    {
      if (_hover == false)
	{
	  std::cout << "In If : Hover" << std::endl;
	  Sound *s = Client::getSound();
	  s->playSound("hover");
	  _hover = true;
	}
      this->getSprite().setTexture(*(RenderWindow::getInstance())->_ressources->_buttonHighlight);
    }
  else
    {
      if (_hover == true)
	_hover = false;
      this->getSprite().setTexture(*(RenderWindow::getInstance())->_ressources->_buttonNormal);
    }
}

bool			Button::updateOnPress(std::pair<unsigned int, unsigned int> pair)
{
  std::pair<std::pair<unsigned int, unsigned int>, std::pair<unsigned int, unsigned int>> rect = this->getSprite().getGlobalBounds();

  if (pair.first >= rect.first.first && pair.first <= (rect.first.first + rect.second.first) && pair.second >= rect.first.second && pair.second <= (rect.first.second + rect.second.second))
    {
      this->getSprite().setTexture(*(RenderWindow::getInstance())->_ressources->_buttonHighlight);
      return true;
    }
  else
    {
      this->getSprite().setTexture(*(RenderWindow::getInstance())->_ressources->_buttonNormal);
      return false;
    }
}

void			Button::render()
{

}
