//
// DemoPanel.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Sun Dec 27 08:14:42 2015 Serge Heitzler
// Last update Sun Dec 27 08:14:43 2015 Serge Heitzler
//

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

#endif /* !DEMOPANEL_HH */
