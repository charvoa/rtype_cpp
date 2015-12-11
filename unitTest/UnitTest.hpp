#ifndef		__UNITTEST_HPP_
# define	__UNITTEST_HPP_

# include	<iostream>
# include	<stdexcept>
# include	<Test.hpp>
# include	<list>

class		UnitTest
{
private:
  Network	_network;
  std::list<Test*>	_testsList;
  int		_testId;
  int		_testMarked;

public:
  explicit	UnitTest() {};
  virtual	~UnitTest() {
    this->_testId = 0;
    this->_network.close();
  };

  void		init(int ac, char **argv) {
    this->initTests();
    if (ac == 2 && !strcmp(argv[1], "-l")) {
      showTests();
      exit(0);
    } else if (ac < 5) {
      throw (std::logic_error("Usage : ./test_rtype [-l(ist)] [<ip> <port> <-t(cp)|-u(dp)> <1|2|3...|n>]"));
    }
    try {
      this->_testMarked = atoi(argv[4]);
      this->_network.init(atoi(argv[2]), (!strcmp(argv[3], "-t")) ? ANetwork::TCP_MODE : ANetwork::UDP_MODE);
      this->_network.connect(std::string(argv[1]));
    } catch (const std::exception &e) {
      throw (std::logic_error(e.what()));
    }
  };

  void		launch() {
    try {
      for (std::list<Test*>::iterator it = this->_testsList.begin(); it != this->_testsList.end(); ++it) {
	if ((*it)->getId() == this->_testMarked) {
	  (*it)->launchTest(&(this->_network));
	  break;
	}
      }
    } catch (const std::exception &e) {
      throw (std::logic_error(e.what()));
    }
  };

private:
  void		showTests() {
    for (std::list<Test*>::iterator it = this->_testsList.begin(); it != this->_testsList.end(); ++it) {
      std::cout << "\033[37m----- TEST " << (*it)->getId() << " -----\033[0m" << std::endl;
      std::cout << "\tTitle       : " << (*it)->getTitle() << std::endl;
      std::cout << "\tDescription : " << (*it)->getDescription() << std::endl << std::endl;;
    }
  }

  void		initTests() {
    /* Describe TEST */
    Test	*hello_world_t = new Test("Hello World", "Send simple Hello World into data", &_testId);
    hello_world_t
      ->addCommand(CMD_HELLO, "Send coucou")
      ->addCommand(CMD_HELLO, "Send coucou");
    this->_testsList.push_back(hello_world_t);
    this->_testsList.push_back(hello_world_t);
    /* Describe TEST */
  };
};

#endif
