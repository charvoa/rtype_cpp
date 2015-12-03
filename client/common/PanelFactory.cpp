//
// PanelFactory.cpp for PanelFactory in /home/barnea_v/rendu/rtype_cpp/client/common
//
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
//
// Started on  Mon Nov 30 09:51:41 2015 Viveka BARNEAUD
// Last update Thu Dec  3 16:40:19 2015 Nicolas Girardot
//

#include "PanelFactory.hh"
#include "RoomPanel.hh"
#include "SettingsPanel.hh"
#include "GamePanel.hh"
#include "DemoPanel.hh"
#include "JoinPanel.hh"
#include "StartPanel.hh"
#include "LoadingPanel.hh"

PanelFactory::PanelFactory()
{

}

PanelFactory::~PanelFactory() {}

APanel		*PanelFactory::createPanel(PanelType type)
{
  switch (type)
    {
    case ROOM_PANEL:
      return (new RoomPanel);
    case SETTINGS_PANEL:
      return (new SettingsPanel);
    case GAME_PANEL:
      return (new GamePanel);
    case DEMO_PANEL:
      return (new DemoPanel);
    case JOIN_PANEL:
      return (new JoinPanel);
    case START_PANEL:
      return (new StartPanel);
    default:
      return (new LoadingPanel);
    }
}
