//
// RenderWindow.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Mon Nov 23 08:18:41 2015 Serge Heitzler
// Last update Tue Nov 24 04:45:10 2015 Serge Heitzler
//

#ifndef RENDERWINDOW_HH_
#define RENDERWINDOW_HH_

#include "IRenderWindow.hh"
#include "Size.hh"

class	        RenderWindow : public IRenderWindow
{

  RenderWindow();
  ~RenderWindow();

  void		create(IVideoMode mode, const std::string&, Uint32, const contextSettings&);
  void		close();
  bool		isOpen();
  bool		pollEvent(sf::Event& event);
  bool	        waitEvent(sf::Event& event);
  IVector2u    	getSize();
  void		SetVerticalSyncEnabled(bool value);
  void		setMouseCursorVisible(bool value);
  void		setKeyRepeatRepeatEnabled(bool value);
  void		display();

private:

  Size		_size;
  PanelFacotry	_panelFactory;
};

#endif /* !RENDERWINDOW_HH_ */
