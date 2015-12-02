//
// StartPanel.cpp for StartPanel in /home/barnea_v/rendu/rtype_cpp/client/common
// 
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
// 
// Started on  Mon Nov 30 09:52:01 2015 Viveka BARNEAUD
// Last update Mon Nov 30 17:26:39 2015 Viveka BARNEAUD
//

#include "PanelFactory.hh"
#include "StartPanel.hh"
#include "RenderWindow.hh"

StartPanel::StartPanel() : APanel()
{

}

StartPanel::~StartPanel() {}

void        StartPanel::joinRoom()
{
	(RenderWindow::getInstance())->addPanel(PanelFactory::JOIN_PANEL);
}

void        StartPanel::createRoom()
{
	(RenderWindow::getInstance())->addPanel(PanelFactory::ROOM_PANEL);
}

void        StartPanel::demo()
{
	(RenderWindow::getInstance())->addPanel(PanelFactory::DEMO_PANEL);
}

void        StartPanel::exit()
{

}

void        StartPanel::settings()
{
	(RenderWindow::getInstance())->addPanel(PanelFactory::SETTINGS_PANEL);
}

void		StartPanel::render()
{

}