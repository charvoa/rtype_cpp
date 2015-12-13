//
// SettingsLoader.cpp for SettingsLoader in /home/barnea_v/rendu/rtype_cpp/client/common
//
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
//
// Started on  Mon Nov 30 09:50:19 2015 Viveka BARNEAUD
// Last update Thu Dec  3 13:19:53 2015 Serge Heitzler
//

#include <cstdlib>
#include "SettingsLoader.hh"

SettingsLoader::SettingsLoader(std::string const& filepath) : _filepath(filepath)
{
	_ifs = new std::ifstream(_filepath.c_str());
	_ofs = new std::ofstream(_filepath.c_str(), std::ios::out);
	_stringKeys["0_KEY"] = sf::Keyboard::Num0;
	_stringKeys["1_KEY"] = sf::Keyboard::Num1;
  _stringKeys["2_KEY"] = sf::Keyboard::Num2;
  _stringKeys["3_KEY"] = sf::Keyboard::Num3;
  _stringKeys["4_KEY"] = sf::Keyboard::Num4;
  _stringKeys["5_KEY"] = sf::Keyboard::Num5;
  _stringKeys["6_KEY"] = sf::Keyboard::Num6;
  _stringKeys["7_KEY"] = sf::Keyboard::Num7;
  _stringKeys["8_KEY"] = sf::Keyboard::Num8;
  _stringKeys["9_KEY"] = sf::Keyboard::Num9;
  _stringKeys["0_KEY"] = sf::Keyboard::Num0;
  _stringKeys["ARROW_UP_KEY"] = sf::Keyboard::Up;
  _stringKeys["ARROW_DOWN_KEY"] = sf::Keyboard::Down;
  _stringKeys["ARROW_LEFT_KEY"] = sf::Keyboard::Left;
  _stringKeys["ARROW_RIGHT_KEY"] = sf::Keyboard::Right;
  _stringKeys["SPACE_KEY"] = sf::Keyboard::Space;
  _stringKeys["ESCAPE_KEY"] = sf::Keyboard::Escape;
  _stringKeys["RETURN_KEY"] = sf::Keyboard::Return;
  _stringKeys["A_KEY"] = sf::Keyboard::A;
  _stringKeys["Z_KEY"] = sf::Keyboard::Z;
  _stringKeys["E_KEY"] = sf::Keyboard::E;
  _stringKeys["R_KEY"] = sf::Keyboard::R;
  _stringKeys["T_KEY"] = sf::Keyboard::T;
  _stringKeys["Y_KEY"] = sf::Keyboard::Y;
  _stringKeys["U_KEY"] = sf::Keyboard::U;
  _stringKeys["I_KEY"] = sf::Keyboard::I;
  _stringKeys["O_KEY"] = sf::Keyboard::O;
  _stringKeys["P_KEY"] = sf::Keyboard::P;
  _stringKeys["Q_KEY"] = sf::Keyboard::Q;
  _stringKeys["S_KEY"] = sf::Keyboard::S;
  _stringKeys["D_KEY"] = sf::Keyboard::D;
  _stringKeys["F_KEY"] = sf::Keyboard::F;
  _stringKeys["G_KEY"] = sf::Keyboard::G;
  _stringKeys["H_KEY"] = sf::Keyboard::H;
  _stringKeys["J_KEY"] = sf::Keyboard::J;
  _stringKeys["K_KEY"] = sf::Keyboard::K;
  _stringKeys["L_KEY"] = sf::Keyboard::L;
  _stringKeys["M_KEY"] = sf::Keyboard::M;
  _stringKeys["W_KEY"] = sf::Keyboard::W;
  _stringKeys["X_KEY"] = sf::Keyboard::X;
  _stringKeys["C_KEY"] = sf::Keyboard::C;
  _stringKeys["V_KEY"] = sf::Keyboard::V;
  _stringKeys["B_KEY"] = sf::Keyboard::B;
  _stringKeys["N_KEY"] = sf::Keyboard::N;
  _stringKeys["PAD_0_KEY"] = sf::Keyboard::Numpad0;
  _stringKeys["PAD_1_KEY"] = sf::Keyboard::Numpad1;
  _stringKeys["PAD_2_KEY"] = sf::Keyboard::Numpad2;
  _stringKeys["PAD_3_KEY"] = sf::Keyboard::Numpad3;
  _stringKeys["PAD_4_KEY"] = sf::Keyboard::Numpad4;
  _stringKeys["PAD_5_KEY"] = sf::Keyboard::Numpad5;
  _stringKeys["PAD_6_KEY"] = sf::Keyboard::Numpad6;
  _stringKeys["PAD_7_KEY"] = sf::Keyboard::Numpad7;
  _stringKeys["PAD_8_KEY"] = sf::Keyboard::Numpad8;
  _stringKeys["PAD_9_KEY"] = sf::Keyboard::Numpad9;

  _stringAxis["JOYSTICK_UP"] = JoystickEvent(sf::Joystick::X);
  _stringAxis["JOYSTICK_DOWN"] = JoystickEvent(sf::Joystick::X);
  _stringAxis["JOYSTICK_LEFT"] = JoystickEvent(sf::Joystick::Y);
  _stringAxis["JOYSTICK_RIGHT"] = JoystickEvent(sf::Joystick::Y);
  _stringAxis["JOYSTICK_X"] = JoystickEvent(0);
  _stringAxis["JOYSTICK_Y"] = JoystickEvent(2);
  _stringAxis["JOYSTICK_A"] = JoystickEvent(1);
  _stringAxis["JOYSTICK_B"] = JoystickEvent(3);
  _stringAxis["JOYSTICK_L1"] = JoystickEvent(sf::Joystick::Z);
  _stringAxis["JOYSTICK_L2"] = JoystickEvent(sf::Joystick::Z);
  _stringAxis["JOYSTICK_R1"] = JoystickEvent(sf::Joystick::R);
  _stringAxis["JOYSTICK_R2"] = JoystickEvent(sf::Joystick::R);

	if (!_ifs->good())
    {
      _fileExists = false;
      return;
    }
  _fileExists = true;
}

SettingsLoader::~SettingsLoader() {}

std::string     SettingsLoader::removeSpaces(std::string const& str) const
{
    unsigned int it = 0;
    unsigned int end = str.length();
	std::string ret(str);

    while (it != end)
    {
        if (ret.at(it) == ' ' ||
            ret.at(it) == '\t')
            ret.erase(it, 1);
        ++it;
    }
    return (ret);
}

std::string     SettingsLoader::getValueOf(std::string const& label) const
{
    std::string	line;
    std::string	value;
    _ifs->seekg(0, _ifs->beg);

    while (std::getline(*_ifs, line))
      {
        line = removeSpaces(line);
        if (line.find(label) != std::string::npos)
        {
	  _ifs->clear();
	  value = line.substr(line.find("=") + 1, std::string::npos);
	  return (value);
        }
      }
    _ifs->clear();
    return ("LABEL_NOT_FOUND");
}

std::string	SettingsLoader::getValueOfKey(std::string const& label) const
{
  std::string	toSplit(getValueOf(label));
  std::string	ret;

  ret = toSplit.substr(0, toSplit.find(","));
  return (ret);
}

std::string	SettingsLoader::getValueOfJoystick(std::string const& label) const
{
  std::string	toSplit(getValueOf(label));
  std::string	ret;

  ret = toSplit.substr(toSplit.find(",") + 1, std::string::npos);
  return (ret);
}

int         SettingsLoader::getGlobalVolume() const
{
    int     global = 50;
    std::string globalString(getValueOf("global"));

    if (globalString != "LABEL_NOT_FOUND")
        global = stringToInteger(globalString);
    return global;
}

int         SettingsLoader::getEffectsVolume() const
{
    int     effects = 50;
    std::string effectsString(getValueOf("effects"));

    if (effectsString != "LABEL_NOT_FOUND")
        effects = stringToInteger(effectsString);
    return effects;
}

int         SettingsLoader::getMusicVolume() const
{
    int     music = 50;
    std::string musicString(getValueOf("music"));

    if (musicString != "LABEL_NOT_FOUND")
        music = stringToInteger(musicString);
    return music;
}

int			SettingsLoader::stringToInteger(std::string const& str) const
{
	return (std::stoi(str));
}

Volume      SettingsLoader::getVolume() const
{
    int     global = 0;
    int     effects = 0;
    int     music = 0;
    Volume ret(50, 50, 50);

    if (_fileExists == false)
        return (ret);
    global = getGlobalVolume();
    effects = getEffectsVolume();
    music = getMusicVolume();
    ret.setEffects(effects);
    ret.setGlobal(global);
    ret.setMusic(music);

    return (ret);
}

bool		SettingsLoader::keyExists(std::string const& key) const
{
	if (_stringKeys.find(key) != _stringKeys.end())
		return (true);
	return (false);
}

bool		SettingsLoader::axisExists(std::string const& axis) const
{
	if (_stringAxis.find(axis) != _stringAxis.end())
		return (true);
	return (false);
}

sf::Keyboard::Key			SettingsLoader::stringToKey(std::string const& str) const
{
	if (!keyExists(str))
		return (sf::Keyboard::KeyCount);
	return (_stringKeys.find(str)->second);
}

std::vector<std::string>	SettingsLoader::getKeys() const
{
  std::string		move_up(getValueOfKey("move_up"));
  std::string		move_down(getValueOfKey("move_down"));
  std::string		move_left(getValueOfKey("move_left"));
  std::string		move_right(getValueOfKey("move_right"));
  std::string		shoot(getValueOfKey("shoot"));
  std::string		weapon1(getValueOfKey("weapon1"));
  std::string		weapon2(getValueOfKey("weapon2"));
  std::string		weapon3(getValueOfKey("weapon3"));
  std::string		leave_game(getValueOfKey("leave_game"));
  std::vector<std::string>	ret;

  ret.push_back(move_up);
  ret.push_back(move_down);
  ret.push_back(move_left);
  ret.push_back(move_right);
  ret.push_back(shoot);
  ret.push_back(weapon1);
  ret.push_back(weapon2);
  ret.push_back(weapon3);
  ret.push_back(leave_game);
  return (ret);
}

JoystickEvent		SettingsLoader::stringToJoystick(std::string const& str) const
{
	if (!axisExists(str))
		return (JoystickEvent(-1));
	return (_stringAxis.find(str)->second);
}

std::vector<std::string>	SettingsLoader::getJoysticks() const
{
  std::string		move_up(getValueOfJoystick("move_up"));
  std::string		move_down(getValueOfJoystick("move_down"));
  std::string		move_left(getValueOfJoystick("move_left"));
  std::string		move_right(getValueOfJoystick("move_right"));
  std::string		shoot(getValueOfJoystick("shoot"));
  std::string		weapon1(getValueOfJoystick("weapon1"));
  std::string		weapon2(getValueOfJoystick("weapon2"));
  std::string		weapon3(getValueOfJoystick("weapon3"));
  std::string		leave_game(getValueOfJoystick("leave_game"));
  std::vector<std::string>	ret;

  ret.push_back(move_up);
  ret.push_back(move_down);
  ret.push_back(move_left);
  ret.push_back(move_right);
  ret.push_back(shoot);
  ret.push_back(weapon1);
  ret.push_back(weapon2);
  ret.push_back(weapon3);
  ret.push_back(leave_game);
  return (ret);
}

std::vector<Bind>	SettingsLoader::createDefaultBinds() const
{
	Bind    moveUp(Bind::MOVE_UP_BIND, sf::Keyboard::Up, JoystickEvent(sf::Joystick::X));
    Bind    moveDown(Bind::MOVE_DOWN_BIND, sf::Keyboard::Down, JoystickEvent(sf::Joystick::X));
    Bind    moveLeft(Bind::MOVE_LEFT_BIND, sf::Keyboard::Left, JoystickEvent(sf::Joystick::Y));
    Bind    moveRight(Bind::MOVE_RIGHT_BIND, sf::Keyboard::Right, JoystickEvent(sf::Joystick::Y));
    Bind    shoot(Bind::ATTACK_BIND, sf::Keyboard::Space, JoystickEvent(sf::Joystick::R));
    Bind    weapon1(Bind::WEAPON_1, sf::Keyboard::Num1, JoystickEvent(1));
    Bind    weapon2(Bind::WEAPON_2, sf::Keyboard::Num2, JoystickEvent(2));
    Bind    weapon3(Bind::WEAPON_3, sf::Keyboard::Num3, JoystickEvent(3));
    Bind    leaveGame(Bind::LEAVE_GAME_BIND, sf::Keyboard::Escape, JoystickEvent(sf::Joystick::Z));
    std::vector<Bind>   defaultBinds;

    defaultBinds.push_back(moveUp);
    defaultBinds.push_back(moveDown);
    defaultBinds.push_back(moveLeft);
    defaultBinds.push_back(moveRight);
    defaultBinds.push_back(shoot);
    defaultBinds.push_back(weapon1);
    defaultBinds.push_back(weapon2);
    defaultBinds.push_back(weapon3);
    defaultBinds.push_back(leaveGame);
    return (defaultBinds);
}

std::vector<Bind>   SettingsLoader::getBinds() const
{
	Bind    moveUp(Bind::MOVE_UP_BIND, sf::Keyboard::Up, JoystickEvent(sf::Joystick::X));
	Bind    moveDown(Bind::MOVE_DOWN_BIND, sf::Keyboard::Down, JoystickEvent(sf::Joystick::X));
	Bind    moveLeft(Bind::MOVE_LEFT_BIND, sf::Keyboard::Left, JoystickEvent(sf::Joystick::Y));
	Bind    moveRight(Bind::MOVE_RIGHT_BIND, sf::Keyboard::Right, JoystickEvent(sf::Joystick::Y));
	Bind    shoot(Bind::ATTACK_BIND, sf::Keyboard::Space, JoystickEvent(sf::Joystick::R));
	Bind    weapon1(Bind::WEAPON_1, sf::Keyboard::Num1, JoystickEvent(1));
	Bind    weapon2(Bind::WEAPON_2, sf::Keyboard::Num2, JoystickEvent(2));
	Bind    weapon3(Bind::WEAPON_3, sf::Keyboard::Num3, JoystickEvent(3));
	Bind    leaveGame(Bind::LEAVE_GAME_BIND, sf::Keyboard::Escape, JoystickEvent(sf::Joystick::Z));
	std::vector<Bind>   binds;

    if (_fileExists == false)
      return (createDefaultBinds());

    std::vector<std::string>keys = getKeys();
    std::vector<std::string>joysticks = getJoysticks();
    std::vector<std::string>::const_iterator itk = keys.begin();
    std::vector<Bind>::iterator itb = binds.begin();
    std::vector<std::string>::const_iterator endk = keys.end();
    std::vector<std::string>::const_iterator itj = joysticks.begin();

    binds.push_back(moveUp);
    binds.push_back(moveDown);
    binds.push_back(moveLeft);
    binds.push_back(moveRight);
    binds.push_back(shoot);
    binds.push_back(weapon1);
    binds.push_back(weapon2);
    binds.push_back(weapon3);
    binds.push_back(leaveGame);
    while (itk != endk)
      {
	(*itb).setKey(stringToKey(*itk));
	(*itb).setJoystick(stringToJoystick(*itj));
	itk++;
	itj++;
      }
    return (binds);
}

Settings::Difficulty    SettingsLoader::getDefaultDifficulty() const
{
    std::string     diff = getValueOf("default");

    if (diff == "EASY_MODE")
        return (Settings::EASY_MODE);
    if (diff == "MEDIUM_MODE")
        return (Settings::MEDIUM_MODE);
    if (diff == "HARD_MODE")
        return (Settings::HARD_MODE);
    return (Settings::MEDIUM_MODE);
}

std::string     SettingsLoader::bindTypeToString(Bind::BindType type) const
{
    switch (type)
    {
    case Bind::MOVE_UP_BIND:
        return "move_up";
    case Bind::MOVE_DOWN_BIND:
        return "move_down";
    case Bind::MOVE_LEFT_BIND:
        return "move_left";
    case Bind::MOVE_RIGHT_BIND:
        return "move_right";
    case Bind::ATTACK_BIND:
        return "shoot";
    case Bind::LEAVE_GAME_BIND:
        return "leave_game";
    case Bind::WEAPON_1:
        return "weapon1";
    case Bind::WEAPON_2:
        return "weapon2";
    case Bind::WEAPON_3:
        return "weapon3";
    default:
      return "";
    }
}

bool		SettingsLoader::joystickIsEqual(JoystickEvent const& a, JoystickEvent const& b) const
{
	if (a.isAxis() != b.isAxis())
		return false;
	if (a.isAxis() == true)
	{
		if (a.getAxis() == b.getAxis())
			return true;
		return false;
	}
	if (a.getButton() == b.getButton())
		return true;
	return false;
}

std::string     SettingsLoader::joystickToString(JoystickEvent joystick) const
{
	std::map<std::string, JoystickEvent>::const_iterator it = _stringAxis.begin();
	std::map<std::string, JoystickEvent>::const_iterator end = _stringAxis.end();

	while (it != end)
	{
		if (joystickIsEqual(it->second, joystick))
			return (it->first);
		++it;
	}
	return ("NO_BIND");
}

std::string		SettingsLoader::keyToString(sf::Keyboard::Key key) const
{
	std::map<std::string, sf::Keyboard::Key>::const_iterator it = _stringKeys.begin();
	std::map<std::string, sf::Keyboard::Key>::const_iterator end = _stringKeys.end();

	while (it != end)
	{
		if (it->second == key)
			return (it->first);
		++it;
	}
	return ("NO_Bind");
}

std::string     SettingsLoader::bindToString(Bind bind) const
{
    std::string bindType = bindTypeToString(bind.getType());
    std::string joystick = joystickToString(bind.getJoystick());
    std::string key = keyToString(bind.getKey());

    bindType += "=" + key + "," + joystick + "\n";
    return bindType;
}

void        SettingsLoader::saveSettings(Settings *settings) const
{
    std::string settingsString(settingsToString(*settings));

    *_ofs << settingsString;
}

std::string	SettingsLoader::settingsToString(Settings const& settings) const
{
	(void)settings;
	return ("TODO");
}

Settings	*SettingsLoader::parseSettings() const
{
  Settings	*ret = new Settings(getVolume(), getBinds(), getDefaultDifficulty());

  return (ret);
}
