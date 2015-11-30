//
// IRenderWindow.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Mon Nov 23 08:20:13 2015 Serge Heitzler
// Last update Wed Nov 25 06:33:30 2015 Serge Heitzler
//

#ifndef IRENDERWINDOW_HH_
#define IRENDERWINDOW_HH_

#include <string>
#include <SFML/Graphics.hpp>
#include "IVideoMode.hh"
#include "IVector2u.hh"

class  		      IRenderWindow
{

  IRenderWindow();
  ~IRenderWindow();

  virtual void		create(IVideoMode mode, const std::string&, Uint32, const contextSettings&) = 0;
  virtual void		close() = 0;
  virtual bool		isOpen() = 0;
  virtual bool		pollEvent(sf::Event& event) = 0;
  virtual bool	        waitEvent(sf::Event& event) = 0;
  virtual IVector2    	getSize() = 0;
  virtual void		SetVerticalSyncEnabled(bool value) = 0;
  virtual void		setMouseCursorVisible(bool value) = 0;
  virtual void		setKeyRepeatRepeatEnabled(bool value) = 0;
  virtual void		display() = 0;
  
};

#endif /* !IRENDERWINDOW_HH_ */
