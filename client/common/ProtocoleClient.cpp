//
// ProtocoleClient.cpp for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Tue Dec  8 06:44:52 2015 Serge Heitzler
// Last update Thu Dec 10 17:05:53 2015 Nicolas Girardot
//


#include <string>
#include <sstream>
#include <vector>
#include <ProtocoleClient.hh>
#include <StartPanel.hh>
#include <RoomPanel.hh>

std::string	g_a = "JVYO";

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
  _functions.insert(std::make_pair(S_HANDSHAKE, &ProtocoleClient::handshake));
  _functions.insert(std::make_pair(S_DISPLAY, &ProtocoleClient::display));
  _functions.insert(std::make_pair(S_CREATE_ROOM, &ProtocoleClient::createRoom));
  _functions.insert(std::make_pair(S_CREATE_ROOM_ERROR, &ProtocoleClient::createRoomError));
  _functions.insert(std::make_pair(S_JOIN_SUCCESS, &ProtocoleClient::joinSuccess));
  _functions.insert(std::make_pair(S_JOIN_ERROR, &ProtocoleClient::joinError));
  _functions.insert(std::make_pair(S_GAME_LAUNCHED, &ProtocoleClient::gameLaunched));
  _functions.insert(std::make_pair(S_NEW_PLAYER_CONNECTED, &ProtocoleClient::newPlayerConnected));
  _functions.insert(std::make_pair(S_PLAYER_LEFT, &ProtocoleClient::playerLeft));
  _functions.insert(std::make_pair(S_CHANGE_HOST, &ProtocoleClient::changeHost));
  _functions.insert(std::make_pair(S_DIE, &ProtocoleClient::die));
  _functions.insert(std::make_pair(S_PLAYER_DEAD, &ProtocoleClient::playerDead));
  _functions.insert(std::make_pair(S_LIFE, &ProtocoleClient::life));
  _functions.insert(std::make_pair(S_SCORE, &ProtocoleClient::score));
  _functions.insert(std::make_pair(S_NEW_WAVE, &ProtocoleClient::newWave));
  _functions.insert(std::make_pair(S_END_GAME, &ProtocoleClient::endGame));
  _functions.insert(std::make_pair(S_LOAD_SPRITES, &ProtocoleClient::loadSprites));
  _functions.insert(std::make_pair(S_GAME_NOT_LAUNCHED, &ProtocoleClient::gameNotLaunched));
}

void		ProtocoleClient::handshake(ANetwork::t_frame &frame)
{
  (void) frame;
}

void		ProtocoleClient::display(ANetwork::t_frame &frame)
{
  (void) frame;
}

void		ProtocoleClient::createRoom(ANetwork::t_frame &frame)
{
  std::vector<std::string> x = split(frame.data, ';');
  StartPanel::goToRoom(x, 0);
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
  std::vector<std::string> x = split(frame.data, ';');
  StartPanel::goToRoom(x, 1);
}

void		ProtocoleClient::joinError(ANetwork::t_frame &frame)
{
  (void) frame;
}

void		ProtocoleClient::gameLaunched(ANetwork::t_frame &frame)
{
  std::cout << "Game Is launched" << std::endl;
  (void) frame;
}

void		ProtocoleClient::newPlayerConnected(ANetwork::t_frame &frame)
{
  std::vector<std::string> x = split(frame.data, ';');
  RoomPanel::newPlayer(x.at(0));
}

void		ProtocoleClient::playerLeft(ANetwork::t_frame &frame)
{
  std::cout << "JACQUES" << std::endl;
  std::vector<std::string> x = split(frame.data, ';');
  std::cout << "JACQUES" << std::endl;
  RoomPanel::playerLeft(x);
  std::cout << "JACQUES" << std::endl;
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

void		ProtocoleClient::gameNotLaunched(ANetwork::t_frame &frame)
{
  std::cout << "GAME IS NOT LAUCNEHD" << std::endl;
  (void) frame;
}

void		ProtocoleClient::methodChecker(ANetwork::t_frame &frame)
{
  std::cout << "JACQUES" << std::endl;
  for (PointersOnFuncs::iterator it = _functions.begin(); it != _functions.end(); ++it)
    {
  std::cout << "JACQUES" << std::endl;
      if ((*it).first == frame.idRequest)
	(*this.*_functions[static_cast<RequestFromServer>(frame.idRequest)])(frame);
    }
  std::cout << "JACQUES" << std::endl;
}
