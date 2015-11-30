//
// PanelFactory.cpp for PanelFactory in /home/barnea_v/rendu/rtype_cpp/client/common
// 
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
// 
// Started on  Mon Nov 30 09:51:41 2015 Viveka BARNEAUD
// Last update Mon Nov 30 10:08:02 2015 Viveka BARNEAUD
//

#include "PanelFactory.hh"
#include "RoomPanel.hh"
#include "SettingsPanel.hh"
#include "GamePanel.hh"
#include "DemoPanel.hh"
#include "PlayPanel.hh"
#include "StartPanel.hh"
#include "LoadingPanel.hh"

PanelFactory::PanelFactory()
{

}

PanelFactory::~PanelFactory() {}

void		PanelFactory::createPanel(PanelType type)
{
  if (_panel != NULL)
    delete _panel;
  switch (type)
    {
    case ROOM_PANEL:
      _panel = new RoomPanel;
      break;
    case SETTINGS_PANEL:
      _panel = new SettingsPanel;
      break;
    case GAME_PANEL:
      _panel = new GamePanel;
      break;
    case DEMO_PANEL:
      _panel = new DemoPanel;
      break;
    case PLAY_PANEL:
      _panel = new PlayPanel;
      break;
    case START_PANEL:
      _panel = new StartPanel;
      break;
    case LOADING_PANEL:
      _panel = new LoadingPanel;
      break;
    }
}

APanel		*PanelFactory::getPanel() const
{
  return (_panel);
}
