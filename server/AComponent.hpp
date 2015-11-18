//
// IComponent.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Sat Nov 28 05:05:15 2015 Louis Audibert
// Last update Tue Nov 17 23:55:23 2015 Joris Bertomeu
//

#ifndef _ICOMPONENT_HH_
# define _ICOMPONENT_HH_

# include "E_Component.hh"

class AComponent {

protected:
  E_COMPONENT _type;

public:
  explicit	AComponent() {};
  virtual ~AComponent() {};
  E_COMPONENT getType();

};

#endif /* _ICOMPONENT_HH_ */
