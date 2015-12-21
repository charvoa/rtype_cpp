//
// Monitoring.hpp for  in /home/jobertomeu/Work/rtype_cpp/server/build
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Tue Dec 15 05:12:20 2015 Joris Bertomeu
// Last update Tue Dec 15 06:30:06 2015 Joris Bertomeu
//

#ifndef			_MONITORING_HPP_
# define		_MONITORING_HPP_

# ifdef			_WIN32
#  include		<NetworkWin.hpp>
#  include		<ThreadWin.hpp>
# else
#  include		<Network.hpp>
#  include		<ThreadUnix.hpp>
# endif
# include		<iostream>
# include		<string>

void			*_handleThread(void *ptr);

class			Monitoring
{
public:
  Network		_network;
  void			*_server;

private:
  Thread		_t;

public:
  explicit		Monitoring() : _t(42) {};
  virtual		~Monitoring() {};
  void			start(void *s) {
    this->_server = s;
    this->_t.attach(_handleThread, this);
    this->_t.run();
    std::cout << "Monitoring :: Start" << std::endl;
  };
  void			parseCommand(void *data, void *c);
};

#endif
