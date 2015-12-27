//
// StartPanel.hh for StartPanel in /home/barnea_v/rendu/rtype_cpp/client/common
// 
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
// 
// Started on  Mon Nov 30 09:50:06 2015 Viveka BARNEAUD
// Last update Sun Dec 27 08:03:19 2015 Serge Heitzler
//

#ifndef STARTPANEL_H
#define STARTPANEL_H

#include <Button.hh>
#include <APanel.hh>

class		StartPanel : public APanel
{
public:
  StartPanel();
  ~StartPanel();
  
  void		createRoom();
  static void	goToRoom(std::vector<std::string> &vector, int from);
  void		joinRoom();
  void		demo();
  void		settings();
  void		exit();
  void	        update();
  void	        setUserInterface();
  int		getType();

private:

};

#endif /* !STARTPANEL_HH_ */
