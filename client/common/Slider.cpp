#include "Slider.hh"
#include "Ressources.hh"


Slider::Slider()
{
	_locked = true;
	_sprite->setTexture(*(RenderWindow::getInstance())->_ressources->_buttonNormal);
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

	if (pair.first >= rect.first.first && pair.first <= (rect.first.first + rect.second.first) && pair.second >= rect.first.second && pair.second <= (rect.first.second + rect.second.second))
	{
		if (_locked == false)
			this->getSprite().setPosition(pair.first, getPosY());
		this->getSprite().setTexture(*(RenderWindow::getInstance())->_ressources->_buttonHighlight);
	}
	else
		this->getSprite().setTexture(*(RenderWindow::getInstance())->_ressources->_buttonNormal);
}

bool			Slider::updateOnPress(std::pair<unsigned int, unsigned int> pair)
{
	std::pair<std::pair<unsigned int, unsigned int>, std::pair<unsigned int, unsigned int>> rect = this->getSprite().getGlobalBounds();

	if (pair.first >= rect.first.first && pair.first <= (rect.first.first + rect.second.first) && pair.second >= rect.first.second && pair.second <= (rect.first.second + rect.second.second))
	{
		_locked = false;
	}
	else
	{
		// déplacer sur la ligne à l'endroit du clic
	}
	return false;
}

void			Slider::updateOnRelease(std::pair<unsigned int, unsigned int> pair)
{
	_locked = true;
	(void)pair;
	// set value en fonction de la position
}
