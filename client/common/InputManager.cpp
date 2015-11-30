//
// InputManager.cpp for InputManager in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Wed Nov 25 05:52:02 2015 Serge Heitzler
// Last update Mon Nov 30 06:34:28 2015 Serge Heitzler
//

#include "InputManager.hh"

/* SFML X AXIS AND Y AXIS REVERSED */

inputmanager::inputmanager(InputType type)
{
  if (type == InputType::MENU_INPUT)
    {
      _functions.insert(std::make_pair(sf::Event::JoystickButtonPressed, &InputManager::joystickPressedInMenuAt));
      _functions.insert(std::make_pair(sf::Event::MouseButtonPressed, &InputManager::mouseButtonInMenuPressedAt));
      _functions.insert(std::make_pair(sf::Event::JoystickMoved, &InputManager::joystickMovedInMenuAt));
      _functions.insert(std::make_pair(sf::Event::MouseMoved, &InputManager::mouseMovedInMenudAt));
    }
  else
    {
      
      //_functions.insert(std::make_pair(sf::Event::KeyPressed, &InputManager::?));
    }
}

InputManager::~InputManager()
{

}

bool						InputManager::isMouseInWindow(IVector2 posMouse)
{
  if (posMouse.x >= 0 && posMouse.x < window.getSize().x
      && posMouse.y >= 0 && posMouse.y < window.getSize().y)
    return true;
  return false;
}

int						InputManager::moveXAxis(sf::Event& event, int mousePosX, int ratioXMovement)
{
  std::cout << "Y axis moved!" << std::endl;
  std::cout << "new position: " << event.joystickMove.position << std::endl;
  if (event.joystickMove.position < 0)
    newPosX = mousePosX - ratioXMovement;
  else
    newPosX = mousePosX + ratioXMovement;  
}

int						InputManager::moveYAxis(sf::Event& event, int mousePosY, int ratioYMovement)
{
  std::cout << "X axis moved!" << std::endl;
  std::cout << "new position: " << event.joystickMove.position << std::endl;
  if (event.joystickMove.position < 0)
    return (mousePosY - ratioYMovement);
  else
    return (mousePosY + ratioYMovement);
}

std::map<unsigned int, unsigned int>		InputManager::joystickMovedInMenuAt(sf::Event& event)
{
  IVector2	globalPosition = sf::Mouse::getPosition();
  int		newPosX = globalPosition.x;
  int		newPosY = globalPosition.y;
  int		ratioXMovement = window.getSize().x / 100; // ratio avec la vélocité du déplacement à voir (si j'appuie fort ou doucement sur le joystic de déplacement)
  int		ratioYMovement = window.getSize().y / 100;

  if (this->isMouseInWindow(globalPosition))
    {
      if (event.joystickMove.axis == sf::Joystick::X)
	newPosY = this->moveYAxis(event, newPosY, ratioYMovement);
      if (event.joystickMove.axis == sf::Joystick::Y)
	newPosX = this->moveXAxis(event, newPosX, ratioXMovement);
    }
  return std::make_pair(newPosX, newPosY);
}

std::map<unsigned int, unsigned int>		InputManager::mouseMovedInMenuAt(sf::Event& event)
{
  return std::make_pair(event.mouseMove.x, event.mouseMove.y);
}

std::map<unsigned int, unsigned int>		InputManager::joystickPressedAt(sf::Event& event)
{
  IVector2 globalPosition = sf::Mouse::getPosition();
  return std::make_pair(globalPosition.x, globalPosition.y);
}

void						InputManager::joystickHardwareEvent(IRenderWindow &window, sf::Event& event)
{
  // changer la texture du controller à display
}















/* ACTION ON EVENT

  //  sf::Mouse:setPosition(IVector2());

  if (sf::Joystick::isConnected(0))
    {
      // joystick number 0 is connected
    }
  else
    {

    }
*/
