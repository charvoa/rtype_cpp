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

 public:
  Socket(int domain, int type, int protocol) {
    this->_fd = socket(domain, type, protocol);
    if (this->_fd < 0)
      throw (std::logic_error("Socket :: Creating Error"));
  };

  Socket(int fd) {
    this->_fd = fd;
  };

  virtual	~Socket() {

  };

  void		*read(int size) {
    void	*data;

    data = malloc(size + 1);
    bzero(data, size + 1);
    ::read(this->_fd, data, size);
    return (data);
  };

  int		write(void *data, int size) {
    return (::write(this->_fd, data, size));
  };

  void		close() {
    ::close(this->_fd);
  };

  int		getFd() const {
    return (this->_fd);
  };
};

#endif
