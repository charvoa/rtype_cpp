//
// Socket.cpp for  in /home/jobertomeu/Work/rtype_cpp/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Wed Nov 18 00:01:36 2015 Joris Bertomeu
// Last update Sat Dec  5 10:44:21 2015 Joris Bertomeu
//

#include	<Socket.hh>
#include	<iostream>

Socket::Socket(int type_, int domain_, int port_)
{
  this->_port = port_;
  this->_type = type_;
  this->_domain = domain_;
  if ((this->_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    throw (std::logic_error("Error while opening socket"));
  std::cout << "Socket created on port " << this->_port << " with fd " << this->_fd << std::endl;
  bzero(&(this->_servAddr), sizeof(struct sockaddr_in));
  if (::bind(this->_fd,
	     (struct sockaddr *) &(this->_servAddr),
	     sizeof(this->_servAddr)) < 0) {
    this->close();
    throw (std::logic_error(std::string("Error while binding : " + std::string(strerror(errno)))));
  }
  ::listen(this->_fd, 5);
  struct sockaddr_in	addr;
  socklen_t		len = sizeof(addr);

  std::cout << "Socket :: Accept (" << this->_fd << ")" << std::endl;
  ::accept(this->_fd, (struct sockaddr *) &addr, &len);
}

Socket::Socket(int fd_, ISocket *s_)
{
  this->_fd = fd_;
  this->_port = s_->getPort();
  this->_type = s_->getType();
  this->_domain = s_->getDomain();
  this->_servAddr = *(s_->getAddr());
}

Socket::~Socket()
{

}

int	Socket::getFd() const
{
  return (this->_fd);
}

int	Socket::getType() const
{
  return (this->_type);
}

int	Socket::getDomain() const
{
  return (this->_domain);
}

int	Socket::getProtocol() const
{
  return (this->_protocol);
}

void	*Socket::read(int size)
{
  ::read(this->_fd, this->_buff, size);
  return (&(this->_buff[0]));
}

int	Socket::write(void *data, int size)
{
  return (::write(this->_fd, data, size));
}

struct sockaddr_in	*Socket::getAddr()
{
  return (&(this->_servAddr));
}

void	Socket::close()
{
  ::close(this->_fd);
}

int	Socket::getPort() const
{
  return (this->_port);
}
