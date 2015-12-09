//
// ButtonFactory.cpp for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Mon Dec  7 03:02:01 2015 Serge Heitzler
// Last update Wed Dec  9 08:16:35 2015 Serge Heitzler
//

#include <iostream>
#include <ButtonFactory.hh>

void			ButtonFactory::create(Vector2 pos, Vector2 size, std::string &title, std::string &normal, std::string &highlight, std::string &select)
{
  Button		*button = new Button();
  Text		       	*text = new Text();
  (void)size;

  text->setString(title);
  text->setSize(25);
  text->setStyle(1);
  text->setOrigin(text->getText().getGlobalBounds().width / 2, text->getText().getGlobalBounds().height / 2);
  text->setPosition(pos);
  text->setColor(Color::WHITE);

  button->setState(Button::StateButton::NORMAL);
  button->getNormalTexture().loadFromFile(normal);
  button->getHighlightTexture().loadFromFile(highlight);
  button->getSelectTexture().loadFromFile(select);
  button->getSprite().setTexture(button->getNormalTexture());
  button->getSprite().scale(0.7);
  button->getSprite().setOrigin(button->getNormalTexture().getSize()._x / 2, button->getNormalTexture().getSize()._y / 2);
  button->getSprite().setPosition(pos._x, pos._y);

  (RenderWindow::getInstance())->getPanels().top()->getUserInterface().push_back(button);

  (RenderWindow::getInstance())->getPanels().top()->getLabels().push_back(*text);

}
