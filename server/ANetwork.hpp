//
// ANetwork.hh for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Nov 25 16:38:49 2015 Nicolas Charvoz
// Last update Wed Nov 18 02:44:57 2015 Joris Bertomeu
//

#ifndef		ANETWORK_HPP_
# define	ANETWORK_HPP_

# include	<string>
# include	"ISocket.hpp"

class		ANetwork
{
protected:
  ISocket	*_socket;

public:
  ANetwork() {};
  virtual	~ANetwork() {};
  virtual void	create(int port_, int sockType_, const std::string &addr_) = 0;
  virtual void	bind() = 0;
  virtual void	listen() = 0;
  virtual void	*read() = 0;
  virtual int	write(void *) = 0;
  virtual void	close() = 0;
  virtual void	accept(ISocket *) = 0;
};

#endif
