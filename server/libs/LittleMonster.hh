//
// LittleMonster.hh for rtype in /home/audibel/rendu/rtype_cpp/server/libs
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Dec  7 00:42:25 2015 Louis Audibert
// Last update Mon Dec  7 07:25:27 2015 Louis Audibert
//

#ifndef _LITTLEMONSTER_HH_
# define _LITTLEMONSTER_HH_

# include "../AEntity.hh"
# include "../E_Component.hh"

class LittleMonster : public AEntity
{
private:
  int	_health;
  int	_x;
  int	_y;

public:
  LittleMonster(int id);
  ~LittleMonster();

  virtual void update(AEntity *);
};

#endif
