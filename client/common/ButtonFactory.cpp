//
// ButtonFactory.cpp for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Mon Dec  7 03:02:01 2015 Serge Heitzler
// Last update Sat Dec 12 06:23:27 2015 Serge Heitzler
//

#include <iostream>
#include <Slider.hh>
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

void			ButtonFactory::createSlider(Vector2 pos)
{
	Slider		*button = new Slider();

	button->setState(Button::StateButton::NORMAL);

	button->getSprite().setTexture(*(RenderWindow::getInstance())->_ressources->_buttonNormal);
	button->getSprite().scale(0.7);
	button->getSprite().setOrigin((RenderWindow::getInstance())->_ressources->_buttonNormal->getSize()._x / 2, (RenderWindow::getInstance())->_ressources->_buttonNormal->getSize()._y / 2);
	button->getSprite().setPosition(pos._x, pos._y);

	(RenderWindow::getInstance())->getPanels().top()->getUserInterface().push_back(button);

	(RenderWindow::getInstance())->getPanels().top()->getLabels().push_back(Text());
}
