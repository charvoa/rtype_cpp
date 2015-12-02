//
// Protocole.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Mon Nov 30 08:38:18 2015 Serge Heitzler
// Last update Tue Dec  1 11:45:50 2015 Serge Heitzler
//

#ifndef PROTOCOLECLIENT_HH_
#define PROTOCOLECLIENT_HH_

class			ProtocoleClient
{

  ProtocoleClient();
  ~ProtocoleClient();

  void			initProtocoleClient();
  void			display(t_frame &frame);
  void			createRoom(t_frame &frame);
  void			joinSuccess(t_frame &frame);
  void			joinError(t_frame &frame);
  void			gameLaunched(t_frame &frame);
  void		       	newPlayerConnected(t_frame &frame);
  void			playerLeft(t_frame &frame);
  void			changeHost(t_frame &frame);
  void			die(t_frame &frame);
  void			playerDead(t_frame &frame);
  void			life(t_frame &frame);
  void	       		score(t_frame &frame);
  void			newWave(t_frame &frame);
  void			endGame(t_frame &frame);
  void			loadSprites(t_frame &frame);
  void			methodChecker(t_frame &frame);
  
private:

  typedef std::map<RequestFromServer, funcs>PointersOnFuncs;
  typedef void(ProtocoleClient::*funcs)(t_frame &frame);
  funcs				_ptr;
  PointersOnFuncs	        _functions;

};

#endif /* !PROTOCOLECLIENT_HH_ */
