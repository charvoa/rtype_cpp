#ifndef STARTPANEL_H
#define STARTPANEL_H

#include "APanel.hh"

class StartPanel
{
public:
    StartPanel(RenderWindow *);
    ~StartPanel();

    void    play();
    void    demo();
    void    settings();
    void    exit();

private:
    Button  _playButton;
    Button  _demoButton;
    Button  _settingsButton;
    Button  _exitButton;
};

#endif // STARTPANEL_H
