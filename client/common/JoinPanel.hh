//
// JoinPanel.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Wed Dec  9 04:57:09 2015 Serge Heitzler
// Last update Thu Dec 10 05:41:18 2015 Serge Heitzler
//

#ifndef JOINPANEL_HH
#define JOINPANEL_HH

#include <string>
#include <APanel.hh>
#include <Button.hh>

class JoinPanel : public APanel
{
public:
  JoinPanel();
  ~JoinPanel();

  void			setUserInterface();
  void		        join();
  void			back();
  void			updateOnTextEntered(int);
  
private:

  std::string		_room;
  SFont			_filledFont;
  SFont			_emptyFont;
};

#endif // JOINPANEL_HH
