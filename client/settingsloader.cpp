#include "settingsloader.h"

SettingsLoader::SettingsLoader(std::string const& filepath) : _filepath(filepath)
{
    _ifs = new std::ifstream(_filepath.c_str());
    _ofs = new std::ofstream(_filepath.c_str(), ios::out);

    _fileExists = false;
    if (_ifs.good())
        _fileExists = true;
}

SettingsLoader::~SettingsLoader() {}

std::string     SettingsLoader::getValueOf(std::string const& label) const
{

}

void        SettingsLoader::setValueOf(std::string const& label, std::string const& value) const
{

}

Volume      SettingsLoader::getVolume() const
{
    int     global = 0;
    int     effects = 0;
    int     music = 0;
    Volume ret(50, 50, 50);

    if (_fileExists == false)
        return (ret);
    global = stringToInteger(getValueOf("global"));
    effects = stringToInteger(getValueOf("effects"));
    music = stringToInteger(getValueOf("music"));
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
}

std::string     SettingsLoader::bindToString(Bind bind)
{
}

void        SettingsLoader::saveSettings(Settings *settings) const
{
    std::string settingsString(settingsToString(settings));

    _ofs << settingsString;
}
