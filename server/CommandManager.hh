//
// CommandManager.hh for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Nov 25 16:43:58 2015 Nicolas Charvoz
// Last update Mon Nov 30 18:31:26 2015 Nicolas Charvoz
//

#ifndef COMMANDMANAGER_HH_
# define COMMANDMANAGER_HH_

# include <map>
# include "E_Command.hh"
# include "ANetwork.hpp"

class		CommandManager
{

public:

  CommandManager() {};
  ~CommandManager() {};
  bool addFunction(E_COMMAND, bool (*cmd)(ANetwork::t_frame frame));

  template <typename T>
  bool executeCommand(ANetwork::t_frame frame, T&) {

  }

  private:

  std::map<E_COMMAND, bool (*)(ANetwork::t_frame frame)> _commands;

};

#endif
