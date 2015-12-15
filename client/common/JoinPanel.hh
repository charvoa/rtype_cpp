//
// JoinPanel.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Wed Dec  9 04:57:09 2015 Serge Heitzler
// Last update Tue Dec 15 06:31:20 2015 Serge Heitzler
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

  static void  	        setError(const std::string &error);
  void			setUserInterface();
  int		        getAlpha();
  void		        setAlpha(int value);
  void		        join();
  void		        update();
  void			back();
  void			updateOnTextEntered(int);
  
private:

  std::string		_room;
  SFont			_filledFont;
  SFont			_emptyFont;
  int			_alpha;
};

#endif // JOINPANEL_HH
