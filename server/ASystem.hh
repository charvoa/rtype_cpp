//
// ASystem.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Nov 30 01:38:40 2015 Louis Audibert
// Last update Mon Nov 30 08:03:11 2015 Louis Audibert
//

#ifndef _ASYSTEM_HH_
# define _ASYSTEM_HH_

# include "AComponent.hpp"

class ASystem
{
protected:
  AComponent *_component;

public:
  explicit ASystem(){};
  virtual ~ASystem(){};
  AComponent *getComponent() const;
};

#endif /* _ASYSTEM_HH_ */
