//
// AEntity.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Nov 30 06:37:36 2015 Louis Audibert
// Last update Sun Dec 20 14:35:28 2015 Nicolas Charvoz
//

#ifndef _AENTITY_HH_
# define _AENTITY_HH_

# include <iostream>
# include <list>
# include <chrono>
# include <E_EntityType.hh>
# include <E_Component.hh>
# include <SystemManager.hh>
# include <Case.hh>

class AEntity
{

protected:
  int		_id;
  E_EntityType	_type;
  SystemManager	*_systemManager;
  char		_color;
  AEntity	*_parent;
  std::string	_name;

public:
  AEntity(int id);
  AEntity(int id, AEntity *parent);
  virtual ~AEntity(){};

  bool	update(int, int);
  bool	update(int);
  bool	update(std::list<Case*>);
  virtual void	addSystem(E_Component type);
  void	removeSystem(E_Component type);
  bool	setType(E_EntityType type);
  E_EntityType getType() const;
  int	getId() const;
  void	setId(int id);
  SystemManager *getSystemManager();
  void	refreshSystemManager();
  bool	checkColision(AEntity *entity);
  const std::string &getName() const;
  void setName(std::string);
  bool	setParent(AEntity *);
  AEntity *getParent();
  std::list<Case*> refreshHitbox();
};

#endif /* _AENTITY_HH_ */
