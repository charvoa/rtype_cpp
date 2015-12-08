//
// ProtocoleClient.cpp for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Tue Dec  8 06:44:52 2015 Serge Heitzler
// Last update Tue Dec  8 16:30:34 2015 Nicolas Girardot
//


#include <string>
#include <sstream>
#include <vector>
#include <ProtocoleClient.hh>
#include <StartPanel.hh>


std::string	g_a = "";

/////Function to split data

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
  std::stringstream ss(s);
  std::string item;
  while (std::getline(ss, item, delim)) {
    elems.push_back(item);
  }
  return elems;
}


std::vector<std::string> split(const std::string &s, char delim) {
  std::vector<std::string> elems;
  split(s, delim, elems);
  return elems;
}

////

ProtocoleClient::ProtocoleClient()
{
  this->initProtocoleClient();
}

ProtocoleClient::~ProtocoleClient()
{

}

void		ProtocoleClient::initProtocoleClient()
{
  _functions.insert(std::make_pair(DISPLAY, &ProtocoleClient::display));
  _functions.insert(std::make_pair(CREATE_ROOM, &ProtocoleClient::createRoom));
  _functions.insert(std::make_pair(CREATE_ROOM_ERROR, &ProtocoleClient::createRoomError));
  _functions.insert(std::make_pair(JOIN_SUCCESS, &ProtocoleClient::joinSuccess));
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

void		ProtocoleClient::display(ANetwork::t_frame &frame)
{
  (void) frame;
}

void		ProtocoleClient::createRoom(ANetwork::t_frame &frame)
{
  (void) frame;
  //std::vector<std::string> x = split(frame.data, ';');
  StartPanel::goToRoom();
}

void		ProtocoleClient::createRoomSuccess(ANetwork::t_frame &frame)
{
  (void) frame;
}

void		ProtocoleClient::createRoomError(ANetwork::t_frame &frame)
{
  (void) frame;
}

void		ProtocoleClient::joinSuccess(ANetwork::t_frame &frame)
{
  (void) frame;
}

void		ProtocoleClient::joinError(ANetwork::t_frame &frame)
{
  (void) frame;
}

void		ProtocoleClient::gameLaunched(ANetwork::t_frame &frame)
{
  (void) frame;
}

void		ProtocoleClient::newPlayerConnected(ANetwork::t_frame &frame)
{
  (void) frame;
}

void		ProtocoleClient::playerLeft(ANetwork::t_frame &frame)
{
  (void) frame;
}

void		ProtocoleClient::changeHost(ANetwork::t_frame &frame)
{
  (void) frame;
}

void		ProtocoleClient::die(ANetwork::t_frame &frame)
{
  (void) frame;
}

void		ProtocoleClient::playerDead(ANetwork::t_frame &frame)
{
  (void) frame;
}

void		ProtocoleClient::life(ANetwork::t_frame &frame)
{
  (void) frame;
}

void		ProtocoleClient::score(ANetwork::t_frame &frame)
{
  (void) frame;
}

void		ProtocoleClient::newWave(ANetwork::t_frame &frame)
{
  (void) frame;
}

void		ProtocoleClient::endGame(ANetwork::t_frame &frame)
{
  (void) frame;
}

void		ProtocoleClient::loadSprites(ANetwork::t_frame &frame)
{
  (void) frame;
}

void		ProtocoleClient::methodChecker(ANetwork::t_frame &frame)
{
  for (PointersOnFuncs::iterator it = _functions.begin(); it != _functions.end(); ++it)
    {
      if ((*it).first == frame.idRequest)
	(*this.*_functions[static_cast<RequestFromServer>(frame.idRequest)])(frame);
    }
}
