//
// Network.hpp for  in /home/jobertomeu/Work/net
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Sat Dec  5 11:23:59 2015 Joris Bertomeu
// Last update Sat Dec 12 00:18:40 2015 Joris Bertomeu
//

#ifndef				__NETWORK_HPP__
# define			__NETWORK_HPP__

# include			<ANetwork.hpp>
# include			<Socket.hpp>
# include			<ProtocoleEnum.hh>

class				Network : public ANetwork
{
private:
  ISocket			*_socket;
  int				_port;
  struct sockaddr_in		serv_addr;
  fd_set			_fdList;
  fd_set			_activeFDList;
  Network::TYPE			_connectionMode;

public:
  explicit			Network() {};
  virtual			~Network() {};
  void				init(int port, Network::TYPE type) {
    std::cout << "Network::init (" << port << ")" <<std::endl;
    if (type == Network::TCP_MODE)
      this->_socket = new Socket(AF_INET, SOCK_STREAM, 0);
    else
      this->_socket = new Socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    this->_port = port;
    this->_connectionMode = type;
    FD_ZERO(&_fdList);
    FD_SET(this->_socket->getFd(), &_fdList);
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
    if (this->_connectionMode == Network::UDP_MODE)
      throw (std::logic_error("Network :: Listen for UDP Mode not allowed"));
    ::listen(this->_socket->getFd(), max);
  };

  virtual ISocket		*accept() {
    struct sockaddr_in		cli_addr;
    socklen_t			clilen = sizeof(cli_addr);

    if (this->_connectionMode == Network::UDP_MODE)
      throw (std::logic_error("Network :: Accept for UDP Mode not allowed"));
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
    serv_addr.sin_port = htons(this->_port);
    if (this->_connectionMode == Network::UDP_MODE) {
      if (inet_aton(serverIP.c_str(), &serv_addr.sin_addr) == 0)
	throw (std::logic_error("Network :: Error while connecting ..."));
      this->_socket->setForUDP(&(this->serv_addr));
    } else {
      bcopy((char *) server->h_addr,
	    (char *) &serv_addr.sin_addr.s_addr,
	    server->h_length);
      if (::connect(this->_socket->getFd(),
		    (struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0)
	throw (std::logic_error("Network :: Error while connecting"));
    }
  };

  virtual t_frame		read() {
    t_frame			frame;

    memcpy(&frame, this->_socket->read(sizeof(t_frame)), sizeof(t_frame));
    return (frame);
  };

  virtual int			write(t_frame frame) {
    return (this->_socket->write(&frame, sizeof(t_frame)));
  }

  virtual ISocket		*select() {
    this->_activeFDList = this->_fdList;
    if (::select(FD_SETSIZE, &_activeFDList, NULL, NULL, NULL) < 0)
      throw (std::logic_error("Network :: Error while selecting"));
    for (int i = 0; i < FD_SETSIZE; i++) {
      if (FD_ISSET(i, &_activeFDList)) {
	if (i == this->_socket->getFd()) {
	  if (this->_connectionMode == ANetwork::UDP_MODE) {
	    return (new Socket(i, SOCK_DGRAM));
	  } else {
	    ISocket *s = this->accept();
	    this->listenSocket(s);
	    return (s);
	  }
	}
	else
	  return (new Socket(i));
      }
    }
    return (NULL);
  };

  virtual void			listenSocket(ISocket *socket) {
    FD_SET(socket->getFd(), &_fdList);
  };

  virtual void			unlistenSocket(ISocket *socket) {
    FD_CLR(socket->getFd(), &_fdList);
  };
  virtual ISocket		*getSocket() {
    return (this->_socket);
  }

};

#endif
