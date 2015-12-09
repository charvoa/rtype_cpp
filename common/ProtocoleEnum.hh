//
// ProtocoleEnum.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Tue Dec  1 10:50:13 2015 Serge Heitzler
// Last update Wed Dec  9 15:30:22 2015 Nicolas Charvoz
//

#ifndef PROTOCOLEENUM_HH_
#define PROTOCOLEENUM_HH_

typedef enum E_Command
  {
    C_CREATEROOM = 1,
    C_CHANGE_SETTINGS = 2,
    C_JOINROOM = 3,
    C_LAUNCHGAME = 4,
    C_MOVE = 5,
    C_SHOOT = 6,
    C_LOAD_SPRITE_SUCCESS = 7,
    C_LOAD_SPRITE_ERROR = 8,
    C_LOAD_SPRITE_IN_PROGRESS = 9,
    C_SEND_MD5 = 10,
    C_PLAYERLEFT = 13
  } E_Command;

typedef enum RequestFromServer
  {
    S_DISPLAY = 100,
    S_CREATE_ROOM = 101,
    S_CREATE_ROOM_ERROR = 102,
    S_JOIN_SUCCESS = 103,
    S_JOIN_ERROR = 104,
    S_GAME_LAUNCHED = 105,
    S_NEW_PLAYER_CONNECTED = 106,
    S_PLAYER_LEFT = 107,
    S_CHANGE_HOST = 108,
    S_DIE = 109,
    S_PLAYER_DEAD = 110,
    S_LIFE = 111,
    S_SCORE = 112,
    S_NEW_WAVE = 113,
    S_END_GAME = 114,
    S_LOAD_SPRITES = 115,
    S_GAME_NOT_LAUNCHED = 125
  } RequestFromServer;

#endif /* PROTOCOLEENUM_HH_ */
