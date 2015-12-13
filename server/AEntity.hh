//
// AEntity.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Nov 30 06:37:36 2015 Louis Audibert
// Last update Sun Dec 13 07:25:43 2015 Antoine Garcia
//

#ifndef _AENTITY_HH_
# define _AENTITY_HH_

# include <iostream>
# include <vector>
# include <E_EntityType.hh>
# include <E_Component.hh>
# include <SystemManager.hh>
# include <Case.hh>

class AEntity
{
protected:
  int		_id;
  E_EntityType	_type;
  SystemManager	_systemManager;
  char		_color;
  AEntity	*_parent;
  std::string	_name;

public:
  AEntity(int id);
  AEntity(int id, AEntity *parent);
  virtual ~AEntity(){};

  bool	update(int, int);
  bool	update(int);
  bool	update(std::vector<Case*>);
  void	addSystem(E_Component type);
  bool	setType(E_EntityType type);
  E_EntityType getType() const;
  int	getId() const;
  SystemManager *getSystemManager();
  bool	checkColision(AEntity *entity);
  const std::string &getName() const;
};

#endif /* _AENTITY_HH_ */
