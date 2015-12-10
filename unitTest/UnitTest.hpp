#ifndef		__UNITTEST_HPP_
# define	__UNITTEST_HPP_

# include	<iostream>
# include	<stdexcept>

class		UnitTest
{
private:
  Network	_network;

public:
  explicit	UnitTest() {};
  virtual	~UnitTest() {};

  void		init(int ac, char **argv) {
    if (ac < 5) {
      throw (std::logic_error("Usage : ./test_rtype <ip> <port> <-t(cp)|-u(dp)> <1|2|3...|n>"));
    }
    try {
      this->_network.init(atoi(argv[2]), (!strcmp(argv[3], "-t")) ? ANetwork::TCP_MODE : ANetwork::UDP_MODE);
      this->_network.connect(std::string(argv[1]));
    } catch (const std::exception &e) {
      throw (std::logic_error(e.what()));
    }
  };

  void		launch() {

  }
};

#endif
