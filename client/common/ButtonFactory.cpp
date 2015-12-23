//
// ButtonFactory.cpp for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Mon Dec  7 03:02:01 2015 Serge Heitzler
// Last update Sun Dec 27 08:15:15 2015 Serge Heitzler
//

#include <iostream>
#include <ButtonFactory.hh>

void			ButtonFactory::create(Vector2 pos, std::string &title)
{
  Button		*button = new Button();
  Text		       	*text = new Text();

  text->setString(title);
  text->setSize(25);
  text->setStyle(1);
  text->setOrigin(text->getText().getGlobalBounds().width / 2, text->getText().getGlobalBounds().height / 2);
  text->setPosition(pos);
  text->setColor(Color::WHITE);

  button->setState(Button::StateButton::NORMAL);

  button->getSprite().setTexture(*(RenderWindow::getInstance())->_ressources->_buttonNormal);
  button->getSprite().scale(0.7);
  button->getSprite().setOrigin((RenderWindow::getInstance())->_ressources->_buttonNormal->getSize()._x / 2, (RenderWindow::getInstance())->_ressources->_buttonNormal->getSize()._y / 2);
  button->getSprite().setPosition(pos._x, pos._y);

  (RenderWindow::getInstance())->getPanels().top()->getUserInterface().push_back(button);

  (RenderWindow::getInstance())->getPanels().top()->getLabels().push_back(*text);

}

Slider			*ButtonFactory::createSlider(Vector2 pos, std::string& title, float xmin, float xmax)
{
  Slider		*button = new Slider(title);

  button->setState(Button::StateButton::NORMAL);

  button->setLimit(xmin, xmax);
  button->getSprite().setTexture(*(RenderWindow::getInstance())->_ressources->_sliderNormal);
  button->getSprite().scale(0.7);
  button->getSprite().setOrigin((RenderWindow::getInstance())->_ressources->_sliderNormal->getSize()._x / 2, (RenderWindow::getInstance())->_ressources->_sliderNormal->getSize()._y / 2);
  button->getSprite().setPosition(pos._x, pos._y);

  (RenderWindow::getInstance())->getPanels().top()->getUserInterface().push_back(button);

  (RenderWindow::getInstance())->getPanels().top()->getLabels().push_back(Text());
  return (button);
}

void			ButtonFactory::createKeyButton(Vector2 pos, std::string &title, unsigned int id)
{
  KeyButton		*button = new KeyButton();
  Text		       	*text = new Text();

  text->setString(title);
  button->setId(id);
  text->setSize(25);
  text->setStyle(1);
  text->setOrigin(text->getText().getGlobalBounds().width / 2, text->getText().getGlobalBounds().height / 2);
  text->setPosition(pos);
  text->setColor(Color::WHITE);

  button->setState(Button::StateButton::NORMAL);

  button->getSprite().setTexture(*(RenderWindow::getInstance())->_ressources->_keyButtonNormal);
  button->getSprite().scale(0.7);
  button->getSprite().setOrigin((RenderWindow::getInstance())->_ressources->_keyButtonNormal->getSize()._x / 2, (RenderWindow::getInstance())->_ressources->_keyButtonNormal->getSize()._y / 2);
  button->getSprite().setPosition(pos._x, pos._y);
  (RenderWindow::getInstance())->getPanels().top()->getUserInterface().push_back(button);

  (RenderWindow::getInstance())->getPanels().top()->getLabels().push_back(*text);

}
