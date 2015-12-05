//
// InputManager.hh for InputManager in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Wed Nov 25 05:31:24 2015 Serge Heitzler
// Last update Sat Dec  5 03:58:32 2015 Serge Heitzler
//

#ifndef INPUTMANAGER_HH_
#define INPUTMANAGER_HH_

#include "IInputManager.hh"

typedef enum					InputType
  {
    MENU_INPUT,
    GAME_INPUT
  }						InputType;

class					        InputManager : public IInputManager
{

public:

  InputManager(InputType inputType);
  ~InputManager();

  std::pair<unsigned int, unsigned int>        	joystickPressedAt(sf::Event &event);
  std::pair<unsigned int, unsigned int>        	joystickMovedInDirection(sf::Event &event);
  bool						isMouseInWindow(Vector2 posMouse);
  int						moveXAxis(sf::Event& event, int mousePosX, int ratioXMovement);
  int						moveYAxis(sf::Event& event, int mousePosY, int ratioYMovement);
  std::pair<unsigned int, unsigned int>		joystickMovedInMenuAt(sf::Event& event);
  std::pair<unsigned int, unsigned int>		mouseMovedInMenuAt(sf::Event& event);
  std::pair<unsigned int, unsigned int>		mouseInMenuPressedAt(sf::Event& event);
  std::pair<unsigned int, unsigned int>		joystickPressedInMenuAt(sf::Event& event);
  std::pair<unsigned int, unsigned int>	       	joystickHardwareEvent(sf::Event& event);
  void						methodChecker(sf::Event &event);

private:

  typedef std::pair<unsigned int, unsigned int>(InputManager::*funcs)(sf::Event &event);
  funcs _ptr;
  typedef std::map<sf::Event::EventType, funcs>PointersOnFuncs;
  PointersOnFuncs	        _functions;

};

#endif /* !INPUTMANAGER_HH_ */
