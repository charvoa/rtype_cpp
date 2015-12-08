//
// SystemManager.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Nov 30 02:27:31 2015 Louis Audibert
// Last update Tue Dec  8 22:23:11 2015 Nicolas Charvoz
//

#ifndef _SYSTEMMANAGER_HH_
# define _SYSTEMMANAGER_HH_

# include <iostream>
# include <vector>
# include <E_Component.hh>
# include <ASystem.hh>
# include <SystemPos.hh>
# include <SystemHealth.hh>
# include <SystemGun.hh>

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
