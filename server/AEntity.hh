//
// AEntity.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Nov 30 06:37:36 2015 Louis Audibert
// Last update Fri Dec 11 17:24:25 2015 Joris Bertomeu
//

#ifndef _AENTITY_HH_
# define _AENTITY_HH_

# include <iostream>
# include <E_EntityType.hh>
# include <E_Component.hh>
# include <SystemManager.hh>

class AEntity
{
protected:
  int		_id;
  E_EntityType	_type;
  SystemManager	_systemManager;
  char		_color;

public:
  AEntity(int id);
  ~AEntity();

  bool	update(int, int);
  bool	update(int);
  void	addSystem(E_Component type);
  bool	setType(E_EntityType type);
  E_EntityType getType() const;
  int	getId() const;
  SystemManager *getSystemManager();
};

#endif /* _AENTITY_HH_ */
