//
// Network.hpp for  in /home/jobertomeu/Work/net
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Sat Dec  5 11:23:59 2015 Joris Bertomeu
// Last update Wed Dec  9 15:25:19 2015 Nicolas Charvoz
//

#ifndef				__NETWORKWIN_HPP__
# define			__NETWORKWIN_HPP__

# include			<ANetwork.hpp>
# include			<SocketWin.hpp>
# include			<list>
# include			<ProtocoleEnum.hh>
# define			_WINSOCK_DEPRECATED_NO_WARNINGS 1

class				Network : public ANetwork
{
private:
  ISocket			*_socket;
  int				_port;
  SOCKADDR_IN		serv_addr;
  fd_set			_fdList;
  fd_set			_activeFDList;
  Network::TYPE			_connectionMode;
  int				_fdSize;
  std::list<ISocket*>	_sList;

public:
  explicit			Network() {};
  virtual			~Network() {};
  void				init(int port, Network::TYPE type) {
    if (type == Network::TCP_MODE)
      this->_socket = new Socket(AF_INET, SOCK_STREAM, 0);
    else
      this->_socket = new Socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    this->_port = port;
    FD_ZERO(&_fdList);
    FD_SET(this->_socket->getFd(), &_fdList);
	this->_fdSize = 2;
	this->_connectionMode = type;
  };

  virtual void			bind() {
    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(this->_port);
    if (::bind(this->_socket->getFd(), (SOCKADDR *) &serv_addr,
	     sizeof(serv_addr)) < 0)
      throw (std::logic_error("Network :: Binding Error"));
  };

  virtual void			listen(int max) {
    if (this->_connectionMode == Network::UDP_MODE)
      throw (std::logic_error("Network :: Listen for UDP Mode not allowed"));
    ::listen(this->_socket->getFd(), max);
  };

  virtual ISocket		*accept() {
    SOCKADDR_IN			cli_addr;
    int					clilen = sizeof(cli_addr);

    if (this->_connectionMode == Network::UDP_MODE)
      throw (std::logic_error("Network :: Accept for UDP Mode not allowed"));
    return (new Socket(::accept(this->_socket->getFd(),
				(SOCKADDR *) &cli_addr, &clilen)));
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
	  memset((char *)&serv_addr, 0, sizeof(serv_addr));
	  serv_addr.sin_family = AF_INET;
	  serv_addr.sin_port = htons(this->_port);
	  serv_addr.sin_addr.s_addr = inet_addr(serverIP.c_str());
	  if (this->_connectionMode == Network::UDP_MODE) {
		  if (inet_addr(serverIP.c_str()) == INADDR_NONE)
			  throw (std::logic_error("Network :: Error while connecting ..."));
		  //serv_addr.sin_addr.s_addr = inet_addr(serverIP.c_str());
		  this->_socket->setForUDP(&(this->serv_addr));
	  } else {
		  if (::connect(this->_socket->getFd(), (SOCKADDR *) &serv_addr, sizeof(serv_addr)) < 0) {
			  throw (std::logic_error(std::string("Network :: Error while connecting : " + std::string(strerror(errno)))));
		  }
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
	  int					ret;

    this->_activeFDList = this->_fdList;
    if ((ret = ::select(FD_SETSIZE, &_activeFDList, NULL, NULL, NULL)) == SOCKET_ERROR)
      throw (std::logic_error("Network :: Error while selecting"));
    if (FD_ISSET(this->_socket->getFd(), &_activeFDList)) {
		if (this->_connectionMode == ANetwork::UDP_MODE) {
			return (new Socket(this->_socket->getFd(), SOCK_DGRAM));
		}
		else {
			ISocket *s = this->accept();
			this->listenSocket(s);
			return (s);
		}
		} else {
		for (std::list<ISocket*>::iterator it = this->_sList.begin(); it != this->_sList.end(); ++it) {
				if (FD_ISSET(dynamic_cast<Socket*>(*it)->getFd(), &_activeFDList))
					return (dynamic_cast<Socket*>(*it));
			}
		}
    return (NULL);
  };

  virtual void				listenSocket(ISocket *socket) {
	  this->_fdSize += 1;
	  this->_sList.push_back(socket);
    FD_SET(socket->getFd(), &_fdList);
  };

  virtual void				unlistenSocket(ISocket *socket) {
	  this->_fdSize -= 1;
	  this->_sList.remove(socket);
    FD_CLR(socket->getFd(), &_fdList);
  };
};

#endif
