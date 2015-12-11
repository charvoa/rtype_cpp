//
// PlayerIG.hh for Rtype in /home/nicolas/rendu/rtype_cpp/client/common
//
// Made by Nicolas Girardot
// Login   <girard_s@epitech.net>
//
// Started on  Fri Dec 11 14:51:45 2015 Nicolas Girardot
// Last update Fri Dec 11 17:30:03 2015 Nicolas Girardot
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
  void	setName(const std::string &);
  const std::string &getName();

private:
  Text	*_life;
  Text	*_name;
  std::string _nameValue;
  int	_nbrLife;
  Sprite	*vessel;
  Sprite	*heart;
};

#endif
