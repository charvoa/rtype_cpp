//
// InputManager.cpp for rtype in /home/nicolas/rendu/rtype_cpp/client/build
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Tue Dec  8 11:12:47 2015 Nicolas Girardot
// Last update Thu Dec 17 17:38:13 2015 Nicolas Girardot
//

#include <iostream>
#include <InputManager.hh>
#include <RenderWindow.hh>
#include <SFML/Config.hpp>
#include <Client.hh>
#include <CreateRequest.hpp>
#include <CRC.hpp>
#include <ANetwork.hpp>
#include <JoinPanel.hh>
#include <GamePanel.hh>

/* SFML X AXIS AND Y AXIS REVERSED */

extern std::string g_a;

InputManager::InputManager(){}

InputManager::~InputManager(){}

void			InputManager::setInputType(InputType type)
{

  _functions.insert(std::make_pair(sf::Event::JoystickConnected, &InputManager::joystickHardwareEvent));
  _functions.insert(std::make_pair(sf::Event::JoystickDisconnected, &InputManager::joystickHardwareEvent));

  if (type == InputType::SETTINGS_INPUT)
  {
    _functions.insert(std::make_pair(sf::Event::MouseButtonPressed, &InputManager::mouseInMenuPressedAt));
    _functions.insert(std::make_pair(sf::Event::MouseButtonReleased, &InputManager::dropSlider));
    _functions.insert(std::make_pair(sf::Event::KeyPressed, &InputManager::keyEntered));
    _functions.insert(std::make_pair(sf::Event::MouseMoved, &InputManager::mouseMovedInMenuAt));
  }
  if (type == InputType::MENU_INPUT || type == InputType::JOIN_INPUT)
    {
      _functions.insert(std::make_pair(sf::Event::JoystickButtonPressed, &InputManager::joystickPressedInMenuAt));
      _functions.insert(std::make_pair(sf::Event::MouseButtonPressed, &InputManager::mouseInMenuPressedAt));
      _functions.insert(std::make_pair(sf::Event::JoystickMoved, &InputManager::joystickMovedInMenuAt));
      _functions.insert(std::make_pair(sf::Event::MouseMoved, &InputManager::mouseMovedInMenuAt));
    }
  if (type == InputType::JOIN_INPUT)
    {
      _functions.insert(std::make_pair(sf::Event::KeyPressed, &InputManager::textEnteredInJoinPanel));
    }
  if (type == InputType::GAME_INPUT)
    {
      _functions.insert(std::make_pair(sf::Event::MouseButtonPressed, &InputManager::mouseInMenuPressedAt));
      _functions.insert(std::make_pair(sf::Event::MouseMoved, &InputManager::mouseMovedInMenuAt));
    }

}


std::pair<unsigned int, unsigned int>   		InputManager::keyPressedInGame()
{
  RenderWindow *window = RenderWindow::getInstance();
  int i = 0;
  //std::cout << "KEY " << event.key.code << std::endl;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && !static_cast<GamePanel*>(window->getPanels().top())->getEscapeMenu())
    static_cast<GamePanel*>(window->getPanels().top())->setEscapeMenu(true);
  if (!static_cast<GamePanel*>(window->getPanels().top())->getEscapeMenu())
    {
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	i += 8;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	i += 2;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	i += 4;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	i += 1;
      if (i != 0)
	{
	  ANetwork *net = Client::getUDPNetwork();
	  ANetwork::t_frame sender = CreateRequest::create((unsigned char)C_MOVE, CRC::calcCRC(std::to_string(i)), 0, std::to_string(i));
	  net->write(sender);
	}
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
	  ANetwork *net = Client::getUDPNetwork();
	  ANetwork::t_frame sender = CreateRequest::create((unsigned char)C_SHOOT, CRC::calcCRC("E_RIFLE"), 0, "E_RIFLE");
	  net->write(sender);
	}
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
	  std::cout << "Shooting A" << std::endl;
	  // ANetwork *net = Client::getUDPNetwork();
	  // ANetwork::t_frame sender = CreateRequest::create((unsigned char)C_SHOOT, CRC::calcCRC("E_RIFLE"), 0, "E_RIFLE");
	  // net->write(sender);
	}
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
	  std::cout << "Shooting E" << std::endl;
	  // ANetwork *net = Client::getUDPNetwork();
	  // ANetwork::t_frame sender = CreateRequest::create((unsigned char)C_SHOOT, CRC::calcCRC("E_RIFLE"), 0, "E_RIFLE");
	  // net->write(sender);
	}
    }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Tab))
    {
      RenderWindow *window = RenderWindow::getInstance();
      static_cast<GamePanel*>(window->getPanels().top())->addExplosion();
    }
  return std::make_pair(0, 0);
}

std::pair<unsigned int, unsigned int>		InputManager::joystickPressedAt(sf::Event& event)
{
  (void)event;

  std::cout << "joy key " << event.joystickButton.button << std::endl;

  return std::make_pair(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
}

std::pair<unsigned int, unsigned int>   		InputManager::joystickMovedInDirection()
{
  float posX = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
  float posY = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);

  int i = 0;

  /* X POSITION JOYSTICK */
  if (posX > -25 && posX < 25)
    i += 0;
  if (posX > 25)
    i += 2;
  if (posX < -25)
    i += 8;


  /* Y POSITION JOYSTICK */
  if (posY > -25 && posY < 25)
    i += 0;
  if (posY > 25)
    i += 4;
  if (posY < -25)
    i += 1;


  if (sf::Joystick::isButtonPressed(0, 0))
  {
    ANetwork *net = Client::getUDPNetwork();
    ANetwork::t_frame sender = CreateRequest::create((unsigned char)C_SHOOT, CRC::calcCRC("E_RIFLE"), 0, "E_RIFLE");
    net->write(sender);
    return std::make_pair(0, 0);
  }

  if (i != 0)
    {
      ANetwork *net = Client::getUDPNetwork();
      ANetwork::t_frame sender = CreateRequest::create((unsigned char)C_MOVE, CRC::calcCRC(std::to_string(i)), 0, std::to_string(i));
      net->write(sender);
    }

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
	newPosX = this->moveXAxis(event, newPosX, ratioXMovement);
      if (event.joystickMove.axis == sf::Joystick::Y)
	newPosY = this->moveYAxis(event, newPosY, ratioYMovement);
    }


  sf::Mouse::setPosition(sf::Vector2i(newPosX, newPosY));
  return std::make_pair((unsigned int)newPosX, (unsigned int)newPosY);
}

std::pair<unsigned int, unsigned int>		InputManager::mouseMovedInMenuAt(sf::Event& event)
{
  (RenderWindow::getInstance())->getPanels().top()->updateOnMove(std::make_pair((unsigned int)event.mouseMove.x, (unsigned int)event.mouseMove.y));

  return std::make_pair((unsigned int)event.mouseMove.x, (unsigned int)event.mouseMove.y);
}

std::pair<unsigned int, unsigned int>		InputManager::mouseInMenuPressedAt(sf::Event& event)
{

  if ((RenderWindow::getInstance())->getPanels().top()->updateOnPress(std::make_pair((unsigned int)event.mouseButton.x, (unsigned int)event.mouseButton.y)))
    {
    }
  return std::make_pair((unsigned int)event.mouseButton.x, (unsigned int)event.mouseButton.y);
}

// std::pair<unsigned int, unsigned int>		InputManager::mouseInGamePressedAt(sf::Event& event)
// {

//   if ((RenderWindow::getInstance())->getPanels().top()->updateOnPressInGame(std::make_pair((unsigned int)event.mouseButton.x, (unsigned int)event.mouseButton.y)))
//     {
//     }
//   return std::make_pair((unsigned int)event.mouseButton.x, (unsigned int)event.mouseButton.y);
// }

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

std::pair<unsigned int, unsigned int>		InputManager::textEnteredInJoinPanel(sf::Event& event)
{
  if ((event.key.code >= sf::Keyboard::A && event.key.code <= sf::Keyboard::Z) || (event.key.code >= sf::Keyboard::Num0 && event.key.code <= sf::Keyboard::Num9) || event.key.code == sf::Keyboard::Return || event.key.code == sf::Keyboard::BackSpace)
    {
      RenderWindow *window = RenderWindow::getInstance();
      static_cast<JoinPanel*>(window->getPanels().top())->updateOnTextEntered(event.key.code);
    }
    return std::make_pair(0, 0);
}

void		InputManager::methodChecker(sf::Event &event)
{
  for (std::map<sf::Event::EventType, funcs>::iterator it = _functions.begin(); it != _functions.end(); ++it)
    {
      if ((*it).first == event.type)
	(*this.*_functions[event.type])(event);
    }
}

std::pair<unsigned int, unsigned int>		InputManager::dropSlider(sf::Event& event)
{
	(RenderWindow::getInstance())->getPanels().top()->updateOnRelease(std::make_pair((unsigned int)event.mouseButton.x, (unsigned int)event.mouseButton.y));
	return std::make_pair((unsigned int)event.mouseButton.x, (unsigned int)event.mouseButton.y);
}

std::pair<unsigned int, unsigned int>		InputManager::keyEntered(sf::Event& event)
{
	RenderWindow *window = RenderWindow::getInstance();
	window->getPanels().top()->setKeyButton(event);
	return std::make_pair(0, 0);
	(void) window;
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
