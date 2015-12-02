//
// Network.cpp for  in /home/jobertomeu/Work/rtype_cpp/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Wed Nov 18 00:22:39 2015 Joris Bertomeu
// Last update Wed Dec  2 13:24:27 2015 Nicolas Charvoz
//

#include	"Network.hh"
#include	<iostream>

Network::Network()
{
  std::cout << "Network Instantiation" << std::endl;
}

Network::~Network()
{

}

void	Network::create(int port_, int sockType_, const std::string &addr_)
{
  (void)addr_;
  std::cout << "Create" <<std::endl;
  this->_socket = new Socket(sockType_, SOCK_STREAM, port_);

}

void	Network::bind()
{
  if (::bind(this->_socket->getFd(),
	   (struct sockaddr *) this->_socket->getAddr(),
	   sizeof(this->_socket->getAddr())) < 0)
    throw (std::logic_error(std::string("Error while binding : " + std::string(strerror(errno)))));
}

void	Network::listen()
{
  ::listen(this->_socket->getFd(), 42);
}

void	*Network::read(int size)
{
  if (size >= 4096)
    throw (std::logic_error("Read size must be < 4096"));
  ::read(this->_socket->getFd(), this->_buffer, size);
  return (&(this->_buffer[0]));
}

int	Network::write(void *data, int size)
{
  return (::write(this->_socket->getFd(), data, size));
}

void	Network::close()
{
  this->_socket->close();
}

ISocket	*Network::accept()
{
  int	fd;
  struct sockaddr_in addr;
  socklen_t		len;

  std::cout << "Network :: Accept" << std::endl;
  fd = ::accept(this->_socket->getFd(), (struct sockaddr *) &addr, &len);
  if (fd < 0)
    throw (std::logic_error(std::string("Error while accepting : " + std::string(strerror(errno)))));
  return (new Socket(fd, this->_socket));
}
