#ifndef JOINPANEL_HH
#define JOINPANEL_HH

#include "APanel.hh"
#include "Button.hh"

class JoinPanel : public APanel
{
public:
  JoinPanel();
  ~JoinPanel();

  void			setUserInterface();
  void		        join();
  void			back();

private:

};

#endif // JOINPANEL_HH
