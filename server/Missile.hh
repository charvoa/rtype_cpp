//
// Missile.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sun Dec 13 05:00:00 2015 Louis Audibert
// Last update Sun Dec 13 05:02:20 2015 Louis Audibert
//

#ifndef _MISSILE_HH_
# define _MISSILE_HH_

# include <AEntity.hh>

class Missile : public AEntity
{
public:
  Missile(int id, AEntity *parent);
  ~Missile();
};

#endif /* _MISSILE_HH_  */
