//
// CommandManager.hh for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Nov 25 16:43:58 2015 Nicolas Charvoz
// Last update Tue Dec  8 22:11:21 2015 Nicolas Charvoz
//

#ifndef COMMANDMANAGER_HPP_
# define COMMANDMANAGER_HPP_

# include <map>
# include <E_Command.hh>
# include <ANetwork.hpp>

class Server;

class		CommandManager
{

public:
  CommandManager();
  ~CommandManager();
  bool addFunction(E_Command, bool (Server::*cmd)(ANetwork::t_frame frame, void*));

  template <typename T>
  bool executeCommand(ANetwork::t_frame frame, void *data, T *other)
  {
    bool (Server::*cmd)(ANetwork::t_frame, void*) = _commands[(E_Command)frame.idRequest];

    (dynamic_cast<Server*>(other)->*cmd)(frame, data);
    // other->cmd(frame, data);
    return true;
  }

  private:

  std::map<E_Command, bool (Server::*)(ANetwork::t_frame, void*)> _commands;

};

#endif
