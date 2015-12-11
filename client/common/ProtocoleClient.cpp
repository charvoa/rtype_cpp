//
// ProtocoleClient.cpp for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Tue Dec  8 06:44:52 2015 Serge Heitzler
// Last update Fri Dec 11 17:26:18 2015 Nicolas Girardot
//


#include <string>
#include <sstream>
#include <vector>
#include <ProtocoleClient.hh>
#include <StartPanel.hh>
#include <RoomPanel.hh>
#include <GamePanel.hh>
#include <Client.hh>
#include <CRC.hpp>
#include <CreateRequest.hpp>

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
  _functions.insert(std::make_pair(S_INIT_UDP, &ProtocoleClient::initUDP));
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

void		ProtocoleClient::initUDP(ANetwork::t_frame &frame)
{
  std::cout << "Creating UDP" << std::endl;
  std::vector<std::string> x = split(frame.data, ';');
  ANetwork *net = Client::getUDPNetwork();
  std::cout << x.at(0) << " :::::::: " << x.at(1) << std::endl;
  try
    {
      net->init(std::atoi(x.at(0).c_str()), ANetwork::UDP_MODE);
      net->connect("10.16.252.249");
    }
  catch (const std::exception &e)
    {
      std::cout << e.what() << std::endl;
    }
  ANetwork::t_frame sender = CreateRequest::create((unsigned char)C_HANDSHAKE_UDP, CRC::calcCRC(x.at(1)), 0, x.at(1));
  std::cout << " WRITE IS SENDING ::: " << net->write(sender) << std::endl;
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
  std::cout << "Create room" << std::endl;
  StartPanel::goToRoom(x, 0);
}

void		ProtocoleClient::createRoomError(ANetwork::t_frame &frame)
{
  std::vector<std::string> x = split(frame.data, ';');
  std::cout << "Create room Error" << std::endl;
  (void) x;
}

void		ProtocoleClient::joinSuccess(ANetwork::t_frame &frame)
{
  std::vector<std::string> x = split(frame.data, ';');
  std::cout << "Join Success" << std::endl;
  StartPanel::goToRoom(x, 1);
}

void		ProtocoleClient::joinError(ANetwork::t_frame &frame)
{
  std::vector<std::string> x = split(frame.data, ';');
  std::cout << "Join Error" << std::endl;
}

void		ProtocoleClient::gameLaunched(ANetwork::t_frame &frame)
{
  std::cout << "Game Is launched" << std::endl;
  (void) frame;
}

void		ProtocoleClient::newPlayerConnected(ANetwork::t_frame &frame)
{
  std::vector<std::string> x = split(frame.data, ';');
  std::cout << "New Player Connected" << std::endl;
  RoomPanel::newPlayer(x.at(0));
}

void		ProtocoleClient::playerLeft(ANetwork::t_frame &frame)
{
  std::vector<std::string> x = split(frame.data, ';');
  RoomPanel::playerLeft(x);
}

void		ProtocoleClient::changeHost(ANetwork::t_frame &frame)
{
  (void) frame;
}

void		ProtocoleClient::die(ANetwork::t_frame &frame)
{
  std::vector<std::string> x = split(frame.data, ';');
  std::cout << "die" << std::endl;
  (void) x;
}

void		ProtocoleClient::playerDead(ANetwork::t_frame &frame)
{
  (void) frame;
}

void		ProtocoleClient::life(ANetwork::t_frame &frame)
{
  std::vector<std::string> x = split(frame.data, ';');
  std::cout << "life" << std::endl;
  GamePanel::setLife(x.at(0), std::atoi(x.at(1).c_str()));
}

void		ProtocoleClient::score(ANetwork::t_frame &frame)
{
  std::vector<std::string> x = split(frame.data, ';');
  std::cout << "Score" << std::endl;
  GamePanel::setScore(std::atoi(x.at(1).c_str()));
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
  for (PointersOnFuncs::iterator it = _functions.begin(); it != _functions.end(); ++it)
    {
      if ((*it).first == frame.idRequest)
	(*this.*_functions[static_cast<RequestFromServer>(frame.idRequest)])(frame);
    }
}
