//
// RenderWindow.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Mon Nov 23 08:18:41 2015 Serge Heitzler
// Last update Wed Dec  2 05:30:46 2015 Serge Heitzler
//

#ifndef RENDERWINDOW_HH_
#define RENDERWINDOW_HH_

#include <stack>
#include "Settings.hh"
#include "IRenderWindow.hh"
#include "PanelFactory.hh"
#include "IVector2.hh"
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
  IVector2    	getSize() const;
  void		setVerticalSyncEnabled(bool value);
  void		setMouseCursorVisible(bool value);
  void		setKeyRepeatEnabled(bool value);
  void		display();
  void		draw(const sf::Drawable &drawable, const sf::RenderStates &states = sf::RenderStates::Default);
  void		clear(const sf::Color &color = sf::Color(0, 0, 0, 255));
  void      addPanel(PanelFactory::PanelType);
  void      back();
  Settings	*getSettings();
  void		setSettings(Settings*);

private:
	static RenderWindow *_renderWindow;
	RenderWindow(sf::VideoMode mode, const std::string &title, uint32_t style = sf::Style::Default, const sf::ContextSettings& settings = sf::ContextSettings());
	
  sf::RenderWindow	*_window;
  std::stack<APanel*>   _panels;
  Settings		*_settings;
  //Size		_size;
  //PanelFactory	_panelFactory;
};

#endif /* !RENDERWINDOW_HH_ */
