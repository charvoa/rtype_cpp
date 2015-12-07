//
// ISocket.hpp for  in /home/jobertomeu/Work/rtype_cpp/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue Nov 17 23:55:57 2015 Joris Bertomeu
// Last update Sun Dec  6 08:45:28 2015 Antoine Garcia
//

#ifndef		__ISOCKET_HPP_
# define	__ISOCKET_HPP_

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
