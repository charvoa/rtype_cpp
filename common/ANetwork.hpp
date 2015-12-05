//
// ANetwork.hh for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Nov 25 16:38:49 2015 Nicolas Charvoz
// Last update Sat Dec  5 17:11:29 2015 Nicolas Charvoz
//

#ifndef ANETWORK_HPP_
# define ANETWORK_HPP_

# include	<string>
# include	<ISocket.hpp>

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
    short int		keyPintade;
    unsigned int	idRequest;
    int			crc;
    int			sizeData;
    char		data[49];
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
  virtual void		connect(const std::string &) = 0;
  virtual t_frame	read() = 0;
  virtual int		write(t_frame) = 0;
  virtual void		select() = 0;
};

#endif
