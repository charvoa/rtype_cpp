//
// ProtocoleClient.cpp for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Tue Dec  8 06:44:52 2015 Serge Heitzler
// Last update Sat Jan  2 19:27:25 2016 Nicolas Girardot
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
#include <JoinPanel.hh>

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
  _functions.insert(std::make_pair(S_JOIN_SUCCESS, &ProtocoleClient::joinSuccess));
  _functions.insert(std::make_pair(S_JOIN_ERROR, &ProtocoleClient::joinError));
  _functions.insert(std::make_pair(S_NEW_PLAYER_CONNECTED, &ProtocoleClient::newPlayerConnected));
  _functions.insert(std::make_pair(S_PLAYER_LEFT, &ProtocoleClient::playerLeft));
  _functions.insert(std::make_pair(S_DIE, &ProtocoleClient::die));
  _functions.insert(std::make_pair(S_LIFE, &ProtocoleClient::life));
  _functions.insert(std::make_pair(S_SCORE, &ProtocoleClient::score));
  _functions.insert(std::make_pair(S_NEW_WAVE, &ProtocoleClient::newWave));
  _functions.insert(std::make_pair(S_END_GAME, &ProtocoleClient::endGame));
  _functions.insert(std::make_pair(S_FILE_TOTAL_SIZE, &ProtocoleClient::fileTotalSize));
  _functions.insert(std::make_pair(S_SHOOT, &ProtocoleClient::shoot));
  _functions.insert(std::make_pair(S_NEW_ENTITY, &ProtocoleClient::newEntity));
  _functions.insert(std::make_pair(S_DELETE_ENTITY, &ProtocoleClient::deleteEntity));
  _functions.insert(std::make_pair(S_DOWNLOAD_COMPLETE, &ProtocoleClient::downloadComplete));
  _functions.insert(std::make_pair(S_PLAYER_LEFT_IG, &ProtocoleClient::playerLeftIG));
  _functions.insert(std::make_pair(S_AMMO_LEFT, &ProtocoleClient::ammoLeft));
  _functions.insert(std::make_pair(S_HIT, &ProtocoleClient::hit));
  _functions.insert(std::make_pair(S_ROOM_SETTINGS_CHANGED, &ProtocoleClient::setSlider));
}

void		ProtocoleClient::setSlider(ANetwork::t_frame &frame)
{
  std::vector<std::string> x = split(frame.data, ';');
  RoomPanel::setSlider(std::atoi(x.at(0).c_str()));
}

void		ProtocoleClient::ammoLeft(ANetwork::t_frame &frame)
{
  std::vector<std::string> x = split(frame.data, ';');
  GamePanel::ammoLeft(x);
}

void		ProtocoleClient::hit(ANetwork::t_frame &frame)
{
  std::vector<std::string> x = split(frame.data, ';');
  GamePanel::hit(std::atoi(x.at(0).c_str()), std::atoi(x.at(1).c_str()));
}

void		ProtocoleClient::newWave(ANetwork::t_frame &frame)
{
  std::vector<std::string> x = split(frame.data, ';');
}

void		ProtocoleClient::newEntity(ANetwork::t_frame &frame)
{
  std::vector<std::string> x = split(frame.data, ';');
  GamePanel::newEntity(x);
}

void		ProtocoleClient::playerLeftIG(ANetwork::t_frame &frame)
{
  std::vector<std::string> x = split(frame.data, ';');
  GamePanel::playerLeft(x.at(0));
}

void		ProtocoleClient::deleteEntity(ANetwork::t_frame &frame)
{
  std::vector<std::string> x = split(frame.data, ';');
  GamePanel::deleteEntity(x);
}

void		ProtocoleClient::downloadComplete(ANetwork::t_frame &frame)
{
  std::vector<std::string> x = split(frame.data, ';');
  RoomPanel::downloadComplete(x.at(0));
}

void		ProtocoleClient::fileTotalSize(ANetwork::t_frame &frame)
{
  std::vector<std::string> x = split(frame.data, ';');
  RoomPanel::receiveFiles(std::atoi(x.at(0).c_str()), std::atoi(x.at(1).c_str()));
}

void		ProtocoleClient::initUDP(ANetwork::t_frame &frame)
{
  std::vector<std::string> x = split(frame.data, ';');
  ANetwork *net = Client::getUDPNetwork();
  try
    {
      net->init(std::atoi(x.at(0).c_str()), ANetwork::UDP_MODE);
      net->connect(RenderWindow::getInstance()->getSettings()->getIP());
    }
  catch (const std::exception &e)
    {
      std::cout << e.what() << std::endl;
    }
  ANetwork::t_frame sender = CreateRequest::create((unsigned char)C_HANDSHAKE_UDP, CRC::calcCRC(x.at(1)), x.at(1).size(), x.at(1));
  net->write(sender);
  RenderWindow *window = RenderWindow::getInstance();
  window->getPanels().push(static_cast<GamePanel*>(PanelFactory::createPanel(PanelFactory::PanelType::GAME_PANEL)));
}

void		ProtocoleClient::handshake(ANetwork::t_frame &frame)
{
  (void) frame;
}

void		ProtocoleClient::display(ANetwork::t_frame &frame)
{
  std::vector<std::string> x = split(frame.data, ';');
  GamePanel::display(x);
}

void		ProtocoleClient::shoot(ANetwork::t_frame &frame)
{
  std::vector<std::string> x = split(frame.data, ';');
  Sound *s = Client::getSound();
  int	type = std::atoi(x.at(0).c_str());
  if (type == 5)
    s->playMusic("riffle");
  else if (type == 6)
    s->playSound("missile");
  else
    s->playSound("laser");
}

void		ProtocoleClient::createRoom(ANetwork::t_frame &frame)
{
  std::vector<std::string> x = split(frame.data, ';');
  StartPanel::goToRoom(x, 0);
}

void		ProtocoleClient::joinSuccess(ANetwork::t_frame &frame)
{
  std::vector<std::string> x = split(frame.data, ';');
  StartPanel::goToRoom(x, 1);
}

void		ProtocoleClient::joinError(ANetwork::t_frame &frame)
{
  std::vector<std::string> x = split(frame.data, ';');
  JoinPanel::setError(x.at(0));
}

void		ProtocoleClient::newPlayerConnected(ANetwork::t_frame &frame)
{
  std::vector<std::string> x = split(frame.data, ';');
  RoomPanel::newPlayer(x.at(0));
}

void		ProtocoleClient::playerLeft(ANetwork::t_frame &frame)
{
  std::vector<std::string> x = split(frame.data, ';');
  RoomPanel::playerLeft(x);
}

void		ProtocoleClient::die(ANetwork::t_frame &frame)
{
  std::vector<std::string> x = split(frame.data, ';');
  GamePanel::die(std::atoi(x.at(0).c_str()), std::atoi(x.at(1).c_str()));
}

void		ProtocoleClient::life(ANetwork::t_frame &frame)
{
  std::vector<std::string> x = split(frame.data, ';');
  GamePanel::setLife(x.at(0), std::atoi(x.at(1).c_str()));
}

void		ProtocoleClient::score(ANetwork::t_frame &frame)
{
  std::vector<std::string> x = split(frame.data, ';');
  GamePanel::setScore(x.at(0), std::atoi(x.at(1).c_str()));
}

void		ProtocoleClient::endGame(ANetwork::t_frame &frame)
{
  std::vector<std::string> x = split(frame.data, ';');
  GamePanel::endGame(x);
}

void		ProtocoleClient::methodChecker(ANetwork::t_frame &frame)
{
  for (PointersOnFuncs::iterator it = _functions.begin(); it != _functions.end(); ++it)
    {
      if ((*it).first == frame.idRequest)
		(*this.*_functions[static_cast<RequestFromServer>(frame.idRequest)])(frame);
    }
}
