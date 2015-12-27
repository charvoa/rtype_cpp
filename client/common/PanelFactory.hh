//
// PanelFactory.hh for rtype in /home/nicolas/rendu/rtype_cpp/client
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed Nov 25 10:15:28 2015 Nicolas Girardot
// Last update Sun Dec 27 08:07:47 2015 Serge Heitzler
//

#ifndef PANELFACTORY_HH
#define PANELFACTORY_HH

#include <APanel.hh>

class PanelFactory
{

public:
    PanelFactory();
    ~PanelFactory();


   typedef enum e_panelType
    {
        ROOM_PANEL,
        SETTINGS_PANEL,
        GAME_PANEL,
        DEMO_PANEL,
        JOIN_PANEL,
        START_PANEL,
        LOADING_PANEL
    } PanelType;

  static APanel    *createPanel(PanelType);
};

#endif /* !PANELFACTORY_HH_ */
