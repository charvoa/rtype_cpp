//
// IComponent.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sat Nov 28 05:05:15 2015 Louis Audibert
// Last update Sat Nov 28 05:12:21 2015 Louis Audibert
//

#ifndef _ICOMPONENT_HH_
# define _ICOMPONENT_HH_

# include "E_Component.hh"

class IComponent {

private:
  E_COMPONENT _type;

public:
  E_COMPONENT getType();

};

#endif /* _ICOMPONENT_HH_ */
