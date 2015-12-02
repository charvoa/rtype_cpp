//
// Socket.cpp for  in /home/jobertomeu/Work/rtype_cpp/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Wed Nov 18 00:01:36 2015 Joris Bertomeu
// Last update Thu Nov 19 00:01:14 2015 Joris Bertomeu
//

#include	"Socket.hh"
#include	<iostream>

Socket::Socket(int type_, int domain_, int port_)
{
  this->_port = port_;
  this->_type = type_;
  this->_domain = domain_;
  if ((this->_fd = socket(domain_, type_, 0)) < 0)
    throw (std::logic_error("Error while opening socket"));
  std::cout << "Socket created on port " << this->_port << " with fd " << this->_fd << std::endl;
  this->_servAddr.sin_family = domain_;
  this->_servAddr.sin_addr.s_addr = INADDR_ANY;
  this->_servAddr.sin_port = htons(port_);
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

void	*Socket::read()
{

}

int	Socket::write(void *data)
{

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
