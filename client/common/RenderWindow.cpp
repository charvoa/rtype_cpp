//
// RenderWindow.cpp for R-TYPE in /home/nicolas/rendu/rtype_cpp/client/common
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed Nov 25 11:05:48 2015 Nicolas Girardot
// Last update Sun Dec 13 11:08:09 2015 Serge Heitzler
//

#include "RenderWindow.hh"

RenderWindow *RenderWindow::_renderWindow = NULL;
RenderWindow::RenderWindow()
{
	_settings = new Settings("../config/PersonalConfig.ini");
}

RenderWindow	*RenderWindow::getInstance()
{
  if (!_renderWindow)
    _renderWindow = new RenderWindow();
  return _renderWindow;
}

RenderWindow::~RenderWindow()
{

}

void		RenderWindow::setWindow(sf::VideoMode vm, std::string const& title)
{
  _window = new sf::RenderWindow(vm, title);
}

void		RenderWindow::setFramerateLimit(unsigned int limit)
{
  this->_window->setFramerateLimit(limit);
}

void		RenderWindow::setSettings(Settings *settings)
{
  _settings = new Settings(*settings);
}

Settings	*RenderWindow::getSettings() const
{
  return _settings;
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

Vector2	RenderWindow::getSize() const
{
  Vector2 vector(_window->getSize().x, _window->getSize().y);
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

void	RenderWindow::setActive(bool value)
{
  _window->setActive(value);
}

void    RenderWindow::addPanel(PanelFactory::PanelType type)
{
  type = type;
  //    PanelFactory factory;

    //    _panels.push(factory.createPanel(type));
    //    _panels.top()->render();
}

void    RenderWindow::back()
{
  _panels.pop();
}

std::stack<APanel*>	&RenderWindow::getPanels()
{
  return _panels;
}
