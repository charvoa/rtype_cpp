//
// SystemManager.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Nov 30 02:27:31 2015 Louis Audibert
// Last update Sat Dec 12 11:57:10 2015 Louis Audibert
//

#ifndef _SYSTEMMANAGER_HH_
# define _SYSTEMMANAGER_HH_

# include <iostream>
# include <vector>
# include <E_Component.hh>
# include <ASystem.hpp>
# include <SystemPos.hh>
# include <SystemHealth.hh>
# include <SystemGun.hh>
# include <SystemHitbox.hh>

class SystemManager
{
private:
  std::vector<ASystem*> _systems;

public:
  SystemManager();
  ~SystemManager();

  ASystem *getSystemByComponent(E_Component type);
  void	addSystemByType(E_Component type);
};

#endif /* _SYSTEMMANAGER_HH_ */
