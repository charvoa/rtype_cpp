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

	void		setAxis(sf::Joystick::Axis axis) {
		_isAxis = true;
		_axis = axis;
	}

	void		setButton(int button) {
		_isAxis = false;
		_button = button;
	}

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

	bool			isEqual(JoystickEvent const& b) {
		if (_isAxis == b._isAxis)
		{
			if (_axis == b._axis)
				return true;
			return false;
		}
		if (_button == b._button)
			return true;
		return false;
	}
};

#endif		/* JOYSTICKEVENT_HPP */