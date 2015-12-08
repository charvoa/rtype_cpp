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

 public:
  Socket(int domain, int type, int protocol) {
	WSAStartup(MAKEWORD(2, 0), &_WSAData);
	this->_fd = socket(domain, type, protocol);
    if (this->_fd < 0)
      throw (std::logic_error("Socket :: Creating Error"));
  };

  Socket(SOCKET fd) {
	  std::cout << "SocketWin :: Created from accept" << std::endl;
    this->_fd = fd;
  };

  virtual	~Socket() {
	  this->close();
  };

  void		*read(int size) {
    void	*data;

    data = malloc(size + 1);
    memset(data, 0, size + 1);
	::recv(this->_fd, (char*) data, size, 0);
	if (!data)
		throw (std::logic_error("Socket :: Read :: Null ptr returned"));
    return (data);
  };

  int		write(void *data, int size) {
	  return (::send(this->_fd, (char*) data, size, 0));
  };

  void		close() {
	  WSACleanup();
    //::close(this->_fd);
  };

  SOCKET		getFd() const {
    return (this->_fd);
  };
};

#endif
