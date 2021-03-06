//
// GamePanel.hh for rty	pe in /home/nicolas/rendu/rtype_cpp/client/build
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri Dec 11 16:48:25 2015 Nicolas Girardot
// Last update Sun Jan  3 05:40:04 2016 Serge Heitzler
//


#ifndef					GAMEPANEL_HH_
#define					GAMEPANEL_HH_

#ifdef _WIN32
#include <NetworkWin.hpp>
#include <ThreadWin.hpp>
#else
#include <Network.hpp>
#include <ThreadUnix.hpp>
#endif

#include				<APanel.hh>
#include				<OtherPlayer.hh>
#include				<RenderWindow.hh>
#include				<Sprite.hh>
#include				<Explosion.hh>
#include				<MainPlayer.hh>
#include				<Asteroid.hh>
#include				<Random.hpp>
#include				<memory>


class					GamePanel : public APanel
{
public:
  GamePanel();
  ~GamePanel();

  static void				setScore(const std::string &name, int life);
  static void		       		setLife(const std::string &name, int life);
  static void				setCurrentWave(unsigned int value);
  static void				display(std::vector<std::string> &vector);
  static void			        endGame(std::vector<std::string> &vector);
  static void			        newEntity(std::vector<std::string> &vector);
  static void			        ammoLeft(std::vector<std::string> &vector);
  static void			        deleteEntity(std::vector<std::string> &vector);
  static void				die(int i, int id);
  static void			        hit(int i, int id);
  static void  				playerLeft(const std::string &playerName);
  void  				setTeamScore(unsigned int score);
  unsigned int  			getTeamScoreString();
  void					setTeamScoreString(int score);
  

  std::vector<Sprite *>			&getSprites();
  OtherPlayer				*getPlayerByName(const std::string &name);
  Text					&getTeamScore();
  Text					&getCurrentWave();
  void					render();
  void					update();
  void		       			drawOtherPlayer();
  std::vector<Explosion *>		&getExplosions();
  std::map<int, Sprite*>		&getDicoSprites();
  std::map<std::string, Texture*>      	&getDicoTextures();
  void					setPlanetTexture(int i);
  void					setPlayers(int nbPlayer, int currentPlayer);
  void					setEscapeMenu(bool value);
  bool					getEscapeMenu();
  void					setEndGame(bool value);
  bool					getEndGame();
  void					resume();
  void					exit();
  int					getType();
  MainPlayer				&getMainPlayer();
  void					setWaveNumber(unsigned int value);
  void				        addPlayerLeft();
  unsigned int	       		        getPlayerLeft();

private:

  std::vector<Sprite*>			_sprites;
  std::vector<Explosion *>		_explosion;
  MainPlayer				*_mainPlayer;
  std::vector<OtherPlayer*>		_otherPlayers;
  std::map<int, Sprite*>		_dicoSprites;
  std::map<int, Asteroid*>		_dicoAsteroids;
  std::map<std::string, Texture*>      	_dicoTextures;
  std::unique_ptr<AThread>		_t;
  Random				*_randPosY;
  Random				*_randPlanet;
  Random				*_randBackground;
  bool					_escapeKey;
  bool					_endGame;
  unsigned int				_teamScore;
  unsigned int				_wave;
  unsigned int				_playerLeft;
};

#endif /* !GAMEPANEL_HH_ */
