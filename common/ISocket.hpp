//
// ISocket.hpp for  in /home/jobertomeu/Work/rtype_cpp/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue Nov 17 23:55:57 2015 Joris Bertomeu
// Last update Tue Dec 22 13:44:59 2015 Joris Bertomeu
//

#ifndef		__ISOCKET_HPP_
# define	__ISOCKET_HPP_
# ifdef		_WIN32
#  include	<winsock2.h>
# endif
# include	<string>

class		ISocket
{
public:
  explicit	ISocket() {};
  virtual	~ISocket() {};
  virtual void	*read(int) = 0;
  virtual void	close() = 0;
  virtual int	write(void *, int) = 0;
  virtual void	*read(int, int*) = 0;
  virtual std::string getIP() = 0;
# ifdef _WIN32
  virtual SOCKET	getFd() const = 0;
  virtual void		setForUDP(SOCKADDR_IN *s) = 0;
# else
  virtual int	getFd() const = 0;
  virtual void	setForUDP(struct sockaddr_in *s) = 0;
# endif
  virtual bool		isEqualTo(ISocket *s) = 0;
};

#endif
