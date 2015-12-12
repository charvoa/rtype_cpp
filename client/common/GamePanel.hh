//
// GamePanel.hh for rty	pe in /home/nicolas/rendu/rtype_cpp/client/build
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri Dec 11 16:48:25 2015 Nicolas Girardot
// Last update Fri Dec 11 22:36:43 2015 Nicolas Girardot
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
  Text	*getScore();
  static void		setLife(const std::string &name, int life);
  static	void	setScore(int);
  static	void	display(std::vector<std::string> &vector);
private:
  Text	*_score;
  std::vector<PlayerIG *> _players;
  std::vector<Sprite *> _sprites;
};

#endif // GAMEPANEL_H
