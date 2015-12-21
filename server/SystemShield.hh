//
// SystemShield.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Dec 21 02:23:18 2015 Louis Audibert
// Last update Mon Dec 21 02:35:17 2015 Louis Audibert
//

#ifndef _SYSTEMSHIELD_HH_
# define _SYSTEMSHIELD_HH_

# include <iostream>
# include <ASystem.hpp>
# include <ComponentShield.hh>

class SystemShield : public ASystem
{
public:
  SystemShield();
  ~SystemShield();

  bool update(bool);
};

#endif /* _SYSTEMSHIELD_HH_ */
