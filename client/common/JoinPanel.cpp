#include "JoinPanel.hh"
#include "PanelFactory.hh"

JoinPanel::JoinPanel(RenderWindow *parent) : APanel(parent)
{

}

JoinPanel::~JoinPanel() {}

void    JoinPanel::join()
{
    _parent->addPanel(PanelFactory::JOIN_PANEL);
}

void    JoinPanel::back()
{
    _parent->back();
}
