//
// ProtocoleEnum.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Tue Dec  1 10:50:13 2015 Serge Heitzler
// Last update Tue Dec 15 03:20:16 2015 Serge Heitzler
//

#ifndef PROTOCOLEENUM_HH_
#define PROTOCOLEENUM_HH_

typedef enum E_Command
  {
    C_INIT_UDP = 1,
    C_HANDSHAKE_UDP = 2,
    C_HANDSHAKE = 3,
    C_CREATE_ROOM = 4,
    C_CHANGE_SETTINGS = 5,
    C_JOIN_ROOM = 6,
    C_PLAYER_LEFT = 7,
    C_LAUNCH_GAME = 8,
    C_MOVE = 9,
    C_SHOOT = 10,
    C_LOAD_SPRITE_SUCCESS = 11,
    C_LOAD_SPRITE_ERROR = 12,
    C_LOAD_SPRITE_IN_PROGRESS = 13,
  } E_Command;

typedef enum RequestFromServer
  {
    S_INIT_UDP = 100,
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
    S_FILE_TOTAL_SIZE = 119,
    S_NEW_ENTITY = 120,
    S_SHOOT = 121
  } RequestFromServer;

#endif /* PROTOCOLEENUM_HH_ */
