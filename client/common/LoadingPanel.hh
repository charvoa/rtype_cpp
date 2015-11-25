#ifndef LOADINGPANEL_H
#define LOADINGPANEL_H

#include "APanel.hh"

class LoadingPanel : public APanel
{
public:
    LoadingPanel(RenderWindow *parent);
    ~LoadingPanel();

private:
    InputManager    *_settings;
};

#endif // LOADINGPANEL_H
