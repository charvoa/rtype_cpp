//
// SystemManager.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Nov 30 02:27:31 2015 Louis Audibert
// Last update Mon Dec 21 02:32:55 2015 Louis Audibert
//

#ifndef _SYSTEMMANAGER_HH_
# define _SYSTEMMANAGER_HH_

# include <iostream>
# include <list>
# include <cstdlib>
# include <E_Component.hh>
# include <ASystem.hpp>
# include <SystemPos.hh>
# include <SystemHealth.hh>
# include <SystemGun.hh>
# include <SystemHitbox.hh>
# include <SystemShield.hh>

class SystemManager
{
private:
  std::list<ASystem*> _systems;

public:
  SystemManager();
  SystemManager(SystemManager *copy);
  ~SystemManager();

  ASystem *getSystemByComponent(E_Component type);
  void	addSystemByType(E_Component type);
  void	removeSystemByType(E_Component type);
};

#endif /* _SYSTEMMANAGER_HH_ */
