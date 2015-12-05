//
// CommandManager.hh for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Nov 25 16:43:58 2015 Nicolas Charvoz
// Last update Sat Dec  5 16:04:47 2015 Nicolas Charvoz
//

#ifndef COMMANDMANAGER_HPP_
# define COMMANDMANAGER_HPP_

# include <map>
# include <E_Command.hh>
# include <ANetwork.hpp>

class		CommandManager
{

public:

  CommandManager();
  ~CommandManager();
  bool addFunction(E_COMMAND, bool (*cmd)(ANetwork::t_frame frame, void*));

  template <typename T>
  bool executeCommand(ANetwork::t_frame frame, void *data, T &other)
  {
    bool (*cmd)(ANetwork::t_frame) = _commands[(E_COMMAND)frame.idRequest];
    other.cmd(frame, data);
    return true;
  }

  private:

  std::map<E_COMMAND, bool (*)(ANetwork::t_frame frame, void*)> _commands;

};

#endif
