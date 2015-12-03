//
// InputManager.hh for InputManager in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Wed Nov 25 05:31:24 2015 Serge Heitzler
// Last update Thu Dec  3 15:56:14 2015 Nicolas Girardot
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

  std::map<unsigned int, unsigned int>         	joystickPressedAt(sf::Event &event);
  std::map<unsigned int, unsigned int>         	joystickMovedInDirection(sf::Event &event);
  bool						isMouseInWindow(IVector2 posMouse);
  int						moveXAxis(sf::Event& event, int mousePosX, int ratioXMovement);
  int						moveYAxis(sf::Event& event, int mousePosY, int ratioYMovement);
  std::map<unsigned int, unsigned int>		joystickMovedInMenuAt(sf::Event& event);
  std::map<unsigned int, unsigned int>		mouseMovedInMenuAt(sf::Event& event);
  std::map<unsigned int, unsigned int>		joystickPressedInMenuAt(sf::Event& event);
  std::map<unsigned int, unsigned int>	       	joystickHardwareEvent(IRenderWindow &window, sf::Event& event);
  void						methodChecker(sf::Event &event);

private:

  typedef void(IInputManager::*funcs)(APanel &panel);
  funcs _ptr;
  typedef std::map<sf::Event, funcs>PointersOnFuncs;
  PointersOnFuncs	        _functions;

};

#endif /* !INPUTMANAGER_HH_ */
