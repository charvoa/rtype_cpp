//
// CommandManager.cpp for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Tue Dec  1 11:32:51 2015 Nicolas Charvoz
// Last update Wed Dec  2 13:15:49 2015 Nicolas Charvoz
//

#include "CommandManager.hpp"

CommandManager::CommandManager() {}

CommandManager::~CommandManager() {}

bool CommandManager::addFunction(E_COMMAND type, bool (*cmd)(ANetwork::t_frame frame))
{
  _commands[type] = cmd;
  return true;
}
