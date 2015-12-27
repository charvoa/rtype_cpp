//
// OtherPlayer.hh for Rtype in /home/nicolas/rendu/rtype_cpp/client/common
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri Dec 11 14:51:45 2015 Nicolas Girardot
// Last update Tue Dec 22 04:49:10 2015 Serge Heitzler
//

#ifndef OTHERPLAYER_HH_
#define OTHERPLAYER_HH_

#include <Text.hh>
#include <Sprite.hh>
#include <RenderWindow.hh>

class OtherPlayer
{
public:
  OtherPlayer(unsigned int pos, unsigned int id);
  ~OtherPlayer();

  void			setLife(unsigned int);
  void			setUsername(const std::string &);
  Sprite		&getSprite();
  const std::string	&getUsername();
  void			setScore(int );
  void			render();

private:

  std::string			_username;
  Sprite			*_spaceShip;
  Sprite			*_greyBack;
  Text				*_score;
  int				_nbrLife;
  std::vector<Sprite*>		_hearts;
};

#endif /* OTHERPLAYER_HH_ */
