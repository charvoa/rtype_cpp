//
// Network.hh for  in /home/jobertomeu/Work/rtype_cpp/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Wed Nov 18 00:21:04 2015 Joris Bertomeu
// Last update Wed Nov 18 16:53:58 2015 Joris Bertomeu
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
  virtual void	*read(int);
  virtual int	write(void *, int);
  virtual void	close();
  virtual void	accept(ISocket *);
};

#endif
