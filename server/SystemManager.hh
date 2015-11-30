//
// SystemManager.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Mon Nov 30 02:27:31 2015 Louis Audibert
// Last update Mon Nov 30 05:44:22 2015 Louis Audibert
//

#ifndef _SYSTEMMANAGER_HH_
# define _SYSTEMMANAGER_HH_

# include <iostream>
# include <vector>
# include "E_Component.hh"

class SystemManager
{
private:
  std::vector<ASystem*> _systems;

public:
  SystemManager();
  ~SystemManager();

  ASystem *getSystemByComponent(E_COMPONENT type);
  void	addSystemByType(E_COMPONENT type);
};

#endif /* _SYSTEMMANAGER_HH_ */
