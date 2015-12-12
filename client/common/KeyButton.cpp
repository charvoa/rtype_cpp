#include "KeyButton.hh"
#include "RenderWindow.hh"



KeyButton::KeyButton()
{
/*	_keyString["0"] = sf::Keyboard::Num0;
	_keyString["1"] = sf::Keyboard::Num1;
	_keyString["2"] = sf::Keyboard::Num2;
	_keyString["3"] = sf::Keyboard::Num3;
	_keyString["4"] = sf::Keyboard::Num4;
	_keyString["5"] = sf::Keyboard::Num5;
	_keyString["6"] = sf::Keyboard::Num6;
	_keyString["7"] = sf::Keyboard::Num7;
	_keyString["8"] = sf::Keyboard::Num8;
	_keyString["9"] = sf::Keyboard::Num9;
	_keyString["0"] = sf::Keyboard::Num0;
	_keyString["UP"] = sf::Keyboard::Up;
	_keyString["DOWN"] = sf::Keyboard::Down;
	_keyString["LEFT"] = sf::Keyboard::Left;
	_keyString["RIGHT"] = sf::Keyboard::Right;
	_keyString["SPACE"] = sf::Keyboard::Space;
	_keyString["ESCAPE"] = sf::Keyboard::Escape;
	_keyString["RETURN"] = sf::Keyboard::Return;
	_keyString["A"] = sf::Keyboard::A;
	_keyString["Z"] = sf::Keyboard::Z;
	_keyString["E"] = sf::Keyboard::E;
	_keyString["R"] = sf::Keyboard::R;
	_keyString["T"] = sf::Keyboard::T;
	_keyString["Y"] = sf::Keyboard::Y;
	_keyString["U"] = sf::Keyboard::U;
	_keyString["I"] = sf::Keyboard::I;
	_keyString["O"] = sf::Keyboard::O;
	_keyString["P"] = sf::Keyboard::P;
	_keyString["Q"] = sf::Keyboard::Q;
	_keyString["S"] = sf::Keyboard::S;
	_keyString["D"] = sf::Keyboard::D;
	_keyString["F"] = sf::Keyboard::F;
	_keyString["G"] = sf::Keyboard::G;
	_keyString["H"] = sf::Keyboard::H;
	_keyString["J"] = sf::Keyboard::J;
	_keyString["K"] = sf::Keyboard::K;
	_keyString["L"] = sf::Keyboard::L;
	_keyString["M"] = sf::Keyboard::M;
	_keyString["W"] = sf::Keyboard::W;
	_keyString["X"] = sf::Keyboard::X;
	_keyString["C"] = sf::Keyboard::C;
	_keyString["V"] = sf::Keyboard::V;
	_keyString["B"] = sf::Keyboard::B;
	_keyString["N"] = sf::Keyboard::N;
	_keyString["NUMPAD 0"] = sf::Keyboard::Numpad0;
	_keyString["NUMPAD 1"] = sf::Keyboard::Numpad1;
	_keyString["NUMPAD 2"] = sf::Keyboard::Numpad2;
	_keyString["NUMPAD 3"] = sf::Keyboard::Numpad3;
	_keyString["NUMPAD 4"] = sf::Keyboard::Numpad4;
	_keyString["NUMPAD 5"] = sf::Keyboard::Numpad5;
	_keyString["NUMPAD 6"] = sf::Keyboard::Numpad6;
	_keyString["NUMPAD 7"] = sf::Keyboard::Numpad7;
	_keyString["NUMPAD 8"] = sf::Keyboard::Numpad8;
	_keyString["NUMPAD 9"] = sf::Keyboard::Numpad9;

	_joystickString["UP"] = JoystickEvent(sf::Joystick::X);
	_joystickString["DOWN"] = JoystickEvent(sf::Joystick::X);
	_joystickString["LEFT"] = JoystickEvent(sf::Joystick::Y);
	_joystickString["RIGHT"] = JoystickEvent(sf::Joystick::Y);
	_joystickString["X"] = JoystickEvent(0);
	_joystickString["Y"] = JoystickEvent(2);
	_joystickString["A"] = JoystickEvent(1);
	_joystickString["B"] = JoystickEvent(3);
	_joystickString["L1"] = JoystickEvent(sf::Joystick::Z);
	_joystickString["L2"] = JoystickEvent(sf::Joystick::Z);
	_joystickString["R1"] = JoystickEvent(sf::Joystick::R);
	_joystickString["R2"] = JoystickEvent(sf::Joystick::R);*/
	_waiting = false;
	_sprite->setTexture(*(RenderWindow::getInstance())->_ressources->_buttonNormal);
}


KeyButton::~KeyButton()
{
}

void		KeyButton::setTitle(std::string const& title)
{
	_title = title;
	_waiting = false;
}

void		KeyButton::setState(Button::StateButton state)
{
	_state = state;
}

bool		KeyButton::updateOnPress(std::pair<unsigned int, unsigned int> pair)
{
	std::pair<std::pair<unsigned int, unsigned int>, std::pair<unsigned int, unsigned int>> rect = this->getSprite().getGlobalBounds();

	if (pair.first >= rect.first.first && pair.first <= (rect.first.first + rect.second.first) && pair.second >= rect.first.second && pair.second <= (rect.first.second + rect.second.second))
		_waiting = true;
	else
		_waiting = false;
	return false;
}

void		KeyButton::render()
{

}