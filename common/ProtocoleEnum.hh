//
// ProtocoleEnum.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Tue Dec  1 10:50:13 2015 Serge Heitzler
// Last update Tue Dec  8 11:05:01 2015 Nicolas Girardot
//

#ifndef PROTOCOLEENUM_HH_
#define PROTOCOLEENUM_HH_

typedef enum RequestFromClient
  {

  } RequestFromClient;

typedef enum RequestFromServer
  {
      DISPLAY = 100,
      CREATE_ROOM = 101,
      CREATE_ROOM_ERROR = 102,
      JOIN_SUCCESS = 103,
      JOIN_ERROR = 104,
      GAME_LAUNCHED = 105,
      NEW_PLAYER_CONNECTED = 106,
      PLAYER_LEFT = 107,
      CHANGE_HOST = 108,
      DIE = 109,
      PLAYER_DEAD = 110,
      LIFE = 111,
      SCORE = 112,
      NEW_WAVE = 113,
      END_GAME = 114,
      LOAD_SPRITES = 115
  } RequestFromServer;

#endif /* PROTOCOLEENUM_HH_ */
