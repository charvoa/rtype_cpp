//
// GamePanel.hh for rty	pe in /home/nicolas/rendu/rtype_cpp/client/build
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri Dec 11 16:48:25 2015 Nicolas Girardot
// Last update Sun Dec 13 12:08:23 2015 Serge Heitzler
//


#ifndef					GAMEPANEL_HH_
#define					GAMEPANEL_HH_

#include				<APanel.hh>
#include				<OtherPlayer.hh>
#include				<RenderWindow.hh>
#include				<Sprite.hh>
#include				<MainPlayer.hh>

class					GamePanel : public APanel
{
public:
  GamePanel();
  ~GamePanel();

  static void				setScore(const std::string &name, int life);
  static void		       		setLife(const std::string &name, int life);
  static void				setTeamScore(unsigned int value);
  static void				setCurrentWave(unsigned int value);
  static void				display(std::vector<std::string> &vector);
  static void			        newEnemy(std::vector<std::string> &vector);
  std::vector<Sprite *>			&getSprites();
  OtherPlayer				*getPlayerByName(const std::string &name);
  Text					&getTeamScore();
  MainPlayer				*getMainPlayer();
  Text					&getCurrentWave();
  void					render();
  void					update();
  void		       			drawOtherPlayer();
  std::map<int, Sprite*>		&getDicoSprites();
  std::map<std::string, Texture*>      	&getDicoTextures();

  
private:
  std::vector<Sprite*>			_sprites;
  MainPlayer				*_mainPlayer;
  std::vector<OtherPlayer*>		_otherPlayers;
  std::map<int, Sprite*>		_dicoSprites;
  std::map<std::string, Texture*>	_dicoTextures;
};

#endif /* GAMEPANEL_HH_ */
