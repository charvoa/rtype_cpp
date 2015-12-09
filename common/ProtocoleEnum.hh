//
// ProtocoleEnum.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Tue Dec  1 10:50:13 2015 Serge Heitzler
// Last update Wed Dec  9 16:16:48 2015 Nicolas Girardot
//

#ifndef PROTOCOLEENUM_HH_
#define PROTOCOLEENUM_HH_

typedef enum E_Command
  {
    C_CREATEROOM = 1,
    C_CHANGE_SETTINGS = 2,
    C_JOINROOM = 3,
    C_PLAYERLEFT = 4,
    C_LAUNCHGAME = 5,
    C_MOVE = 6,
    C_SHOOT = 7,
    C_LOAD_SPRITE_SUCCESS = 8,
    C_LOAD_SPRITE_ERROR = 9,
    C_LOAD_SPRITE_IN_PROGRESS = 10,
    C_SEND_MD5 = 11
  } E_Command;

typedef enum RequestFromServer
  {
    S_DISPLAY = 100,
    S_CREATE_ROOM = 101,
    S_CREATE_ROOM_ERROR = 102,
    S_JOIN_SUCCESS = 103,
    S_JOIN_ERROR = 104,
    S_GAME_LAUNCHED = 105,
    S_GAME_NOT_LAUNCHED = 106,
    S_NEW_PLAYER_CONNECTED = 107,
    S_PLAYER_LEFT = 108,
    S_CHANGE_HOST = 109,
    S_DIE = 110,
    S_PLAYER_DEAD = 111,
    S_LIFE = 112,
    S_SCORE = 113,
    S_NEW_WAVE = 114,
    S_END_GAME = 115,
    S_LOAD_SPRITES = 116,
    S_CHECK_MD5 = 117,
    S_FILE_TOTAL_SIZE = 118
  } RequestFromServer;

#endif /* PROTOCOLEENUM_HH_ */
