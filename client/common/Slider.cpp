#include "Slider.hh"
#include "SettingsPanel.hh"
#include "Client.hh"
#include "Ressources.hh"


Slider::Slider(std::string const& title)
{
	_title = title;
	_locked = true;
}


Slider::~Slider()
{
}

void		Slider::setTitle(std::string const& title)
{
	_title = title;
}

void		Slider::setValue(int val)
{
	_value = val;
}

void			Slider::setState(Button::StateButton state)
{
	_state = state;
}

std::string		Slider::getTitle() const
{
	return _title;
}

int				Slider::getValue() const
{
	return _value;
}

void			Slider::render()
{

}

void			Slider::setLimit(float xmin, float xmax)
{
	_minX = xmin;
	_maxX = xmax;
}

float			Slider::getPosX()
{
	return _sprite->getPosX();
}

float			Slider::getPosY()
{
	return _sprite->getPosY();
}

void			Slider::updateOnMove(std::pair<unsigned int, unsigned int> pair)
{
	std::pair<std::pair<unsigned int, unsigned int>, std::pair<unsigned int, unsigned int>> rect = this->getSprite().getGlobalBounds();
	RenderWindow	*window = RenderWindow::getInstance();

	if (pair.first >= rect.first.first && pair.first <= (rect.first.first + rect.second.first) && pair.second >= rect.first.second && pair.second <= (rect.first.second + rect.second.second))
	{
		if (_locked == false)
		{
			if (pair.first <= _maxX && pair.first >= _minX)
				this->getSprite().setPosition(pair.first, getPosY());
		}
	}
	// window->_ressources->_keyButtonNormal->getSize()._x / 2
}

bool			Slider::updateOnPress(std::pair<unsigned int, unsigned int> pair)
{
	RenderWindow	*window = RenderWindow::getInstance();
	std::pair<std::pair<unsigned int, unsigned int>, std::pair<unsigned int, unsigned int>> rect = this->getSprite().getGlobalBounds();

	if (pair.first >= rect.first.first && pair.first <= (rect.first.first + rect.second.first) && pair.second >= rect.first.second && pair.second <= (rect.first.second + rect.second.second))
	{
		_locked = false;
	}
	else if (pair.first <= _maxX && pair.first >= _minX && pair.second >= rect.first.second && pair.second <= (rect.first.second + rect.second.second))
	{
		this->setValue((pair.first - _minX) / 7);
		this->getSprite().setPosition(pair.first, getPosY());
		if (_title == "global")
		{
			dynamic_cast<SettingsPanel*>(window->getPanels().top())->setGlobalVolume(_value);
			Client::getSound()->setEffectsVolume(_value);
			Client::getSound()->setMusicVolume(_value);
		}
		else if (_title == "effects")
		{
			dynamic_cast<SettingsPanel*>(window->getPanels().top())->setEffectsVolume(_value);
			Client::getSound()->setEffectsVolume(_value);
		}
		else if (_title == "music")
		{
			dynamic_cast<SettingsPanel*>(window->getPanels().top())->setMusicVolume(_value);
			Client::getSound()->setMusicVolume(_value);
		}
	}
	return false;
}

void			Slider::updateOnRelease(std::pair<unsigned int, unsigned int> pair)
{
	RenderWindow	*window = RenderWindow::getInstance();
	
	if (_locked == true)
		return;
	if (pair.first > _maxX)
		this->setValue(100);
	if (pair.first < _minX)
		this->setValue(0);
	else
		this->setValue((pair.first - _minX) / 7);
	if (_title == "global")
	{
		dynamic_cast<SettingsPanel*>(window->getPanels().top())->setGlobalVolume(_value);
		Client::getSound()->setEffectsVolume(_value);
		Client::getSound()->setMusicVolume(_value);
	}
	else if (_title == "effects")
	{
		dynamic_cast<SettingsPanel*>(window->getPanels().top())->setEffectsVolume(_value);
		Client::getSound()->setEffectsVolume(_value);
	}
	else if (_title == "music")
	{
		dynamic_cast<SettingsPanel*>(window->getPanels().top())->setMusicVolume(_value);
		Client::getSound()->setMusicVolume(_value);
	}
	Client::getSound()->setMusicVolume(_value);
	Client::getSound()->setEffectsVolume(_value);
	_locked = true;
}
