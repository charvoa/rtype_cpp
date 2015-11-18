//
// IComponent.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sat Nov 28 05:05:15 2015 Louis Audibert
// Last update Mon Nov 30 05:51:06 2015 Antoine Garcia
//

#ifndef _ICOMPONENT_HH_
# define _ICOMPONENT_HH_

# include "E_Component.hh"

class AComponent {

protected:
  E_COMPONENT _type;

public:
  virtual ~AComponent();
  E_COMPONENT getType();

};

#endif /* _ICOMPONENT_HH_ */
