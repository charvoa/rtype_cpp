#ifndef			_TEST_HPP_
# define		_TEST_HPP_

# include		<string>
# include		<stack>
# include		<ANetwork.hpp>
# include		<CreateRequest.hpp>
# include		<map>

# define CMD_HELLO	CreateRequest::create(1, 2, 3, "Hello World")


class			Test
{
private:
  std::string		_title;
  std::string		_description;
  std::stack<ANetwork::t_frame>	_cmdList;
  int			_id;

public:
  explicit		Test(const std::string &title, const std::string &desc, int *id) {
    this->_title = title;
    this->_description = desc;
    this->_id = *id + 1;
    *id += 1;
  };
  virtual		~Test() {};
  std::string		getTitle() const {
    return (this->_title);
  };

  std::string		getDescription() const {
    return (this->_description);
  };

  Test			*addCommand(const ANetwork::t_frame &req, const std::string &desc) {
    this->_cmdList.push(req);
    return (this);
  };

  int			getId() const {
    return (this->_id);
  };
  
  void			launchTest(ANetwork *net) {
    int			i = 0;
    ANetwork::t_frame	frame;

    std::cout << "Launching test " << _id << std::endl << std::endl;
    std::cout << "\tTitle       : " << getTitle() << std::endl;
    std::cout << "\tDescription : " << getDescription() << std::endl << std::endl;
    std::cout << "***** Starting sequence *****" << std::endl << std::endl;;
    while (!this->_cmdList.empty()) {
      std::cout << "Frame " << i++ << " send\t\t[OK]" << std::endl;
      net->write(this->_cmdList.top());
      this->_cmdList.pop();
      frame = net->read();
      std::cout << "\tResponse : " << CreateRequest::getData(frame) << std::endl;
    }
    std::cout << std::endl << "***** Sequence finished *****" << std::endl;
  };
};

#endif
