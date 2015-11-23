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
