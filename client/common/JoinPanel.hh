//
// JoinPanel.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Wed Dec  9 04:57:09 2015 Serge Heitzler
// Last update Wed Dec  9 04:57:11 2015 Serge Heitzler
//

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
