//
// E_Command.hh for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Mon Nov 30 17:38:04 2015 Nicolas Charvoz
// Last update Wed Dec  9 05:36:09 2015 Antoine Garcia
//

#ifndef E_COMMAND_HH_
# define E_COMMAND_HH_

enum E_Command {
  C_CREATEROOM = 1,
  C_CHANGESETTINGS = 2,
  C_JOINROOM = 3,
  C_LAUNCHGAME = 4,
  C_MOVE = 5,
  C_SHOOT = 6,
  C_LOADSPRITESUCCESS = 7,
  C_LOADSPRITEERROR = 8,
  C_PLAYERLEFT = 13
};

#endif
