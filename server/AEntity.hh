//
// AEntity.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Nov 30 06:37:36 2015 Louis Audibert
// Last update Tue Dec  1 02:53:52 2015 Louis Audibert
//

#ifndef _AENTITY_HH_
# define _AENTITY_HH_

# include <iostream>
# include "E_EntityType.hh"
# include "E_Component.hh"
# include "SystemManager.hh"

class AEntity
{
protected:
  int		_id;
  E_ENTITYTYPE	_type;
  SystemManager	_systemManager;
  char		_color;
  //  AI		_brain;

public:
  AEntity(int id);
  ~AEntity();

  bool	update(int, int);
  bool	update(int);
  void	addSystem(E_COMPONENT type);
  bool	setType(E_ENTITYTYPE type);
  E_ENTITYTYPE getType() const;
  int	getId() const;
};

#endif /* _AENTITY_HH_ */
