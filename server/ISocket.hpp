//
// ISocket.hpp for  in /home/jobertomeu/Work/rtype_cpp/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue Nov 17 23:55:57 2015 Joris Bertomeu
// Last update Wed Nov 18 01:28:02 2015 Joris Bertomeu
//

class		ISocket
{
protected:


public:
  explicit	ISocket() {};
  virtual	~ISocket() {};
  virtual void	*read();
  virtual int	write(void *);
};
