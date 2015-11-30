//
// IIputManager.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Mon Nov 23 08:20:13 2015 Serge Heitzler
// Last update Wed Nov 25 05:49:46 2015 Serge Heitzler
//

#ifndef IINPUTMANAGER_HH_
#define IINPUTMANAGER_HH_

#include <SFML/Graphics.hpp>
#include <string>
#include <map>

typedef	enum	MenuEvent
{
};

class	        IInputManager
{

  IInputManager();
  IInputManager(const std::string& pathToFile);
  ~IInputManager();

  void		create() = 0;

private:

  typedef std::map<MenuEvent, funcs>PointersOnFuncs;
  typedef void(IInputManager::*funcs)(DataFromClient &data);
  funcs _ptr;
  PointersOnFuncs	        _functions;
  
};

#endif /* !IINPUTMANAGER_HH_ */
