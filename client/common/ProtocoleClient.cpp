//
// Protocole.cpp for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Tue Dec  1 01:23:08 2015 Serge Heitzler
// Last update Tue Dec  1 10:48:45 2015 Serge Heitzler
//

#include "ProtocoleClient.hh"

ProtocoleClient::ProtocoleClient()
{
  this->initProtocoleClient
}

ProtocoleClient::~ProtocoleClient()
{

}

void		ProtocoleClient::initProtocoleClient()
{
  _functions.insert(std::make_pair(DISPLAY, &ProtocolClient::display));
  _functions.insert(std::make_pair(CREATE_ROOM_SUCCESS, &ProtocolClient::createRoomSuccess));
  _functions.insert(std::make_pair(CREATE_ROOM_ERROR, &ProtocolClient::createRoomError));
  _functions.insert(std::make_pair(JOIN_SUCCESS, &ProtocolClient::joinSucces));
  _functions.insert(std::make_pair(JOIN_ERROR, &ProtocolClient::joinError));
  _functions.insert(std::make_pair(GAME_LAUNCHED, &ProtocolClient::gameLaunched));
  _functions.insert(std::make_pair(NEW_PLAYER_CONNECTED, &ProtocolClient::newPlayerConnected));
  _functions.insert(std::make_pair(PLAYER_LEFT, &ProtocolClient::playerLeft));
  _functions.insert(std::make_pair(CHANGE_HOST, &ProtocolClient::changeHost));
  _functions.insert(std::make_pair(DIE, &ProtocolClient::die));
  _functions.insert(std::make_pair(PLAYER_DEAD, &ProtocolClient::playerDead));
  _functions.insert(std::make_pair(LIFE, &ProtocolClient::life));
  _functions.insert(std::make_pair(SCORE, &ProtocolClient::score));
  _functions.insert(std::make_pair(NEW_WAVE, &ProtocolClient::newWave));
  _functions.insert(std::make_pair(END_GAME, &ProtocolClient::endGame));
  _functions.insert(std::make_pair(LOAD_SPRITES, &ProtocolClient::loadSprites));
}

void		ProtocoleClient::display()
{

}

void		ProtocoleClient::createRoom()
{

}

void		ProtocoleClient::joinSuccess()
{

}

void		ProtocoleClient::joinError()
{

}

void		ProtocoleClient::gameLaunched()
{

}

void		ProtocoleClient::newPlayerConnected()
{

}

void		ProtocoleClient::playerLeft()
{

}

void		ProtocoleClient::changeHost()
{

}

void		ProtocoleClient::die()
{

}

void		ProtocoleClient::playerDead()
{

}

void		ProtocoleClient::life()
{

}

void		ProtocoleClient::score()
{

}

void		ProtocoleClient::newWave()
{

}

void		ProtocoleClient::endGame()
{

}

void		ProtocoleClient::loadSprites()
{

}

void		ProtocoleClient::methodChecker(DataFromClient &fromClient)
{
  for (std::map<CommunicationClient, funcs>::iterator it = _functions.begin(); it != _functions.end(); ++it)
    {
      if ((*it).first == fromClient.getType())
	(*this.*_functions[fromClient.getType()])(fromClient);
    }
}
