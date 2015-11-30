//
// APanel.hh for APanel in /home/barnea_v/rendu/rtype_cpp/client/common
// 
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
// 
// Started on  Mon Nov 30 09:50:56 2015 Viveka BARNEAUD
// Last update Mon Nov 30 09:51:02 2015 Viveka BARNEAUD
//

#ifndef APANEL_HH
#define APANEL_HH

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

#endif // APANEL_HH
