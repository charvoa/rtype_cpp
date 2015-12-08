//
// Room.hh for Room in /home/antoinegarcia/rendu/rtype_cpp/server/Room
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Mon Nov 30 08:52:59 2015 Antoine Garcia
// Last update Tue Dec  8 02:57:25 2015 Antoine Garcia
//

#ifndef _ROOM_HH_
# define _ROOM_HH_

# include <string>
# include <Client.hh>
# include <ClientManager.hh>
# include <Parameters.hh>
# include <ANetwork.hpp>
# include <CRC.hpp>
# include <CreateRequest.hpp>

class	Room
{
  std::string	_id;
  ClientManager	_clientManager;
  Parameters	_parameter;
  Client	_owner;
  void		sendPlayerJoin(Client &);
  void		sendRoomPlayerJoin(Client &);
  void		sendError(Client &);
public:
  Room();
  Room(const std::string &id, Client&);
  ~Room();
  const std::string&	getId() const;
  void	addPlayer(Client &);
  std::vector<Client>&	getAllPlayers();
  void			setParameters(Parameters &);
  const Parameters&	getParameters() const;
};


#endif
