//
// Protocole.hh for rtype in /home/sergeheitzler/rendu/rtype_cpp/client/common
// 
// Made by Serge Heitzler
// Login   <sergeheitzler@epitech.net>
// 
// Started on  Mon Nov 30 08:38:18 2015 Serge Heitzler
// Last update Tue Dec  1 11:22:14 2015 Serge Heitzler
//

#ifndef PROTOCOLECLIENT_HH_
#define PROTOCOLECLIENT_HH_

class	        ProtocoleClient
{

  ProtocoleClient();
  ~ProtocoleClient();

  void			initProtocoleClient();
  
private:

  typedef std::map<RequestFromServer, funcs>PointersOnFuncs;
  typedef void(ProtocoleClient::*funcs)(t_frame &frame);
  funcs				_ptr;
  PointersOnFuncs	        _functions;

};

#endif /* !PROTOCOLECLIENT_HH_ */
