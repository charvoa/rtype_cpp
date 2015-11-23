#ifndef BIND_H
#define BIND_H


class Bind
{
public:
    Bind(Bind::BindType, sf::Event::key, sf::Event::joystick);
    ~Bind();

    typedef enum e_BindType
    {
        ATTACK_BIND,
        MOVE_UP_BIND,
        MOVE_DOWN_BIND,
        MOVE_LEFT_BIND,
        MOVE_RIGHT_BIND,
        LEAVE_GAME_BIND
    } BindType;

    Bind::BindType getType() const;
    sf::Event::key getKey() const;
    sf::Event::joystick getJoystick() const;

    void setType(Bind::BindType);
    void setKey(sf::Event::key);
    void setJoystick(sf::Event::joystick);

private:
    Bind::BindType _type;
    sf::Event::key _key;
    sf::Event::joystick _joystick;
};

#endif // BIND_H
