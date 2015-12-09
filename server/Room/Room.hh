//
// Room.hh for Room in /home/antoinegarcia/rendu/rtype_cpp/server/Room
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Mon Nov 30 08:52:59 2015 Antoine Garcia
// Last update Wed Dec  9 05:47:08 2015 Antoine Garcia
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
  void	deletePlayer(Client &);
  const std::vector<Client>&	getAllPlayers() const;
  void			setParameters(Parameters &);
  const Parameters&	getParameters() const;
};


#endif
