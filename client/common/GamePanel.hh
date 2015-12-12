//
// GamePanel.hh for rty	pe in /home/nicolas/rendu/rtype_cpp/client/build
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri Dec 11 16:48:25 2015 Nicolas Girardot
// Last update Sat Dec 12 19:52:02 2015 Nicolas Girardot
//


#ifndef GAMEPANEL_HH_
#define GAMEPANEL_HH_

#include <APanel.hh>
#include <PlayerIG.hh>
#include <RenderWindow.hh>
#include <Sprite.hh>

class GamePanel : public APanel
{
public:
  GamePanel();
  ~GamePanel();

  std::vector<Sprite *> &getSprites();
  PlayerIG	*getPlayerByName(const std::string &name);
  static void		setLife(const std::string &name, int life);
  Text			&getTeamScore();
  static	void	setTeamScore(int);
  static	void	display(std::vector<std::string> &vector);
  static	void	changeWave(int waveNbr)

private:

  std::vector<PlayerIG *> _players;
  std::vector<Sprite *> _sprites;
};

#endif /* GAMEPANEL_HH_ */
