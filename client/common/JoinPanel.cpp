//
// JoinPanel.cpp for Rtype in /home/nicolas/rendu/rtype_cpp/client/build
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed Dec  2 16:53:07 2015 Nicolas Girardot
// Last update Wed Dec  2 16:53:46 2015 Nicolas Girardot
//

#include "JoinPanel.hh"
#include "PanelFactory.hh"
#include "RenderWindow.hh"

JoinPanel::JoinPanel() : APanel()
{

}

JoinPanel::~JoinPanel() {}

void    JoinPanel::join()
{
  RenderWindow::getInstance()->addPanel(PanelFactory::JOIN_PANEL);
}

void    JoinPanel::back()
{
  RenderWindow::getInstance()->back();
}

void	JoinPanel::render()
{

}