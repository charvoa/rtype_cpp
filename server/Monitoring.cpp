//
// Monitoring.cpp for  in /home/jobertomeu/Work/rtype_cpp/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue Dec 15 05:35:57 2015 Joris Bertomeu
// Last update Tue Dec 15 06:01:53 2015 Joris Bertomeu
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
      // int	nbGames = 0;
      // client->getSocket()->write(std::string("Nombre de games :" + std::to_string(nbGames)).c_str(),
      // 				 std::string("Nombre de games :" + std::to_string(nbGames)).size());
    }
  return (NULL);
}
