//
// Machine.cpp for Machine in /home/barnea_v/rendu/rtype_cpp/client/common
// 
// Made by Viveka BARNEAUD
// Login   <barnea_v@epitech.net>
// 
// Started on  Tue Dec  1 11:16:47 2015 Viveka BARNEAUD
// Last update Tue Dec  1 11:28:16 2015 Viveka BARNEAUD
//

#include	"Machine.hpp"

const eState	gStateTable[STATE_MAX][EDGE_MAX] =
{
	{STATE_ERROR, STATE_ERROR, STATE_ERROR, STATE_ERROR, STATE_ERROR, STATE_ERROR, STATE_ERROR, STATE_ERROR}
};

const eAction	gActionTable[STATE_MAX][EDGE_MAX] =
{
	{HR, HR, HR, HR, HR, HR, HR, HR}
};
