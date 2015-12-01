#ifndef JOINPANEL_HH
#define JOINPANEL_HH

#include "APanel.hh"
#include "Button.hh"

class JoinPanel : public APanel
{
public:
    JoinPanel(RenderWindow*);
    ~JoinPanel();

    void    join();
    void    back();
private:
    Button  _joinButton;
    Button  _backButton;
};

#endif // JOINPANEL_HH
