//
// Socket.hpp for  in /home/jobertomeu/Work/net
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Sat Dec  5 11:18:33 2015 Joris Bertomeu
// Last update Sat Dec 12 09:44:48 2015 Joris Bertomeu
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
# include	<netdb.h>
# include	<ISocket.hpp>
# include	<arpa/inet.h>
# include	<iostream>
# include	<stdlib.h>
# include	<ANetwork.hpp>

class		Socket : public ISocket
{
 private:
  int		_fd;
  int		_mode;
  struct sockaddr_in _me;
  bool		_init;

 public:
  Socket(int domain, int type, int protocol) {
    this->_fd = socket(domain, type, protocol);
    if (this->_fd < 0)
      throw (std::logic_error("Socket :: Creating Error"));
    this->_mode = type;
    this->_init = false;
  };

  Socket(int fd) {
    this->_fd = fd;
    this->_mode = SOCK_STREAM;
	this->_init = false;
  };

  Socket(int fd, int mode) {
    this->_fd = fd;
    this->_mode = mode;
    this->_init = false;
  }

  virtual	~Socket() {

  };

  virtual void		setForUDP(struct sockaddr_in *s) {
    this->_init = true;
    this->_me = *s;
  };

  void		*read(int size) {
    int		toto;

    if (this->_mode == SOCK_STREAM)
      return (this->read_tcp(size, &toto));
    else
      return (this->read_udp(size, &toto));
  };

  void		*read(int size, int *fill) {
    if (this->_mode == SOCK_STREAM)
      return (this->read_tcp(size, fill));
    else
      return (this->read_udp(size, fill));
  };

  int		write(void *data, int size) {
    if (!data)
      return (0);
    if (this->_mode == SOCK_STREAM)
      return (this->write_tcp(data, size));
    else
      return (this->write_udp(data, size));
  };

  void		close() {
    ::shutdown(this->_fd, SHUT_RDWR);
    ::close(this->_fd);
  };

  int		getFd() const {
    return (this->_fd);
  };

  bool		isEqualTo(ISocket *s) {
    if (!memcmp(&(this->_me.sin_addr), &(dynamic_cast<Socket*>(s)->_me.sin_addr), sizeof(this->_me.sin_addr)) &&
	this->_me.sin_port == dynamic_cast<Socket*>(s)->_me.sin_port)
      return (true);
    return (false);
  };

private:
  void		*read_tcp(int size, int *fill) {
    void	*data;

    data = malloc(size + 1);
    bzero(data, size + 1);
    if ((*fill = ::read(this->_fd, data, size)) <= 0) {
      this->close();
      return (NULL);
    }
    return (data);
  };

  void		*read_udp(int size, int *fill) {
    void	*data;
    socklen_t	meSize = sizeof(struct sockaddr_in);

    data = malloc(size + 1);
    bzero(data, size + 1);
    *fill = ::recvfrom(this->_fd, data, size, 0, (struct sockaddr*) &_me, &meSize);
    if (&(this->_me) != NULL)
      this->_init = true;
    return (data);
  };

  int		write_tcp(void *data, int size) {
    return (::write(this->_fd, data, size));
  };

  int		write_udp(void *data, int size) {
    socklen_t	meSize = sizeof(struct sockaddr_in);
    int		ret;

    if (!this->_init)
      throw(std::logic_error("Socket :: UDP :: Write :: Write before send not allowed for UDP Mode"));
    ret = ::sendto(this->_fd, data, size, 0, (struct sockaddr*) &_me, meSize);
    if (ret < 0)
      throw (std::logic_error("Socket :: UDP :: Write :: Error while writing"));
    printf("-- Sent DATA UDP : %s --\n", ((ANetwork::t_frame*) data)->data);
    return (ret);
  };
};

#endif
