//
// ProtocoleEnum.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Tue Dec  1 10:50:13 2015 Serge Heitzler
// Last update Sat Dec 26 16:47:49 2015 Nicolas Girardot
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
    S_JOIN_SUCCESS = 104,
    S_JOIN_ERROR = 105,
    S_GAME_LAUNCHED = 106,
    S_GAME_NOT_LAUNCHED = 107,
    S_NEW_PLAYER_CONNECTED = 108,
    S_PLAYER_LEFT = 109,
    S_DIE = 110,
    S_LIFE = 111,
    S_SCORE = 112,
    S_SET_CURRENT_WAVE = 113,
    S_END_GAME = 114,
    S_LOAD_SPRITES = 115,
    S_FILE_TOTAL_SIZE = 116,
    S_NEW_ENTITY = 117,
    S_SHOOT = 118,
    S_DOWNLOAD_COMPLETE = 119,
    S_DELETE_ENTITY = 120,
    S_PLAYER_LEFT_IG = 121,
    S_NEW_WAVE = 122,
    S_AMMO_LEFT = 123
  } RequestFromServer;

typedef enum RequestFromMonitoring
  {
    M_LIST_GAMES = 100,
    M_GET_GAME_INFO = 101
  } RequestFromMonitoring;

#endif /* PROTOCOLEENUM_HH_ */
