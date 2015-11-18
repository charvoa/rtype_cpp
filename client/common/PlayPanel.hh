//
// PlayPanel.hh for PlayPanel in /home/barnea_v/rendu/rtype_cpp/client/common
// 
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
// 
// Started on  Mon Nov 30 09:50:34 2015 Viveka BARNEAUD
// Last update Mon Nov 30 09:53:12 2015 Viveka BARNEAUD
//

#ifndef PLAYPANEL_H
#define PLAYPANEL_H

#include "APanel.hh"
#include "Button.hh"

class PlayPanel : public APanel
{
public:
    PlayPanel(RenderWindow *);
    ~PlayPanel();

    void    solo();
    void    multi();
    void    back();
private:
    Button  _soloButton;
    Button  _multiButton;
    Button  _backButton;
};

#endif // PLAYPANEL_H
