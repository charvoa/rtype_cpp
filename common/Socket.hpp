//
// Socket.hpp for  in /home/jobertomeu/Work/net
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Sat Dec  5 11:18:33 2015 Joris Bertomeu
// Last update Sat Dec  5 12:18:43 2015 Joris Bertomeu
//

#ifndef		__SOCKET__HPP_
# define	__SOCKET__HPP_

# include	<stdio.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<string.h>
# include	<sys/types.h>
# include	<sys/socket.h>
# include	<netinet/in.h>
# include	<stdexcept>
# include	<ISocket.hpp>

class		Socket : public ISocket
{
 private:
  int		_fd;

 public:
  Socket(int domain, int protocol) {
    this->_fd = socket(domain, protocol, 0);
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
