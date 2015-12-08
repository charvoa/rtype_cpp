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

# include	<stdexcept>
# include	<string.h>
# include	<errno.h>
# include	<winsock2.h>
# include	<ISocket.hpp>
# include	<iostream>
# pragma comment(lib, "ws2_32.lib")

class		Socket : public ISocket
{
 private:
  SOCKET		_fd;
  WSADATA		_WSAData;
  SOCKADDR_IN	_me;
  int			_mode;
  bool			_init;

 public:
  Socket(int domain, int type, int protocol) {
	WSAStartup(MAKEWORD(2, 0), &_WSAData);
	this->_fd = socket(domain, type, protocol);
    if (this->_fd < 0)
      throw (std::logic_error("Socket :: Creating Error"));
	this->_mode = type;
	this->_init = false;
  };

  Socket(SOCKET fd) {
	  std::cout << "SocketWin :: Created from accept" << std::endl;
	  this->_fd = fd;
	  this->_mode = SOCK_STREAM;
	  this->_init = false;
  };

  Socket(SOCKET fd, int mode) {
	  this->_fd = fd;
	  this->_mode = mode;
	  this->_init = false;
  }

  virtual	~Socket() {
	  this->close();
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
	  WSACleanup();
    //::close(this->_fd);
  };

  SOCKET		getFd() const {
    return (this->_fd);
  };

  virtual void		setForUDP(SOCKADDR_IN *s) {
	  this->_me = *s;
  };

private:
	void		*read_tcp(int size) {
		void	*data;

		data = malloc(size + 1);
		memset(data, 0, size + 1);
		::recv(this->_fd, (char*)data, size, 0);
		if (!data)
			throw (std::logic_error("Socket :: Read :: Null ptr returned"));
		return (data);
	};

	void		*read_udp(int size) {
		void	*data;
		int		meSize = sizeof(SOCKADDR_IN);

		data = malloc(size + 1);
		memset(data, 0, size + 1);
		::recvfrom(this->_fd, (char*) data, size, 0, (SOCKADDR*) &_me, &meSize);
		if (&(this->_me) != NULL)
			this->_init = true;
		return (data);
	};

	int		write_tcp(void *data, int size) {
		return (::send(this->_fd, (char*)data, size, 0));
	};

	int		write_udp(void *data, int size) {
		int	meSize = sizeof(SOCKADDR_IN);
		int		ret;

		if (!this->_init)
			throw(std::logic_error("Socket :: UDP :: Write :: Write before send not allowed for UDP Mode"));
		ret = ::sendto(this->_fd, (char*) data, size, 0, (SOCKADDR*) &_me, meSize);
		if (ret < 0)
			throw (std::logic_error("Socket :: UDP :: Write :: Error while writing"));
		return (ret);
	};
};

#endif
