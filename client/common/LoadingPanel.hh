//
// LoadingPanel.hh for LoadingPanel in /home/barnea_v/rendu/rtype_cpp/client/common
// 
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
// 
// Started on  Mon Nov 30 09:50:41 2015 Viveka BARNEAUD
// Last update Mon Nov 30 09:53:36 2015 Viveka BARNEAUD
//

#ifndef LOADINGPANEL_H
#define LOADINGPANEL_H

#include "APanel.hh"
#include "InputManager.hh"

class LoadingPanel : public APanel
{
public:
    LoadingPanel();
    ~LoadingPanel();

	void render();
private:
    InputManager    *_settings;
};

#endif // LOADINGPANEL_H
