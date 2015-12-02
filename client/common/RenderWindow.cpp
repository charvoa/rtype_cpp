//
// RenderWindow.cpp for R-TYPE in /home/nicolas/rendu/rtype_cpp/client/common
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed Nov 25 11:05:48 2015 Nicolas Girardot
// Last update Tue Dec  1 11:51:35 2015 Nicolas Girardot
//

#include "RenderWindow.hh"

RenderWindow::RenderWindow(sf::VideoMode mode, const std::string &title, uint32_t style, const sf::ContextSettings& settings)
{
  _window = new sf::RenderWindow(mode, title, style, settings);
}

RenderWindow::~RenderWindow()
{

}

void RenderWindow::close()
{
  _window->close();
}

bool RenderWindow::isOpen()
{
  return (_window->isOpen());
}

bool RenderWindow::pollEvent(sf::Event& event)
{
  return (_window->pollEvent(event));
}

bool RenderWindow::waitEvent(sf::Event& event)
{
  return (_window->waitEvent(event));
}

IVector2	RenderWindow::getSize() const
{
  Vector2<int> vector(_window->getSize().x, _window->getSize().y);
  return vector;
}

void	RenderWindow::setVerticalSyncEnabled(bool value)
{
  _window->setVerticalSyncEnabled(value);
}

void	RenderWindow::setMouseCursorVisible(bool value)
{
  _window->setMouseCursorVisible(value);
}

void	RenderWindow::setKeyRepeatEnabled(bool value)
{
  _window->setKeyRepeatEnabled(value);
}

void	RenderWindow::display()
{
  _window->display();
}

void	RenderWindow::draw(const sf::Drawable &drawable, const sf::RenderStates &states)
{
  _window->draw(drawable, states);
}

void	RenderWindow::clear(const sf::Color &color)
{
  _window->clear(color);
}

void    RenderWindow::addPanel(PanelFactory::PanelType type)
{
    PanelFactory factory;

    _panels.push(factory.createPanel(type));
    (_panels.top)->render();
}

void    RenderWindow::back()
{
    _panels.pop();
    (_panels.top)->render();
}
