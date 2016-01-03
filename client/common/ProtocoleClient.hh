//
// Protocole.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
//
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
//
// Started on  Mon Nov 30 08:38:18 2015 Serge Heitzler
// Last update Sat Jan  2 19:24:54 2016 Nicolas Girardot
//

#ifndef PROTOCOLECLIENT_HH_
#define PROTOCOLECLIENT_HH_

#include <iostream>
#include <map>
#include <ANetwork.hpp>
#include <ProtocoleEnum.hh>

class			ProtocoleClient
{
public:
  ProtocoleClient();
  ~ProtocoleClient();

  void			initProtocoleClient();
  void			initUDP(ANetwork::t_frame &frame);
  void			handshake(ANetwork::t_frame &frame);
  void			display(ANetwork::t_frame &frame);
  void			createRoom(ANetwork::t_frame &frame);
  void			joinSuccess(ANetwork::t_frame &frame);
  void			joinError(ANetwork::t_frame &frame);
  void		       	newPlayerConnected(ANetwork::t_frame &frame);
  void			playerLeft(ANetwork::t_frame &frame);
  void			die(ANetwork::t_frame &frame);
  void			newEnemy(ANetwork::t_frame &frame);
  void			life(ANetwork::t_frame &frame);
  void	       		score(ANetwork::t_frame &frame);
  void			newWave(ANetwork::t_frame &frame);
  void			endGame(ANetwork::t_frame &frame);
  void			methodChecker(ANetwork::t_frame &frame);
  void			createRoomSuccess(ANetwork::t_frame &frame);
  void			fileTotalSize(ANetwork::t_frame &frame);
  void			shoot(ANetwork::t_frame &frame);
  void			newEntity(ANetwork::t_frame &frame);
  void			deleteEntity(ANetwork::t_frame &frame);
  void			playerLeftIG(ANetwork::t_frame &frame);
  void			downloadComplete(ANetwork::t_frame &frame);
  void		        ammoLeft(ANetwork::t_frame &frame);
  void		        hit(ANetwork::t_frame &frame);
  void			setSlider(ANetwork::t_frame &frame);

private:


  typedef void(ProtocoleClient::*funcs)(ANetwork::t_frame &frame);
  funcs				_ptr;
  typedef std::map<RequestFromServer, funcs>PointersOnFuncs;
  PointersOnFuncs	        _functions;

};

#endif /* !PROTOCOLECLIENT_HH_ */
