//
// ANetwork.hh for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Nov 25 16:38:49 2015 Nicolas Charvoz
// Last update Sat Dec  5 12:25:39 2015 Joris Bertomeu
//

#ifndef ANETWORK_HPP_
# define ANETWORK_HPP_

# include	<string>
# include	<Socket.hpp>

class ANetwork
{
public:
   typedef enum		e_TYPE {
    TCP_MODE,
    UDP_MODE
  }			TYPE;

protected:
  char			_buffer[4096];
  ISocket		*_socket;

public :
  typedef struct	s_frame {
    short int		_keyPintade;
    unsigned char	_requestType;
    unsigned int	_idRequest;
    int			_crc;
    int			_sizeData;
    char		_data[49];
  }			t_frame;

  ANetwork() {};
  virtual		~ANetwork() {};
  virtual void		init(int port_, ANetwork::TYPE type) = 0;
  virtual void		bind() = 0;
  virtual void		listen(int) = 0;
  virtual void		*read(int) = 0;
  virtual int		write(void *, int) = 0;
  virtual void		close() = 0;
  virtual ISocket	*accept() = 0;

};

#endif
