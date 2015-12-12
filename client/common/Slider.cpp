#include "Slider.hh"
#include "Ressources.hh"


Slider::Slider()
{
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
