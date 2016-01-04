//
// InputManager.cpp for rtype in /home/nicolas/rendu/rtype_cpp/client/build
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Tue Dec  8 11:12:47 2015 Nicolas Girardot
// Last update Mon Jan  4 05:10:47 2016 Serge Heitzler
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
  if (type == ROOM_INPUT)
  {
    _functions.insert(std::make_pair(sf::Event::MouseButtonPressed, &InputManager::mouseInMenuPressedAt));
    _functions.insert(std::make_pair(sf::Event::MouseButtonReleased, &InputManager::dropSlider));
    _functions.insert(std::make_pair(sf::Event::MouseMoved, &InputManager::mouseMovedInMenuAt));
  }
}


std::pair<unsigned int, unsigned int>   		InputManager::keyPressedInGame()
{
  RenderWindow *window = RenderWindow::getInstance();
  int i = 0;
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
	  ANetwork *net = Client::getUDPNetwork();
	  ANetwork::t_frame sender = CreateRequest::create((unsigned char)C_SHOOT, CRC::calcCRC("E_MISSILE"), 0, "E_MISSILE");
	  net->write(sender);
	}
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	{
	  ANetwork *net = Client::getUDPNetwork();
	  ANetwork::t_frame sender = CreateRequest::create((unsigned char)C_SHOOT, CRC::calcCRC("E_LASER"), 0, "E_LASER");
	  net->write(sender);
	}
    }
  return std::make_pair(0, 0);
}

std::pair<unsigned int, unsigned int>		InputManager::joystickPressedAt(sf::Event& event)
{
  (void)event;
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

  if (sf::Joystick::isButtonPressed(0, 1))
  {
    ANetwork *net = Client::getUDPNetwork();
    ANetwork::t_frame sender = CreateRequest::create((unsigned char)C_SHOOT, CRC::calcCRC("E_MISSILE"), 0, "E_MISSILE");
    net->write(sender);
    return std::make_pair(0, 0);
  }

  if (sf::Joystick::isButtonPressed(0, 2))
  {
    ANetwork *net = Client::getUDPNetwork();
    ANetwork::t_frame sender = CreateRequest::create((unsigned char)C_SHOOT, CRC::calcCRC("E_LASER"), 0, "E_LASER");
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
  if (event.joystickMove.position < 0)
    return (mousePosX - ratioXMovement);
  else
    return (mousePosX + ratioXMovement);
}

int						InputManager::moveYAxis(sf::Event& event, int mousePosY, int ratioYMovement)
{
  if (event.joystickMove.position < 0)
    return (mousePosY - ratioYMovement);
  else
    return (mousePosY + ratioYMovement);
}

void		InputManager::joystickMovedInMenuAt()
{
  int			posX = sf::Mouse::getPosition().x;
  int			posY = sf::Mouse::getPosition().y;

  float			moveX = 0;
  float			moveY = 0;
  
    /* X POSITION JOYSTICK */
  if (posX > 25)
    moveX += 10;
  if (posX < -25)
    moveX -= 10;

  /* Y POSITION JOYSTICK */
  if (posY > 25)
    moveY += 10;
  if (posY < -25)
    moveY += 10;

  sf::Mouse::setPosition(sf::Vector2i(posX + moveX, posY + moveY));
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

std::pair<unsigned int, unsigned int>		InputManager::joystickPressedInMenuAt(sf::Event& event)
{
  (void)event;
  return std::make_pair(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);
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

std::pair<unsigned int, unsigned int>		InputManager::dropSliderDifficulty(sf::Event& event)
{
	(RenderWindow::getInstance())->getPanels().top()->difficultyUpdateOnRelease(std::make_pair((unsigned int)event.mouseButton.x, (unsigned int)event.mouseButton.y));
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
