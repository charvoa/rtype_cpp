//
// StartPanel.hh for StartPanel in /home/barnea_v/rendu/rtype_cpp/client/common
// 
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
// 
// Started on  Mon Nov 30 09:50:06 2015 Viveka BARNEAUD
// Last update Mon Nov 30 09:52:52 2015 Viveka BARNEAUD
//

#ifndef STARTPANEL_H
#define STARTPANEL_H

#include "Button.hh"
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
