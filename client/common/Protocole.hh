//
// Protocole.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Mon Nov 30 08:38:18 2015 Serge Heitzler
// Last update Tue Dec  1 02:57:20 2015 Serge Heitzler
//

#ifndef PROTOCOLE_HH_
#define PROTOCOLE_HH_

class	        Protocole
{

  typedef enum Received
    {
      DISPLAY = 100,
      CREATE_ROOM = 101,
      JOIN_SUCCESS = 102,
      JOIN_ERROR = 103,
      GAME_LAUNCHED = 104,
      NEW_PLAYER_CONNECTED = 105,
      PLAYER_LEFT = 106,
      CHANGE_HOST = 107,
      DIE = 108,
      PLAYER_DEAD = 109,
      LIFE = 110,
      SCORE = 111,
      NEW_WAVE = 112,
      END_GAME = 113,
      LOAD_SPRITES = 114,
    }	        Received;

  Protocole();
  ~Protocole();

private:

  typedef std::map<Protocole::Received, funcs>PointersOnFuncs;
  typedef void(Protocole::*funcs)();
  funcs				_ptr;
  PointersOnFuncs	        _functions;

};

#endif /* !PROTOCOLE_HH_ */
