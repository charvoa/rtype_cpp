//
// CommandManager.hh for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Nov 25 16:43:58 2015 Nicolas Charvoz
// Last update Wed Dec  2 11:17:25 2015 Nicolas Charvoz
//

#ifndef COMMANDMANAGER_HPP_
# define COMMANDMANAGER_HPP_

# include <map>
# include "E_Command.hh"
# include "ANetwork.hpp"

class		CommandManager
{

public:

  CommandManager();
  ~CommandManager();
  bool addFunction(E_COMMAND, bool (*cmd)(ANetwork::t_frame frame));

  template <typename T>
  bool executeCommand(ANetwork::t_frame frame, T &other)
  {
    bool (*cmd)(ANetwork::t_frame) = _commands[(E_COMMAND)frame._idRequest];
    other.cmd(frame);
  }

  private:

  std::map<E_COMMAND, bool (*)(ANetwork::t_frame frame)> _commands;

};

#endif
