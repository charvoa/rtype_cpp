//
// Socket.cpp for  in /home/jobertomeu/Work/rtype_cpp/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Wed Nov 18 00:01:36 2015 Joris Bertomeu
// Last update Wed Nov 18 16:55:10 2015 Joris Bertomeu
//

#include	"Socket.hh"
#include	<iostream>

Socket::Socket(int type_, int domain_, int port_)
{
  this->_port = port_;
  this->_type = type_;
  this->_port = port_;
  if ((this->_fd = socket(domain_, type_, 0)) < 0)
    throw (std::logic_error("Error while opening socket"));
  std::cout << "Socket created on port " << this->_port << " with fd " << this->_fd << std::endl;
  this->_servAddr.sin_family = domain_;
  this->_servAddr.sin_addr.s_addr = INADDR_ANY;
  this->_servAddr.sin_port = htons(port_);
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
