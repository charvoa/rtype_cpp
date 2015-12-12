//
// PlayerIG.hh for Rtype in /home/nicolas/rendu/rtype_cpp/client/common
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri Dec 11 14:51:45 2015 Nicolas Girardot
// Last update Sat Dec 12 02:05:30 2015 Serge Heitzler
//

#ifndef PLAYERIG_HH_
#define PLAYERIG_HH_

#include <Text.hh>
#include <Sprite.hh>

class PlayerIG
{
public:
  PlayerIG();
  ~PlayerIG();
  void	setLife(unsigned int);
  void	setUsername(const std::string &);
  const std::string &getUsername();
  
private:

  std::string			_username;

  Text				*_score;

  Sprite			*_spaceShip;

  int				_nbrLife;

  std::vector<Sprite*>		_hearts;
};

#endif
