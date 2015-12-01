//
// InputManager.hh for InputManager in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Wed Nov 25 05:31:24 2015 Serge Heitzler
// Last update Mon Nov 30 08:47:33 2015 Serge Heitzler
//

#ifndef INPUTMANAGER_HH_
#define INPUTMANAGER_HH_

#include "IInputManager.hh"

typedef enum InputType
  {
    MENU_INPUT,
    GAME_INPUT
  };

class	        InputManager : public IInputManager
{

  InputManager(InputType inputType);
  ~InputManager();

  bool						isMouseInWindow(IVector2 posMouse);
  int						moveXAxis(sf::Event& event, int mousePosX, int ratioXMovement);
  int						moveYAxis(sf::Event& event, int mousePosY, int ratioYMovement);
  std::map<unsigned int, unsigned int>		joystickMovedInMenuAt(sf::Event& event);
  std::map<unsigned int, unsigned int>		mouseMovedInMenuAt(sf::Event& event);
  std::map<unsigned int, unsigned int>		joystickPressedInMenuAt(sf::Event& event);
  std::map<unsigned int, unsigned int>		joystickPressedAt(sf::Event& event);
  void						joystickHardwareEvent(IRenderWindow &window, sf::Event& event);

private:
  
  typedef std::map<sf::Event, funcs>PointersOnFuncs;
  typedef void(IInputManager::*funcs)(APanel &panel);
  funcs _ptr;
  PointersOnFuncs	        _functions;

};

#endif /* !INPUTMANAGER_HH_ */
