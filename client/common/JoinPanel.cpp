#include "JoinPanel.hh"
#include "PanelFactory.hh"
#include "RenderWindow.hh"

JoinPanel::JoinPanel() : APanel()
{

}

JoinPanel::~JoinPanel() {}

void    JoinPanel::join()
{
    (RenderWindow::getInstance())->addPanel(PanelFactory::JOIN_PANEL);
}

void    JoinPanel::back()
{
	(RenderWindow::getInstance())->back();
}

void	JoinPanel::render()
{

}