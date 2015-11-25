#ifndef ROOMPANEL_H
#define ROOMPANEL_H

#include "APanel.hh"

class RoomPanel : public APanel
{
public:
    RoomPanel(RenderWindow *);
    ~RoomPanel();

    void    difficulty(Settings::Difficulty);
    void    start();
    void    back();

private:
    Button  _startButton;
    Button  _easyButton;
    Button  _mediumButton;
    Button  _hardButton;
    Button  _backButton;
    std::map<Player*, Component*> _playersList;
};

#endif // ROOMPANEL_H
