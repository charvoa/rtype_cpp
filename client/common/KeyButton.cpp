#include "SettingsLoader.hh"
#include "KeyButton.hh"
#include "RenderWindow.hh"



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
