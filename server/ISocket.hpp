//
// ISocket.hpp for  in /home/jobertomeu/Work/rtype_cpp/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue Nov 17 23:55:57 2015 Joris Bertomeu
// Last update Sat Dec  5 12:21:57 2015 Joris Bertomeu
//

#ifndef		__ISOCKET_HPP_
# define	__ISOCKET_HPP_

# include	<sys/types.h>
# include	<unistd.h>
# include	<sys/socket.h>
# include	<netinet/in.h>
# include	<stdexcept>
# include	<string.h>
# include	<errno.h>

class		ISocket
{
public:
  explicit	ISocket() {};
  virtual	~ISocket() {};
  virtual void	*read(int) = 0;
  virtual void	close() = 0;
  virtual int	write(void *, int) = 0;
  virtual int	getFd() const = 0;
};

#endif
