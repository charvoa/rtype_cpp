//
// InputManager.hh for InputManager in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Wed Nov 25 05:31:24 2015 Serge Heitzler
// Last update Wed Nov 25 05:34:38 2015 Serge Heitzler
//

#ifndef INPUTMANAGER_HH_
#define INPUTMANAGER_HH_

#include "IInputManager.hh"

class	        InputManager : public IInputManager
{

  InputManager();
  InputManager(const std::string& pathToFile);
  ~InputManager();

  void		create();
  
};

#endif /* !INPUTMANAGER_HH_ */
