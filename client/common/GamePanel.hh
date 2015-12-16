//
// GamePanel.hh for rty	pe in /home/nicolas/rendu/rtype_cpp/client/build
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri Dec 11 16:48:25 2015 Nicolas Girardot
// Last update Wed Dec 16 15:22:47 2015 Nicolas Girardot
//


#ifndef					GAMEPANEL_HH_
#define					GAMEPANEL_HH_

#include				<APanel.hh>
#include				<OtherPlayer.hh>
#include				<RenderWindow.hh>
#include				<Sprite.hh>
#include				<Explosion.hh>
#include				<MainPlayer.hh>
#include				<Random.hpp>

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
  static void			        newEntity(std::vector<std::string> &vector);
  static void			        deleteEntity(std::vector<std::string> &vector);
  static void				die(int i);
  std::vector<Sprite *>			&getSprites();
  OtherPlayer				*getPlayerByName(const std::string &name);
  Text					&getTeamScore();
  MainPlayer				*getMainPlayer();
  Text					&getCurrentWave();
  void					render();
  void					update();
  void		       			drawOtherPlayer();
  std::map<int, Sprite*>		&getDicoSprites();
  std::map<int, Texture*>	      	&getDicoTextures();
  void					setPlanetTexture(int i);
  void					setPlayers(int nbPlayer, int currentPlayer);
  void					addExplosion();

private:
  std::vector<Sprite*>			_sprites;
  std::vector<Explosion *>		_explosion;
  MainPlayer				*_mainPlayer;
  std::vector<OtherPlayer*>		_otherPlayers;
  std::map<int, Sprite*>		_dicoSprites;
  std::map<int, Texture*>		_dicoTextures;
  Random				*_randPosY;
  Random				*_randPlanet;
  Random				*_randBackground;
};

#endif /* GAMEPANEL_HH_ */
