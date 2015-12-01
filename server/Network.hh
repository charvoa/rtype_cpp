//
// Network.hh for  in /home/jobertomeu/Work/rtype_cpp/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Wed Nov 18 00:21:04 2015 Joris Bertomeu
// Last update Mon Nov 30 18:19:11 2015 Nicolas Charvoz
//

#ifndef		__NETWORK_HH_
# define	__NETWORK_HH_

# include	<iostream>
# include	"ANetwork.hpp"

class		Network : public ANetwork
{
public:
  Network();
  virtual	~Network();
  virtual void	create(int port_, int sockType_, const std::string &addr_);
  virtual void	bind();
  virtual void	listen();
  virtual void	*read();
  virtual int	write(void *);
  virtual void	close();
  virtual void	accept(ISocket *);
};

#endif
