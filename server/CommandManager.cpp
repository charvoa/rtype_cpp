//
// CommandManager.cpp for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Dec  1 11:32:51 2015 Nicolas Charvoz
// Last update Tue Dec  8 22:11:33 2015 Nicolas Charvoz
//

#include <CommandManager.hpp>

CommandManager::CommandManager() {}

CommandManager::~CommandManager() {}

bool CommandManager::addFunction(E_Command type, bool (Server::*cmd)(ANetwork::t_frame frame, void *data))
{
  _commands[type] = cmd;

  return true;
}
