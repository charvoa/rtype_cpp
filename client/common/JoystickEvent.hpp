#ifndef		JOYSTICKEVENT_HPP_
#define		JOYSTICKEVENT_HPP_

class JoystickEvent
{
	sf::Joystick::Axis		_axis;
	int		_button;
	bool	_isAxis;
public:
	JoystickEvent() {};

	JoystickEvent(sf::Joystick::Axis axis) {
		_axis = axis;
		_isAxis = true;
	};
	JoystickEvent(int button) {
		_button = button;
		_isAxis = false;
	};
	~JoystickEvent() {};

	bool		isAxis() const { return _isAxis; }

	sf::Joystick::Axis	getAxis() const { return _axis; }

	int	getButton() const { return _button; }

	JoystickEvent&	operator=(JoystickEvent const& event) {
		_isAxis = event._isAxis;
		if (_isAxis)
			_axis = event._axis;
		else
			_button = event._button;
		return *this;
	}
};

#endif		/* JOYSTICKEVENT_HPP */