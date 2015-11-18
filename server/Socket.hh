//
// Socket.hh for  in /home/jobertomeu/Work/rtype_cpp/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue Nov 17 23:57:49 2015 Joris Bertomeu
// Last update Wed Nov 18 01:27:40 2015 Joris Bertomeu
//

#ifndef		__SOCKET_HH_
# define	__SOCKET_HH_

# include	"ISocket.hpp"

class		Socket : public ISocket
{
private:
  int		_fd;
  int		_type;
  int		_domain;
  int		_protocol;
  int		_port;
  int		_sockType;

public:
  explicit	Socket(int type_, int domain_, int port_);
  virtual	~Socket();
  int		getFd() const;
  int		getType() const;
  int		getDomain() const;
  int		getProtocol() const;
  virtual void	*read();
  virtual int	write(void *);
};

#endif
