//
// APanel.hh for APanel in /home/barnea_v/rendu/rtype_cpp/client/common
// 
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
// 
// Started on  Mon Nov 30 09:50:56 2015 Viveka BARNEAUD
// Last update Wed Dec  2 05:50:49 2015 Serge Heitzler
//

#ifndef APANEL_HH
#define APANEL_HH

#include "RenderWindow.hh"

class		APanel
{
public:
  
  APanel(RenderWindow *parent);
  ~APanel();

  void		render();
  void		hide();
  
protected:
  
  RenderWindow	*_parent;
};

#endif // APANEL_HH
