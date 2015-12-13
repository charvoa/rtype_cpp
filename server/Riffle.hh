//
// Riffle.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sun Dec 13 04:46:59 2015 Louis Audibert
// Last update Sun Dec 13 04:59:11 2015 Louis Audibert
//

#ifndef _RIFFLE_HH_
# define _RIFFLE_HH_

# include <AEntity.hh>

class Riffle : public AEntity
{
public:
  Riffle(int id, AEntity *parent);
  ~Riffle();
};

#endif
