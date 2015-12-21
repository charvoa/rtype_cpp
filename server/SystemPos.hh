//
// SystemPos.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Nov 30 01:50:45 2015 Louis Audibert
// Last update Mon Dec 21 02:26:09 2015 Louis Audibert
//

#ifndef _SYSTEMPOS_HH_
# define _SYSTEMPOS_HH_

# include <iostream>
# include <ASystem.hpp>
# include <ComponentPosition.hh>

class SystemPos : public ASystem
{
public:
  SystemPos();
  ~SystemPos();

  bool update(int x, int y);
};

#endif /* _SYSTEMPOS_HH_ */
