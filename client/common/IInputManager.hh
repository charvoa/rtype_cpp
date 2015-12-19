//
// IIputManager.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Mon Nov 23 08:20:13 2015 Serge Heitzler
// Last update Sat Dec 19 13:19:49 2015 Serge Heitzler
//

#ifndef							IINPUTMANAGER_HH_
#define							IINPUTMANAGER_HH_

#include						<SFML/Graphics.hpp>
#include						<string>
#include						<map>
#include						"IRenderWindow.hh"
#include						"InputTypeEnum.hh"

class							IInputManager
{

public:

  virtual std::pair<unsigned int, unsigned int>        	joystickPressedAt(sf::Event &event) = 0;
  virtual std::pair<unsigned int, unsigned int>        	joystickMovedInDirection() = 0;
  virtual bool						isMouseInWindow(Vector2 posMouse) = 0;
  virtual int						moveXAxis(sf::Event& event, int mousePosX, int ratioXMovement) = 0;
  virtual int						moveYAxis(sf::Event& event, int mousePosY, int ratioYMovement) = 0;
  virtual void						joystickMovedInMenuAt() = 0;
  virtual std::pair<unsigned int, unsigned int>		mouseMovedInMenuAt(sf::Event& event) = 0;
  //  std::pair<unsigned int, unsigned int>			mouseInGamePressedAt(sf::Event& event);
  virtual std::pair<unsigned int, unsigned int>		mouseInMenuPressedAt(sf::Event& event) = 0;
  virtual std::pair<unsigned int, unsigned int>		joystickPressedInMenuAt(sf::Event& event) = 0;

private:

};

#endif							/* !IINPUTMANAGER_HH_ */
