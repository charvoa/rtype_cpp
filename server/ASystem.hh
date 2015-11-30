//
// ASystem.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Nov 30 01:38:40 2015 Louis Audibert
// Last update Mon Nov 30 06:19:53 2015 Louis Audibert
//

#ifndef _ASYSTEM_HH_
# define _ASYSTEM_HH_

# include "AComponent.hpp"

class ASystem
{
protected:
  AComponent *_component;

public:
  AComponent *getComponent() const;
};

#endif /* _ASYSTEM_HH_ */
