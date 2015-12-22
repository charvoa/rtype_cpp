//
// MainPlayer.hh for Rtype in /home/nicolas/rendu/rtype_cpp/client/common
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri Dec 11 14:51:45 2015 Nicolas Girardot
// Last update Tue Dec 22 04:40:16 2015 Serge Heitzler
//

#ifndef MAINPLAYER_HH_
#define MAINPLAYER_HH_

#include <Text.hh>
#include <Sprite.hh>

class MainPlayer
{
public:
  MainPlayer(unsigned int id);
  ~MainPlayer();

  const std::string	&getUsername() const;
  unsigned int	        getScore();
  void		setNbRocket(unsigned int nb);
  void		setNbLife(unsigned int nb);
  void	        setScore(unsigned int score);
  void		render();

private:

  std::string			_username;

  Sprite			*_spaceShip;
  Text				*_score;
  Text				*_nbrRocketText;

  unsigned int 			_nbrLife;
  unsigned int	       		_nbrRocket;

  std::vector<Sprite*>		_hearts;
  std::vector<Sprite*>		_ammos;
};

#endif /* MAINPLAYER_HH_ */
