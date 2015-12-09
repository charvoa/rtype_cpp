//
// AEntity.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Nov 30 06:37:36 2015 Louis Audibert
// Last update Wed Dec  9 06:57:53 2015 Louis Audibert
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
  // virtual void update();
  void	addSystem(E_Component type);
  bool	setType(E_EntityType type);
  E_EntityType getType() const;
  int	getId() const;
  SystemManager *getSystemManager();
};

#endif /* _AENTITY_HH_ */
