//
// ANetwork.hh for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Nov 25 16:38:49 2015 Nicolas Charvoz
// Last update Mon Nov 30 18:30:40 2015 Nicolas Charvoz
//

#ifndef ANETWORK_HH_
# define ANETWORK_HH_

# include	<string>
# include	"ISocket.hpp"

class ANetwork {

public :
  typedef struct s_frame {
    short int _keyPintade;
    unsigned char _requestType;
    unsigned int _idRequest;
    int _crc;
    int _sizeData;
    char _data[49];
  } t_frame;

  ANetwork() {};
  virtual	~ANetwork() {};
  virtual void	create(int port_, int sockType_, const std::string &addr_) = 0;
  virtual void	bind() = 0;
  virtual void	listen() = 0;
  virtual void	*read() = 0;
  virtual int	write(void *) = 0;
  virtual void	close() = 0;
  virtual void	accept(ISocket *) = 0;

private:
  ISocket	*_socket;

};

#endif
