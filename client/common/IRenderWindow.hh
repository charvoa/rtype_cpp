//
// IRenderWindow.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Mon Nov 23 08:20:13 2015 Serge Heitzler
// Last update Tue Dec  1 11:43:28 2015 Nicolas Girardot
//

#ifndef IRENDERWINDOW_HH_
#define IRENDERWINDOW_HH_

#include <string>
#include <cstdint>
#include <SFML/Window/ContextSettings.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include "IVideoMode.hh"
#include "Vector2.hh"

class  		      IRenderWindow
{
public:
  virtual void		close() = 0;
  virtual bool		isOpen() = 0;
  virtual void		clear(const sf::Color& color) = 0;
  virtual bool		pollEvent(sf::Event& event) = 0;
  virtual bool	        waitEvent(sf::Event& event) = 0;
  virtual IVector2    	getSize() const = 0;
  virtual void		setVerticalSyncEnabled(bool value) = 0;
  virtual void		setMouseCursorVisible(bool value) = 0;
  virtual void		setKeyRepeatEnabled(bool value) = 0;
  virtual void		display() = 0;
  virtual void		draw(const sf::Drawable &drawable, const sf::RenderStates &states) = 0;
};

#endif /* !IRENDERWINDOW_HH_ */
