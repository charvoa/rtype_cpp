//
// Socket.cpp for  in /home/jobertomeu/Work/rtype_cpp/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Wed Nov 18 00:01:36 2015 Joris Bertomeu
// Last update Wed Nov 18 01:28:28 2015 Joris Bertomeu
//

#include	"Socket.hh"

Socket::Socket(int type_, int domain_, int port_)
{

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
