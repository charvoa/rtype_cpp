//
// RenderWindow.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Mon Nov 23 08:18:41 2015 Serge Heitzler
// Last update Fri Dec  4 20:22:06 2015 Nicolas Girardot
//

#ifndef RENDERWINDOW_HH_
#define RENDERWINDOW_HH_

#include <stack>
#include "Settings.hh"
#include "IRenderWindow.hh"
#include "PanelFactory.hh"
#include "Vector2.hh"
#include "Size.hh"

class	        RenderWindow : public IRenderWindow
{
public:
  ~RenderWindow();

  static RenderWindow *getInstance();
  void		close();
  bool		isOpen();
  bool		pollEvent(sf::Event& event);
  bool	        waitEvent(sf::Event& event);
  Vector2   	getSize() const;
  void		setVerticalSyncEnabled(bool value);
  void		setMouseCursorVisible(bool value);
  void		setFramerateLimit(unsigned int limit);
  void		setKeyRepeatEnabled(bool value);
  void		display();
  void		draw(const sf::Drawable &drawable, const sf::RenderStates &states = sf::RenderStates::Default);
  void		clear(const sf::Color &color = sf::Color(0, 0, 0, 255));
  void      addPanel(PanelFactory::PanelType);
  void      back();
  Settings	*getSettings();
  void		setSettings(Settings*);
  void		setWindow(sf::VideoMode, std::string const& title);

private:
  RenderWindow();
  static RenderWindow *_renderWindow;
  sf::RenderWindow	*_window;
  std::stack<APanel*>   _panels;
  Settings		*_settings;
  //Size		_size;
  //PanelFactory	_panelFactory;
};

#endif /* !RENDERWINDOW_HH_ */
