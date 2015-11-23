#ifndef PLAYPANEL_H
#define PLAYPANEL_H

#include "APanel.hh"

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
