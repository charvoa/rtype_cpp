#pragma once

#include "AMenuElement.hh"
#include "RenderWindow.hh"
#include "Button.hh"

class Slider :	public AMenuElement
{
public:
	Slider();
	~Slider();

	std::string	getTitle() const;
	int			getValue() const;

	void		setTitle(std::string const&);
	void		setValue(int);
	void		render();
	void		setState(Button::StateButton state);

private:
	Button::StateButton	_state;
	std::string	_title;
	int			_value;
};
