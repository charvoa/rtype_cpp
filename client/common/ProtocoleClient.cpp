//
// Protocole.cpp for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Tue Dec  1 01:23:08 2015 Serge Heitzler
// Last update Tue Dec  8 06:40:18 2015 Serge Heitzler
//

#include "ProtocoleClient.hh"

ProtocoleClient::ProtocoleClient()
{
  this->initProtocoleClient;
}

ProtocoleClient::~ProtocoleClient()
{

}

void		ProtocoleClient::initProtocoleClient()
{
  _functions.insert(std::make_pair(DISPLAY, &ProtocoleClient::display));
  _functions.insert(std::make_pair(CREATE_ROOM_SUCCESS, &ProtocoleClient::createRoomSuccess));
  _functions.insert(std::make_pair(CREATE_ROOM_ERROR, &ProtocoleClient::createRoomError));
  _functions.insert(std::make_pair(JOIN_SUCCESS, &ProtocoleClient::joinSucces));
  _functions.insert(std::make_pair(JOIN_ERROR, &ProtocoleClient::joinError));
  _functions.insert(std::make_pair(GAME_LAUNCHED, &ProtocoleClient::gameLaunched));
  _functions.insert(std::make_pair(NEW_PLAYER_CONNECTED, &ProtocoleClient::newPlayerConnected));
  _functions.insert(std::make_pair(PLAYER_LEFT, &ProtocoleClient::playerLeft));
  _functions.insert(std::make_pair(CHANGE_HOST, &ProtocoleClient::changeHost));
  _functions.insert(std::make_pair(DIE, &ProtocoleClient::die));
  _functions.insert(std::make_pair(PLAYER_DEAD, &ProtocoleClient::playerDead));
  _functions.insert(std::make_pair(LIFE, &ProtocoleClient::life));
  _functions.insert(std::make_pair(SCORE, &ProtocoleClient::score));
  _functions.insert(std::make_pair(NEW_WAVE, &ProtocoleClient::newWave));
  _functions.insert(std::make_pair(END_GAME, &ProtocoleClient::endGame));
  _functions.insert(std::make_pair(LOAD_SPRITES, &ProtocoleClient::loadSprites));
}

void		ProtocoleClient::display(t_frame &frame)
{

}

void		ProtocoleClient::createRoom(t_frame &frame)
{

}

void		ProtocoleClient::joinSuccess(t_frame &frame)
{

}

void		ProtocoleClient::joinError(t_frame &frame)
{

}

void		ProtocoleClient::gameLaunched(t_frame &frame)
{

}

void		ProtocoleClient::newPlayerConnected(t_frame &frame)
{

}

void		ProtocoleClient::playerLeft(t_frame &frame)
{

}

void		ProtocoleClient::changeHost(t_frame &frame)
{

}

void		ProtocoleClient::die(t_frame &frame)
{

}

void		ProtocoleClient::playerDead(t_frame &frame)
{

}

void		ProtocoleClient::life(t_frame &frame)
{

}

void		ProtocoleClient::score(t_frame &frame)
{

}

void		ProtocoleClient::newWave(t_frame &frame)
{

}

void		ProtocoleClient::endGame(t_frame &frame)
{

}

void		ProtocoleClient::loadSprites(t_frame &frame)
{

}

void		ProtocoleClient::methodChecker(t_frame &frame)
{
  for (std::map<RequestFromClient, funcs>::iterator it = _functions.begin(); it != _functions.end(); ++it)
    {
      if ((*it).first == frame._idRequest)
	(*this.*_functions[frame._idRequest])(frame);
    }
}
