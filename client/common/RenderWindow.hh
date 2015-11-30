//
// RenderWindow.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Mon Nov 23 08:18:41 2015 Serge Heitzler
<<<<<<< HEAD
// Last update Mon Nov 30 04:45:08 2015 Serge Heitzler
=======
// Last update Wed Nov 25 16:34:25 2015 Nicolas Girardot
>>>>>>> 02a251ffe5f072a58c677484f844235795494e85
//

#ifndef RENDERWINDOW_HH_
#define RENDERWINDOW_HH_

#include "IRenderWindow.hh"
#include "IVector2.hh"
#include "Size.hh"

class	        RenderWindow : public IRenderWindow
{
public:

  RenderWindow(sf::VideoMode mode, const std::string &title, uint32_t style = sf::Style::Default, const sf::ContextSettings& settings = sf::ContextSettings());
  ~RenderWindow();

  void		close();
  bool		isOpen();
  bool		pollEvent(sf::Event& event);
  bool	        waitEvent(sf::Event& event);
<<<<<<< HEAD
  IVector2    	getSize();
  void		SetVerticalSyncEnabled(bool value);
=======
  IVector2    	getSize() const;
  void		setVerticalSyncEnabled(bool value);
>>>>>>> 02a251ffe5f072a58c677484f844235795494e85
  void		setMouseCursorVisible(bool value);
  void		setKeyRepeatEnabled(bool value);
  void		display();
  void		draw(const sf::Drawable &drawable, const sf::RenderStates &states = sf::RenderStates::Default);
  void		clear(const sf::Color &color = sf::Color(0, 0, 0, 255));

private:

  sf::RenderWindow *_window;
  //Size		_size;
  //PanelFactory	_panelFactory;
};

#endif /* !RENDERWINDOW_HH_ */
