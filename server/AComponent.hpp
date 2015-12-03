//
// AComponent.hpp for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Dec  2 17:43:05 2015 Nicolas Charvoz
// Last update Wed Dec  2 17:43:06 2015 Nicolas Charvoz
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
