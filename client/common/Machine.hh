//
// Machine.hh for Machine in /home/barnea_v/rendu/rtype_cpp/client/common
// 
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
// 
// Started on  Tue Dec  1 11:18:18 2015 Viveka BARNEAUD
// Last update Tue Dec  1 11:23:59 2015 Viveka BARNEAUD
//

#ifndef		MACHINE_HH_
# define	MACHINE_HH_

typedef enum	e_state
  {
    START,
    PLAY,
    DEMO,
    SETTINGS,
    ROOM,
    GAME,
    LOADING,
    STATE_ERROR
  } eState;

typedef enum	e_action
  {
    MA,
    HR,
    ACTION_ERROR
  } eAction;

extern const eState		gStateTable[STATE_MAX][EDGE_MAX];
extern const eAction		gActionTable[STATE_MAX][EDGE_MAX];

#endif		/* MACHINE_HH_ */
