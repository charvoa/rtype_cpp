//
// Socket.hpp for  in /home/jobertomeu/Work/net
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Sat Dec  5 11:18:33 2015 Joris Bertomeu
// Last update Sun Dec  6 08:45:26 2015 Antoine Garcia
//

#ifndef		__SOCKET__HPP_
# define	__SOCKET__HPP_

# include	<sys/types.h>
# include	<unistd.h>
# include	<sys/socket.h>
# include	<netinet/in.h>
# include	<stdexcept>
# include	<string.h>
# include	<errno.h>
#include	<netdb.h>
# include	<ISocket.hpp>
# include	<arpa/inet.h>

class		Socket : public ISocket
{
 private:
  int		_fd;
  int		_mode;
  struct sockaddr_in _me;
  
 public:
  Socket(int domain, int type, int protocol) {
    this->_fd = socket(domain, type, protocol);
    if (this->_fd < 0)
      throw (std::logic_error("Socket :: Creating Error"));
    this->_mode = type;
  };

  Socket(int fd) {
    this->_fd = fd;
    this->_mode = SOCK_STREAM;
  };

  Socket(int fd, int mode) {
    this->_fd = fd;
    this->_mode = mode;
  }
  
  virtual	~Socket() {

  };

  void		*read(int size) {
    if (this->_mode == SOCK_STREAM)
      return (this->read_tcp(size));
    else
      return (this->read_udp(size));
  };

  int		write(void *data, int size) {
    if (this->_mode == SOCK_STREAM)
      return (this->write_tcp(data, size));
    else
      return (this->write_udp(data, size));
  };

  void		close() {
    ::close(this->_fd);
  };

  int		getFd() const {
    return (this->_fd);
  };

private:
  void		*read_tcp(int size) {
    void	*data;

    data = malloc(size + 1);
    bzero(data, size + 1);
    ::read(this->_fd, data, size);
    return (data);
  };

  void		*read_udp(int size) {
    void	*data;
    socklen_t	meSize = sizeof(this->_me);
    
    data = malloc(size + 1);
    bzero(data, size + 1);
    ::recvfrom(this->_fd, data, size, 0, (struct sockaddr*) &_me, &meSize);
    return (data);
  };

  int		write_tcp(void *data, int size) {
    return (::write(this->_fd, data, size));
  };

  int		write_udp(void *data, int size) {
    return (0);
  };
};

#endif
