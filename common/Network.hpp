//
// Network.hpp for  in /home/jobertomeu/Work/net
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Sat Dec  5 11:23:59 2015 Joris Bertomeu
// Last update Sat Dec  5 13:41:21 2015 Joris Bertomeu
//

#ifndef				__NETWORK_HPP__
# define			__NETWORK_HPP__

# include			<ANetwork.hpp>
# include			<Socket.hpp>

class				Network : public ANetwork
{
private:
  ISocket			*_socket;
  int				_port;
  struct sockaddr_in		serv_addr;

public:
  explicit			Network() {};
  virtual			~Network() {};
  void				init(int port, Network::TYPE type) {
    if (type == Network::TCP_MODE)
      this->_socket = new Socket(AF_INET, SOCK_STREAM);
    else
      this->_socket = new Socket(AF_INET, SOCK_DGRAM);
    this->_port = port;
  };
  virtual void			bind() {
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(this->_port);
    if (::bind(this->_socket->getFd(), (struct sockaddr *) &serv_addr,
	     sizeof(serv_addr)) < 0)
      throw (std::logic_error("Network :: Binding Error"));
  };

  virtual void			listen(int max) {
    ::listen(this->_socket->getFd(), max);
  };

  virtual ISocket		*accept() {
    struct sockaddr_in	cli_addr;
    socklen_t		clilen = sizeof(cli_addr);

    return (new Socket(::accept(this->_socket->getFd(),
				(struct sockaddr *) &cli_addr, &clilen)));
  }
  virtual void			close() {
    this->_socket->close();
  };

  virtual void			*read(int size) {
    return (this->_socket->read(size));
  }

  virtual int			write(void *data, int size) {
    return (this->_socket->write(data, size));
  }

  virtual void			connect(const std::string &serverIP) {
    struct hostent		*server;

    server = gethostbyname(serverIP.c_str());
    if (server == NULL) {
      throw (std::logic_error("Network :: Server IP is not valid"));
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr,
	  (char *) &serv_addr.sin_addr.s_addr,
	  server->h_length);
    serv_addr.sin_port = htons(this->_port);
    if (::connect(this->_socket->getFd(), (struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
      throw (std::logic_error("Network :: Error while connecting"));
  };
};

#endif
