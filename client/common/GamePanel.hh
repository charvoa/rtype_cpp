#ifndef GAMEPANEL_H
#define GAMEPANEL_H

#include "APanel.hh"

class GamePanel : public APanel
{
public:
    GamePanel();
    ~GamePanel();

	void render();
};

#endif // GAMEPANEL_H
