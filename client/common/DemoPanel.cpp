//
// DemoPanel.cpp for RType in /home/nicolas/rendu/rtype_cpp/client/common
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Wed Dec  9 13:50:11 2015 Nicolas Girardot
// Last update Wed Dec  9 13:54:47 2015 Nicolas Girardot
//

#include <DemoPanel.hh>

DemoPanel::DemoPanel() : APanel()
{
	_type = PanelFactory::DEMO_PANEL;
}

DemoPanel::~DemoPanel() {}

void		DemoPanel::render()
{

}

int	DemoPanel::getType()
{
	return _type;
}