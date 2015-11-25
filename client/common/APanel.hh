#ifndef APANEL_H
#define APANEL_H

#include "RenderWindow.hh"
#include "IPanel.hh"

class APanel : public IPanel
{
public:
    APanel(RenderWindow *parent);
    ~Apanel();

protected:
    RenderWindow  *_parent;
};

#endif // APANEL_H
