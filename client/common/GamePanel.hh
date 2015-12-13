//
// GamePanel.hh for rty	pe in /home/nicolas/rendu/rtype_cpp/client/build
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri Dec 11 16:48:25 2015 Nicolas Girardot
// Last update Sun Dec 13 07:19:49 2015 Serge Heitzler
//


#ifndef GAMEPANEL_HH_
#define GAMEPANEL_HH_

#include <APanel.hh>
#include <OtherPlayer.hh>
#include <RenderWindow.hh>
#include <Sprite.hh>
#include <MainPlayer.hh>

class GamePanel : public APanel
{
public:
  GamePanel();
  ~GamePanel();

  std::vector<Sprite *> &getSprites();
  OtherPlayer	*getPlayerByName(const std::string &name);
  static void		setLife(const std::string &name, int life);
  Text			&getTeamScore();
  static	void	setTeamScore(unsigned int value);
  Text			&getCurrentWave();
  static	void	setCurrentWave(unsigned int value);
  static	void	display(std::vector<std::string> &vector);
  void		render();
  void		update();
  void		drawOtherPlayer();
  std::map<std::string, Texture*>	&getDictionary();

  
private:
  std::vector<OtherPlayer*> _otherPlayers;
  std::vector<Sprite*> _sprites;
  MainPlayer		*_mainPlayer;

  std::map<std::string, Texture*>	_dictionary;
};

#endif /* GAMEPANEL_HH_ */
