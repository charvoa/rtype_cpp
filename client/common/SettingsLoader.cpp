//
// SettingsLoader.cpp for SettingsLoader in /home/barnea_v/rendu/rtype_cpp/client/common
//
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
//
// Started on  Mon Nov 30 09:50:19 2015 Viveka BARNEAUD
// Last update Thu Dec  3 17:43:29 2015 Nicolas Girardot
//

#include <cstdlib>
#include "SettingsLoader.hh"

SettingsLoader::SettingsLoader(std::string const& filepath) : _filepath(filepath)
{
  _ifs = new std::ifstream(_filepath.c_str());
  _ofs = new std::ofstream(_filepath.c_str(), std::ios::out);

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

    while (it != end)
    {
        if (str.at(it) == ' ' ||
            str.at(it) == '\t')
            str.erase(it, 1);
        ++it;
    }
    return (str);
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

int			SettingsLoader::stringToInteger(std::string const& str)
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

sf::Event			SettingsLoader::stringToKey(std::string const& str)
{

}

std::vector<std::string>	SettingsLoader::getKeys() const
{
  std::string		move_up(stringToKey(getValueOfKey("move_up")));
  std::string		move_down(stringToKey(getValueOfKey("move_down")));
  std::string		move_left(stringToKey(getValueOfKey("move_left")));
  std::string		move_right(stringToKey(getValueOfKey("move_right")));
  std::string		shoot(stringToKey(getValueOfKey("shoot")));
  std::string		weapon1(stringToKey(getValueOfKey("weapon1")));
  std::string		weapon2(stringToKey(getValueOfKey("weapon2")));
  std::string		weapon3(stringToKey(getValueOfKey("weapon3")));
  std::string		leave_game(stringToKey(getValueOfKey("leave_game")));
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

sf::Event		SettingsLoader::stringToJoystick(std::string const& str)
{

}

std::vector<std::string>	SettingsLoader::getJoysticks() const
{
  std::string		move_up(stringToJoystick(getValueOfJoystick("move_up")));
  std::string		move_down(stringToJoystick(getValueOfJoystick("move_down")));
  std::string		move_left(stringToJoystick(getValueOfJoystick("move_left")));
  std::string		move_right(stringToJoystick(getValueOfJoystick("move_right")));
  std::string		shoot(stringToJoystick(getValueOfJoystick("shoot")));
  std::string		weapon1(stringToJoystick(getValueOfJoystick("weapon1")));
  std::string		weapon2(stringToJoystick(getValueOfJoystick("weapon2")));
  std::string		weapon3(stringToJoystick(getValueOfJoystick("weapon3")));
  std::string		leave_game(stringToJoystick(getValueOfJoystick("leave_game")));
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
    Bind    moveUp(Bind::MOVE_UP_BIND, sf::Event::key.Up, sf::Event::joystick::TODO);
    Bind    moveDown(Bind::MOVE_DOWN_BIND, sf::Event::key.Down, sf::Event::joystick::TODO);
    Bind    moveLeft(Bind::MOVE_LEFT_BIND, sf::Event::key.Left, sf::Event::joystick::TODO);
    Bind    moveRight(Bind::MOVE_RIGHT_BIND, sf::Event::key.Right, sf::Event::joystick::TODO);
    Bind    shoot(Bind::ATTACK_BIND, sf::Event::key.Space, sf::Event::joystick::TODO);
    Bind    weapon1(Bind::WEAPON_1, sf::Event::key.Num1, sf::Event::joystick::TODO);
    Bind    weapon2(Bind::WEAPON_2, sf::Event::key.Num2, sf::Event::joystick::TODO);
    Bind    weapon3(Bind::WEAPON_3, sf::Event::key.Num3, sf::Event::joystick::TODO);
    Bind    leaveGame(Bind::LEAVE_GAME_BIND, sf::Event::Escape, sf::Event::joystick::TODO);
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
    Bind    moveUp(Bind::MOVE_UP_BIND, sf::Event::key.Up, sf::Event::joystick::TODO);
    Bind    moveDown(Bind::MOVE_DOWN_BIND, sf::Event::key.Down, sf::Event::joystick::TODO);
    Bind    moveLeft(Bind::MOVE_LEFT_BIND, sf::Event::key.Left, sf::Event::joystick::TODO);
    Bind    moveRight(Bind::MOVE_RIGHT_BIND, sf::Event::key.Right, sf::Event::joystick::TODO);
    Bind    shoot(Bind::ATTACK_BIND, sf::Event::key.Space, sf::Event::joystick::TODO);
    Bind    weapon1(Bind::WEAPON_1, sf::Event::key.Num1, sf::Event::joystick::TODO);
    Bind    weapon2(Bind::WEAPON_2, sf::Event::key.Num2, sf::Event::joystick::TODO);
    Bind    weapon3(Bind::WEAPON_3, sf::Event::key.Num3, sf::Event::joystick::TODO);
    Bind    leaveGame(Bind::LEAVE_GAME_BIND, sf::Event::Escape, sf::Event::joystick::TODO);
    std::vector<Bind>   binds;

    if (_fileExists == false)
      return (createDefaultBinds());

    std::vector<std::string>keys = getKeys();
    std::vector<std::string>joysticks = getJoysticks();
    std::vector<std::string>::iterator itk = keys.begin();
    std::vector<Bind>::iterator itb = binds.begin();
    std::vector<std::string>::const_iterator endk = keys.end();
    std::vector<std::string>::iterator itj = joysticks.begin();

    binds.push_back(move_up);
    binds.push_back(move_down);
    binds.push_back(move_left);
    binds.push_back(move_right);
    binds.push_back(shoot);
    binds.push_back(weapon1);
    binds.push_back(weapon2);
    binds.push_back(weapon3);
    binds.push_back(leave_game);
    while (itk != endk)
      {
	(*itb).setKey(*itk);
	(*itb).setJoystick(*itj);
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
    }
}

std::string     SettingsLoader::joystickToString(sf::Event joystick) const
{
}

std::string     SettingsLoader::keyToString(sf::Event key) const
{
    switch (key) {
	case Num0:
        return "0_KEY";
    case Num1:
        return "1_KEY";
    case Num2:
        return "2_KEY";
    case Num3:
        return "3_KEY";
    case Num4:
        return "4_KEY";
    case Num5:
        return "5_KEY";
    case Num6:
        return "6_KEY";
    case Num7:
        return "7_KEY";
    case Num8:
        return "8_KEY";
    case Num9:
        return "9_KEY";
        return "ARROW_UP_KEY";
        return "ARROW_DOWN_KEY";
        return "ARROW_LEFT_KEY";
        return "ARROW_RIGHT_KEY";
        return "SPACE_KEY";
        return "ESCAPE_KEY";
    case A:
        return "A_KEY";
    case Z:
        return "Z_KEY";
    case E:
        return "E_KEY";
    case R:
        return "R_KEY";
    case T:
        return "T_KEY";
    case Y:
        return "Y_KEY";
    case U:
        return "U_KEY";
    case I:
        return "I_KEY";
    case O:
        return "O_KEY";
    case P:
        return "P_KEY";
        return "^_KEY";
        return "$_KEY";
    case Return:
        return "RETURN_KEY";
    case Q:
        return "Q_KEY";
    case S:
        return "S_KEY";
    case D:
        return "D_KEY";
    case F:
        return "F_KEY";
    case G:
        return "G_KEY";
    case H:
        return "H_KEY";
    case J:
        return "J_KEY";
    case K:
        return "K_KEY";
    case L:
        return "L_KEY";
    case M:
        return "M_KEY";
        return "ù_KEY";
        return "*_KEY";
        return "<_KEY";
        return ")_KEY";
        return "=_KEY";
    case W:
        return "W_KEY";
    case X:
        return "X_KEY";
    case C:
        return "C_KEY";
    case V:
        return "V_KEY";
    case B:
        return "B_KEY";
    case N:
        return "N_KEY";
        return ",_KEY";
        return ";_KEY";
        return ":_KEY";
        return "!_KEY";
    case Numpad0:
        return "PAD_0_KEY";
    case Numpad1:
        return "PAD_1_KEY";
    case Numpad2:
        return "PAD_2_KEY";
    case Numpad3:
        return "PAD_3_KEY";
    case Numpad4:
        return "PAD_4_KEY";
    case Numpad5:
        return "PAD_5_KEY";
    case Numpad6:
        return "PAD_6_KEY";
    case Numpad7:
        return "PAD_7_KEY";
    case Numpad8:
        return "PAD_8_KEY";
    case Numpad9:
        return "PAD_9_KEY";
    default:
        return "NO_BIND";
    }
}

std::string     SettingsLoader::bindToString(Bind bind)
{
    std::string bindType = bindTypeToString(bind.getType());
    std::string joystick = joystickToString(bind.getJoystick());
    std::string key = keyToString(bind.getKey());

    bindType += "=" + key + "," + joystick + "\n";
    return bindType;
}

void        SettingsLoader::saveSettings(Settings *settings) const
{
    std::string settingsString(settingsToString(settings));

    _ofs << settingsString;
}

Settings	*SettingsLoader::parseSettings() const
{
  Settings	*ret = new Settings(getVolume(), getBinds(), getDefaultDifficulty());

  return (ret);
}
