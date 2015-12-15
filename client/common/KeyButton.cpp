#include "SettingsLoader.hh"
#include "KeyButton.hh"
#include "RenderWindow.hh"
#include "SettingsPanel.hh"



KeyButton::KeyButton()
{
	_waiting = false;
	_sprite->setTexture(*(RenderWindow::getInstance())->_ressources->_buttonNormal);
}


KeyButton::~KeyButton()
{
}

void		KeyButton::setTitle(std::string const& title)
{
	_title = title;
}

void		KeyButton::setState(Button::StateButton state)
{
	_state = state;
}

void		KeyButton::setId(unsigned int id)
{
	_id = id;
}

void		KeyButton::reset(std::string const& title)
{
	SettingsLoader	*loader = new SettingsLoader();
	RenderWindow	*window = RenderWindow::getInstance();

	(window->getPanels().top()->getLabels().at(_id)).setString(title);
	setTitle(title);
	getSprite().setTexture(*(RenderWindow::getInstance())->_ressources->_buttonNormal);
	delete loader;
}

void		KeyButton::setBind(sf::Event event)
{
	if (_waiting == false)
		return;
	SettingsLoader	*loader = new SettingsLoader();
	RenderWindow	*window = RenderWindow::getInstance();
	std::string		newTitle = loader->keyToString(event.key.code);

	//event joystick ou key ?*
	(window->getPanels().top()->getLabels().at(_id)).setString(newTitle);
	setTitle(newTitle);
	std::cout << "id : " << _id << std::endl;
	switch (_id)
	{
	case 3:
		(dynamic_cast<SettingsPanel*>(window->getPanels().top())->getTemporarySettings()->setKey(Bind::MOVE_UP_BIND, event.key.code));
	case 4:
		(dynamic_cast<SettingsPanel*>(window->getPanels().top())->getTemporarySettings()->setJoystick(Bind::MOVE_UP_BIND, JoystickEvent(0)));
	case 5:
		(dynamic_cast<SettingsPanel*>(window->getPanels().top())->getTemporarySettings()->setKey(Bind::MOVE_DOWN_BIND, event.key.code));
	case 6:
		(dynamic_cast<SettingsPanel*>(window->getPanels().top())->getTemporarySettings()->setJoystick(Bind::MOVE_DOWN_BIND, JoystickEvent(0)));
	case 7:
		(dynamic_cast<SettingsPanel*>(window->getPanels().top())->getTemporarySettings()->setKey(Bind::MOVE_LEFT_BIND, event.key.code));
	case 8:
		(dynamic_cast<SettingsPanel*>(window->getPanels().top())->getTemporarySettings()->setJoystick(Bind::MOVE_LEFT_BIND, JoystickEvent(0)));
	case 9:
		(dynamic_cast<SettingsPanel*>(window->getPanels().top())->getTemporarySettings()->setKey(Bind::MOVE_RIGHT_BIND, event.key.code));
	case 10:
		(dynamic_cast<SettingsPanel*>(window->getPanels().top())->getTemporarySettings()->setJoystick(Bind::MOVE_RIGHT_BIND, JoystickEvent(0)));
	case 11:
		(dynamic_cast<SettingsPanel*>(window->getPanels().top())->getTemporarySettings()->setKey(Bind::LEAVE_GAME_BIND, event.key.code));
	case 12:
		(dynamic_cast<SettingsPanel*>(window->getPanels().top())->getTemporarySettings()->setJoystick(Bind::LEAVE_GAME_BIND, JoystickEvent(0)));
	case 13:
		(dynamic_cast<SettingsPanel*>(window->getPanels().top())->getTemporarySettings()->setKey(Bind::WEAPON_1, event.key.code));
	case 14:
		(dynamic_cast<SettingsPanel*>(window->getPanels().top())->getTemporarySettings()->setJoystick(Bind::WEAPON_1, JoystickEvent(0)));
	case 15:
		(dynamic_cast<SettingsPanel*>(window->getPanels().top())->getTemporarySettings()->setKey(Bind::WEAPON_2, event.key.code));
	case 16:
		(dynamic_cast<SettingsPanel*>(window->getPanels().top())->getTemporarySettings()->setJoystick(Bind::WEAPON_2, JoystickEvent(0)));
	case 17:
		(dynamic_cast<SettingsPanel*>(window->getPanels().top())->getTemporarySettings()->setKey(Bind::WEAPON_3, event.key.code));
	case 18:
		(dynamic_cast<SettingsPanel*>(window->getPanels().top())->getTemporarySettings()->setJoystick(Bind::WEAPON_3, JoystickEvent(0)));
	}
	_waiting = false;
	getSprite().setTexture(*(RenderWindow::getInstance())->_ressources->_buttonNormal);
	delete loader;
}

bool		KeyButton::updateOnPress(std::pair<unsigned int, unsigned int> pair)
{
	std::pair<std::pair<unsigned int, unsigned int>, std::pair<unsigned int, unsigned int>> rect = this->getSprite().getGlobalBounds();

	if (pair.first >= rect.first.first && pair.first <= (rect.first.first + rect.second.first) && pair.second >= rect.first.second && pair.second <= (rect.first.second + rect.second.second))
	{
		getSprite().setTexture(*(RenderWindow::getInstance())->_ressources->_buttonHighlight);
		_waiting = true;
	}
	else
	{
		getSprite().setTexture(*(RenderWindow::getInstance())->_ressources->_buttonNormal);
		_waiting = false;
	}
	return false;
}

void		KeyButton::render()
{

}
