#pragma once
#include "Button.hh"
#include "AMenuElement.hh"

class KeyButton : public AMenuElement
{
private:
	Button::StateButton	_state;
	std::string	_title;
	bool	_waiting;
	unsigned int _id;
public:
	KeyButton();
	~KeyButton();

	void		setBind(sf::Event);
	bool		updateOnPress(std::pair<unsigned int, unsigned int>);
	void		setState(Button::StateButton);
	void		setTitle(std::string const&);
	void		render();
	void		setId(unsigned int);
	void		reset(std::string const&);
};
