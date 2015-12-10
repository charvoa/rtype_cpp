//
// ProtocoleEnum.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Tue Dec  1 10:50:13 2015 Serge Heitzler
// Last update Thu Dec 10 20:13:22 2015 Nicolas Charvoz
//

#ifndef PROTOCOLEENUM_HH_
#define PROTOCOLEENUM_HH_

typedef enum E_Command
  {
    S_HANDSHAKE_UDP = 1,
    C_HANDSHAKE = 2,
    C_CREATEROOM = 2,
    C_CHANGE_SETTINGS = 4,
    C_JOINROOM = 5,
    C_PLAYERLEFT = 6,
    C_LAUNCHGAME = 7,
    C_MOVE = 8,
    C_SHOOT = 9,
    C_LOAD_SPRITE_SUCCESS = 10,
    C_LOAD_SPRITE_ERROR = 11,
    C_LOAD_SPRITE_IN_PROGRESS = 12,
    C_SEND_MD5 = 13
  } E_Command;

typedef enum RequestFromServer
  {
    S_HANDSHAKE_UDP = 100,
    S_HANDSHAKE = 101,
    S_DISPLAY = 102,
    S_CREATE_ROOM = 103,
    S_CREATE_ROOM_ERROR = 104,
    S_JOIN_SUCCESS = 105,
    S_JOIN_ERROR = 106,
    S_GAME_LAUNCHED = 107,
    S_GAME_NOT_LAUNCHED = 108,
    S_NEW_PLAYER_CONNECTED = 109,
    S_PLAYER_LEFT = 110,
    S_CHANGE_HOST = 111,
    S_DIE = 112,
    S_PLAYER_DEAD = 113,
    S_LIFE = 114,
    S_SCORE = 115,
    S_NEW_WAVE = 116,
    S_END_GAME = 117,
    S_LOAD_SPRITES = 118,
    S_CHECK_MD5 = 119,
    S_FILE_TOTAL_SIZE = 120
  } RequestFromServer;

#endif /* PROTOCOLEENUM_HH_ */
