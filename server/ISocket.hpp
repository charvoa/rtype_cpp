//
// ISocket.hpp for  in /home/jobertomeu/Work/rtype_cpp/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue Nov 17 23:55:57 2015 Joris Bertomeu
// Last update Wed Nov 18 16:54:26 2015 Joris Bertomeu
//

#ifndef		__ISOCKET_HPP_
# define	__ISOCKET_HPP_

# include	<sys/types.h>
# include	<sys/socket.h>
# include	<netinet/in.h>
# include	<stdexcept>

class		ISocket
{
public:
  explicit	ISocket() {};
  virtual	~ISocket() {};
  virtual void	*read() = 0;
  virtual void	close() = 0;
  virtual int	write(void *) = 0;
  virtual int	getFd() const = 0;
  virtual int	getType() const = 0;
  virtual int	getDomain() const = 0;
  virtual int	getProtocol() const = 0;
  virtual struct sockaddr_in	*getAddr() = 0;
};

#endif
