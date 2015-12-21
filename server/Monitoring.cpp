//
// Monitoring.cpp for  in /home/jobertomeu/Work/rtype_cpp/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue Dec 15 05:35:57 2015 Joris Bertomeu
// Last update Tue Dec 15 08:55:11 2015 Joris Bertomeu
//

#include		<Monitoring.hpp>
#include		<Server.hh>

void			*_handleThread(void *ptr) {
  Monitoring		*me = reinterpret_cast<Monitoring*>(ptr);
  Client		*client;
  Server		*server = reinterpret_cast<Server*>(me->_server);
  void			*data;

  std::cout << "Monitoring :: Thread starting" << std::endl;
  try {
    me->_network.init(9999, ANetwork::TCP_MODE);
    me->_network.bind();
    me->_network.listen(24);
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  while (1)
    {
      client = new Client(me->_network.select());
      if (!(data = client->getSocket()->read(sizeof(ANetwork::t_frame)))) {
	me->_network.unlistenSocket(client->getSocket());
	continue;
      }
      me->parseCommand(data, (void*) client);
    }
  return (NULL);
}

void			Monitoring::parseCommand(void *data, void *c)
{
  Client		*client = reinterpret_cast<Client*>(c);
  ANetwork::t_frame	*frame = reinterpret_cast<ANetwork::t_frame*>(data);

  if (frame->idRequest == M_LIST_GAMES) {
    int	nbGames = reinterpret_cast<Server*>(this->_server)->_gameManager.getNbGames();
    std::list<Game>	games = reinterpret_cast<Server*>(this->_server)->_gameManager.getGames();
    std::string		inter = "[";

    //response = std::string("{\"result\":") + std::to_string(nbGames) + std::string("}");
    for (std::list<Game>::iterator it = games.begin(); it != games.end() ; ++it)
      {
	inter += "{\"id\":\"" + (*it).getId() + "\", \"time\":" + std::to_string((*it).getTimestamp()) +
	  ", \"nbPlayers\":" + std::to_string((*it).getPlayers().size()) + "},";
      }
    inter.pop_back();
    inter += "]";
    client->getSocket()->write(CreateRequest::create(1, 2, 3, inter, true), sizeof(ANetwork::t_frame));
  } else if (frame->idRequest == M_GET_GAME_INFO) {

  } else {
    client->getSocket()->write(CreateRequest::create(1, 2, 3, "\"Bad command number\"", true), sizeof(ANetwork::t_frame));
    std::cout << "\"Monitoring :: ParseCommand :: Bad command number\"" << std::endl;
  }
}
