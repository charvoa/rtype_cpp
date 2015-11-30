//
// IIputManager.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Mon Nov 23 08:20:13 2015 Serge Heitzler
// Last update Mon Nov 30 05:37:06 2015 Serge Heitzler
//

#ifndef IINPUTMANAGER_HH_
#define IINPUTMANAGER_HH_

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

class		      IInputManager
{

public:
  
  IInputManager();
  IInputManager(const std::string& pathToFile);
  ~IInputManager();

    bool						isMouseInWindow(IVector2 posMouse) = 0;
  int						moveXAxis(sf::Event& event, int mousePosX, int ratioXMovement) = 0;
  int						moveYAxis(sf::Event& event, int mousePosY, int ratioYMovement) = 0;
  std::map<unsigned int, unsigned int>		joystickMovedAt(sf::Event& event) = 0;
  std::map<unsigned int, unsigned int>		mouseMovedAt(sf::Event& event) = 0;
  std::map<unsigned int, unsigned int>		joystickPressedAt(sf::Event& event) = 0;
  std::map<unsigned int, unsigned int>		joystickHardwareEvent(IRenderWindow &window, sf::Event& event) = 0;

private:

};

#endif /* !IINPUTMANAGER_HH_ */
