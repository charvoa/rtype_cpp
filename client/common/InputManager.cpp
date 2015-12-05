//
// InputManager.cpp for InputManager in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Wed Nov 25 05:52:02 2015 Serge Heitzler
// Last update Sat Dec  5 04:36:11 2015 Serge Heitzler
//

#include <iostream>
#include "InputManager.hh"
#include "RenderWindow.hh"

/* SFML X AXIS AND Y AXIS REVERSED */

InputManager::InputManager(InputType type)
{
  _functions.insert(std::make_pair(sf::Event::JoystickConnected, &InputManager::joystickHardwareEvent));
  _functions.insert(std::make_pair(sf::Event::JoystickDisconnected, &InputManager::joystickHardwareEvent));

  
  if (type == InputType::MENU_INPUT)
    {
      _functions.insert(std::make_pair(sf::Event::JoystickButtonPressed, &InputManager::joystickPressedInMenuAt));
      _functions.insert(std::make_pair(sf::Event::MouseButtonPressed, &InputManager::mouseInMenuPressedAt));
      _functions.insert(std::make_pair(sf::Event::JoystickMoved, &InputManager::joystickMovedInMenuAt));
      _functions.insert(std::make_pair(sf::Event::MouseMoved, &InputManager::mouseMovedInMenuAt));
    }
  else
    {
      _functions.insert(std::make_pair(sf::Event::JoystickButtonPressed, &InputManager::joystickPressedAt));
      _functions.insert(std::make_pair(sf::Event::JoystickMoved, &InputManager::joystickMovedInDirection));
      //      _functions.insert(std::make_pair(sf::Event::KeyPressed, &InputManager::CHOISIRUNNOMDEFONCTION));
    }
}

InputManager::~InputManager()
{

}

std::pair<unsigned int, unsigned int>   		InputManager::joystickMovedInDirection(sf::Event &event)
{
  (void)event;
  // 8 directions
  return std::make_pair(0, 0);
}

bool						InputManager::isMouseInWindow(Vector2 posMouse)
{
  RenderWindow *window = RenderWindow::getInstance();
  
  if (posMouse._x >= 0 && posMouse._x < window->getSize()._x
      && posMouse._y >= 0 && posMouse._y < window->getSize()._y)
    return true;
  return false;
}

int						InputManager::moveXAxis(sf::Event& event, int mousePosX, int ratioXMovement)
{
  std::cout << "Y axis moved!" << std::endl;
  std::cout << "new position: " << event.joystickMove.position << std::endl;
  if (event.joystickMove.position < 0)
    return (mousePosX - ratioXMovement);
  else
    return (mousePosX + ratioXMovement);
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

std::pair<unsigned int, unsigned int>		InputManager::joystickMovedInMenuAt(sf::Event& event)
{
  RenderWindow		*window = RenderWindow::getInstance();
  unsigned int		newPosX = sf::Mouse::getPosition().x;
  unsigned int		newPosY = sf::Mouse::getPosition().y;
  unsigned int		ratioXMovement = window->getSize()._x / 100;
  unsigned int		ratioYMovement = window->getSize()._y / 100;

  // TODO
  // ratio avec la vélocité du déplacement à voir (si j'appuie fort ou doucement sur le joystic de déplacement)

  if (this->isMouseInWindow(Vector2(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y)))
    {
      if (event.joystickMove.axis == sf::Joystick::X)
	newPosY = this->moveYAxis(event, newPosY, ratioYMovement);
      if (event.joystickMove.axis == sf::Joystick::Y)
	newPosX = this->moveXAxis(event, newPosX, ratioXMovement);
    }
  return std::make_pair((unsigned int)newPosX, (unsigned int)newPosY);
}

std::pair<unsigned int, unsigned int>		InputManager::mouseMovedInMenuAt(sf::Event& event)
{
  std::cout << "mouse moved at x " << event.mouseMove.x << " && y " << event.mouseMove.y << std::endl;
  return std::make_pair((unsigned int)event.mouseMove.x, (unsigned int)event.mouseMove.y);
}

std::pair<unsigned int, unsigned int>		InputManager::mouseInMenuPressedAt(sf::Event& event)
{
  std::cout << "mouse pressed at x " << event.mouseButton.x << " && y " << event.mouseButton.y << std::endl;
  return std::make_pair((unsigned int)event.mouseButton.x, (unsigned int)event.mouseButton.y);
}

std::pair<unsigned int, unsigned int>		InputManager::joystickPressedAt(sf::Event& event)
{
  (void)event;
  return std::make_pair(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
}

std::pair<unsigned int, unsigned int>		InputManager::joystickPressedInMenuAt(sf::Event& event)
{
  (void)event;
  std::cout << "joystick pressed in menu at x " << sf::Mouse::getPosition().x << " && y " << sf::Mouse::getPosition().y << std::endl;
  return std::make_pair(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
}

std::pair<unsigned int, unsigned int>		InputManager::joystickHardwareEvent(sf::Event& event)
{
  // TODO
  // changer la texture du controller à display
  if (event.type == sf::Event::JoystickConnected)
    {
      std::cout << "joystick connected" << event.joystickConnect.joystickId << std::endl;

    }

  if (event.type == sf::Event::JoystickDisconnected)
    {
      std::cout << "joystick disconnected" << event.joystickConnect.joystickId << std::endl;

    }
  return std::make_pair(0, 0);
}

void		InputManager::methodChecker(sf::Event &event)
{
  std::cout << "check: " << std::endl;
  for (std::map<sf::Event::EventType, funcs>::iterator it = _functions.begin(); it != _functions.end(); ++it)
    {
      if ((*it).first == event.type)
	(*this.*_functions[event.type])(event);
    }
}

/* ACTION ON EVENT

  //  sf::Mouse:setPosition(Vector2());

  if (sf::Joystick::isConnected(0))
    {
      // joystick number 0 is connected
    }
  else
    {

    }
*/
