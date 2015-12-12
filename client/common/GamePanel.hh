//
// GamePanel.hh for rty	pe in /home/nicolas/rendu/rtype_cpp/client/build
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri Dec 11 16:48:25 2015 Nicolas Girardot
// Last update Sat Dec 12 02:11:49 2015 Serge Heitzler
//


#ifndef GAMEPANEL_H
#define GAMEPANEL_H

#include <APanel.hh>
#include <PlayerIG.hh>
#include <RenderWindow.hh>
#include <Sprite.hh>

class GamePanel : public APanel
{
public:
  GamePanel();
  ~GamePanel();

  void render();
  std::vector<Sprite *> &getSprites();
  PlayerIG	*getPlayerByName(const std::string &name);
  static void		setLife(const std::string &name, int life);
  Text			*getTeamScore();
  static	void	setTeamScore(int);
  static	void	display(std::vector<std::string> &vector);
private:

  Text			*_teamScore;
  
  std::vector<PlayerIG *> _players;
  std::vector<Sprite *> _sprites;
};

#endif // GAMEPANEL_H
