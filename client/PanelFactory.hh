//
// PanelFactory.hh for rtype in /home/nicolas/rendu/rtype_cpp/client
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed Nov 25 10:15:28 2015 Nicolas Girardot
// Last update Wed Nov 25 10:15:29 2015 Nicolas Girardot
//

#ifndef PANELFACTORY_H
#define PANELFACTORY_H


class PanelFactory
{
public:
    PanelFactory();
    ~PanelFactory();

    enum e_panelType
    {
        ROOM_PANEL,
        SETTINGS_PANEL,
        GAME_PANEL,
        DEMO_PANEL,
        PLAY_PANEL,
        START_PANEL,
        LOADING_PANEL
    } PanelType;

    void    createPanel(PanelType);

    APanel  *getPanel() const;

private:
    APanel  *_panel;
};

#endif // PANELFACTORY_H
