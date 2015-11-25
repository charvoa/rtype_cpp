#include "SettingsLoader.hh"

SettingsLoader::SettingsLoader(std::string const& filepath) : _filepath(filepath)
{
  _ifs = new std::ifstream(_filepath.c_str());
  _ofs = new std::ofstream(_filepath.c_str(), ios::out);

  if (!ifs.good())
    {
      _fileExists = false;
      return;
    }
  _fileExists = true;
}

SettingsLoader::~SettingsLoader() {}

std::string     SettingsLoader::getValueOf(std::string const& label) const
{
    std::string	line;
    std::string	value;
    _ifs->seekg(0, ifs->beg);

    while (std::getline(*_ifs, line))
      {
	std::cout << "LINE : [" << line << "]" << std::endl;
        if (line.find(label) != std::string::npos)
        {
	  _ifs->clear();
	  value = line.substr(line.find("=") + 1, std::string::npos);
	  return (value);
        }
      }
    _ifs->clear();
    return ("NOT_FOUND");
}

void        SettingsLoader::setValueOf(std::string const& label, std::string const& value) const
{
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
    std::vector<Bind>   defaultBinds;
    std::vector<Bind>   binds;

    defaultBinds.push_back(moveUp);
    defaultBinds.push_back(moveDown);
    defaultBinds.push_back(moveLeft);
    defaultBinds.push_back(moveRight);
    defaultBinds.push_back(shoot);
    defaultBinds.push_back(weapon1);
    defaultBinds.push_back(weapon2);
    defaultBinds.push_back(weapon3);
    defaultBinds.push_back(leaveGame);

    if (_fileExists == false)
        return (defaultBinds);

    moveUp.setKey(stringToKey(getValueOf("move_up")));
    moveDown.setKey(stringToKey(getValueOf("move_down")));
    moveLeft.setKey(stringToKey(getValueOf("move_left")));
    moveRight.setKey(stringToKey(getValueOf("move_right")));
    shoot.setKey(stringToKey(getValueOf("shoot")));
    weapon1.setKey(stringToKey(getValueOf("weapon1")));
    weapon2.setKey(stringToKey(getValueOf("weapon2")));
    weapon3.setKey(stringToKey(getValueOf("weapon3")));
    leaveGame.setKey(stringToKey(getValueOf("leave_game")));

    binds.push_back(moveUp);
    binds.push_back(moveDown);
    binds.push_back(moveLeft);
    binds.push_back(moveRight);
    binds.push_back(shoot);
    binds.push_back(weapon1);
    binds.push_back(weapon2);
    binds.push_back(weapon3);
    binds.push_back(leaveGame);

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

std::string     SettingsLoader::joystickToString(sf::Event::Joystick) const
{
}

std::string     SettingsLoader::keyToString(sf::Event::key key) const
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

    bindType+="="+key+","+joystick+"\n";
}

void        SettingsLoader::saveSettings(Settings *settings) const
{
    std::string settingsString(settingsToString(settings));

    _ofs << settingsString;
}
