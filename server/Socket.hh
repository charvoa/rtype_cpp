//
// Socket.hh for  in /home/jobertomeu/Work/rtype_cpp/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue Nov 17 23:57:49 2015 Joris Bertomeu
// Last update Thu Dec  3 05:30:23 2015 Louis Audibert
//

#ifndef			__SOCKET_HH_
# define		__SOCKET_HH_

# include		<ISocket.hpp>

class			Socket : public ISocket
{
private:
  int			_fd;
  int			_type;
  int			_domain;
  int			_protocol;
  int			_port;
  int			_sockType;
  struct sockaddr_in	_servAddr;

public:
  Socket(int type_, int domain_, int port_);
  Socket(int fd_, ISocket *);
  virtual		~Socket();
  virtual int		getPort() const;
  virtual int		getFd() const;
  virtual int		getType() const;
  virtual int		getDomain() const;
  virtual int		getProtocol() const;
  virtual void		*read();
  virtual void		close();
  virtual int		write(void *);
  virtual struct sockaddr_in	*getAddr();
};

#endif
