//
// SystemHealth.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Nov 30 01:57:34 2015 Louis Audibert
// Last update Mon Nov 30 02:18:19 2015 Louis Audibert
//

#ifndef _SYSTEMHEALTH_HH_
# define _SYSTEMHEALTH_HH_

# include <iostream>
# include "ASystem.hh"
# include "Health.hh"

class SystemHealth : public ASystem
{
public:
  SystemHealth();
  ~SystemHealth();

  bool update(int health);
};

#endif /* _SYSTEMHEALTH_HH_ */
