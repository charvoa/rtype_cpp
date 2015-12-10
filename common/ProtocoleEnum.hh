//
// ProtocoleEnum.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Tue Dec  1 10:50:13 2015 Serge Heitzler
// Last update Thu Dec 10 17:06:33 2015 Nicolas Girardot
//

#ifndef PROTOCOLEENUM_HH_
#define PROTOCOLEENUM_HH_

typedef enum E_Command
  {
    C_HANDSHAKE = 1,
    C_CREATEROOM = 2,
    C_CHANGE_SETTINGS = 3,
    C_JOINROOM = 4,
    C_PLAYERLEFT = 5,
    C_LAUNCHGAME = 6,
    C_MOVE = 7,
    C_SHOOT = 8,
    C_LOAD_SPRITE_SUCCESS = 9,
    C_LOAD_SPRITE_ERROR = 10,
    C_LOAD_SPRITE_IN_PROGRESS = 11,
    C_SEND_MD5 = 12
  } E_Command;

typedef enum RequestFromServer
  {
    S_HANDSHAKE = 100,
    S_DISPLAY = 101,
    S_CREATE_ROOM = 102,
    S_CREATE_ROOM_ERROR = 103,
    S_JOIN_SUCCESS = 104,
    S_JOIN_ERROR = 105,
    S_GAME_LAUNCHED = 106,
    S_GAME_NOT_LAUNCHED = 107,
    S_NEW_PLAYER_CONNECTED = 108,
    S_PLAYER_LEFT = 109,
    S_CHANGE_HOST = 110,
    S_DIE = 111,
    S_PLAYER_DEAD = 112,
    S_LIFE = 113,
    S_SCORE = 114,
    S_NEW_WAVE = 115,
    S_END_GAME = 116,
    S_LOAD_SPRITES = 117,
    S_CHECK_MD5 = 118,
    S_FILE_TOTAL_SIZE = 119
  } RequestFromServer;

#endif /* PROTOCOLEENUM_HH_ */
