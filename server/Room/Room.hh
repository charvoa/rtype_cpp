//
// Room.hh for Room in /home/antoinegarcia/rendu/rtype_cpp/server/Room
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Mon Nov 30 08:52:59 2015 Antoine Garcia
// Last update Wed Dec 23 01:06:20 2015 Joris Bertomeu
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
# include <BotManager.hpp>

class	Room
{
  std::list<std::string>	_transfertFinished;
  std::list<Bot*> _botList;
  std::string	_id;
  ClientManager	*_clientManager;
  Parameters	*_parameter;
  Client	_owner;
  void		sendPlayerJoin(Client *);
  void		sendRoomPlayerJoin(Client *);
  void		sendError(Client *);
  void		sendPlayerLeft(int playerID);
public:
  Room();
  Room(const std::string &id, Client *, std::list<Bot*>);
  ~Room();
  const std::string&	getId() const;
  void	addPlayer(Client *);
  void	deletePlayer(Client *);
  std::list<Client*>&	getAllPlayers();
  void			setParameters(Parameters &);
  Parameters*		getParameters();
  void			sendFileToClient(Client *client, std::list<Bot*> list);
};


#endif
