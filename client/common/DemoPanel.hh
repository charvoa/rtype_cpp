#ifndef DEMOPANEL_HH
#define DEMOPANEL_HH

#include <APanel.hh>
#include <PanelFactory.hh>

class DemoPanel : public APanel
{
public:
    DemoPanel();
    ~DemoPanel();

	void render();
	int	getType();
};

#endif // DEMOPANEL_HH
