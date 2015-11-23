//
// IRenderWindow.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Mon Nov 23 08:20:13 2015 Serge Heitzler
// Last update Mon Nov 23 08:20:14 2015 Serge Heitzler
//

#ifndef IRENDERWINDOW_HH_
#define IRENDERWINDOW_HH_

#include <string>
#include <SFML/Graphics.hpp>
#include "IVideoMode.hh"
#include "IVector2u.hh"

class	        IRenderWindow
{

  IRenderWindow();
  ~IRenderWindow();

  void		create(IVideoMode mode, const std::string&, Uint32, const contextSettings&) = 0;
  void		close() = 0;
  bool		isOpen() = 0;
  bool		pollEvent(sf::Event& event) = 0;
  bool	        waitEvent(sf::Event& event) = 0;
  IVector2u    	getSize() = 0;
  void		SetVerticalSyncEnabled(bool value) = 0;
  void		setMouseCursorVisible(bool value) = 0;
  void		setKeyRepeatRepeatEnabled(bool value) = 0;
  void		display() = 0;
  
};

#endif /* !IRENDERWINDOW_HH_ */
