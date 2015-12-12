//
// File.hpp for  in /home/jobertomeu/Work/rtype_cpp/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Fri Dec 11 18:32:59 2015 Joris Bertomeu
// Last update Sat Dec 12 01:08:54 2015 Joris Bertomeu
//

#ifndef			_FILE_HPP_
# define		_FILE_HPP_

# include		<string>
# include		<fstream>
# ifdef			_WIN32
#  include		<NetworkWin.hpp>
# else
#  include		<Network.hpp>
# endif
# include		<stdio.h>
# include		<CreateRequest.hpp>
# include		<sstream>
# include		<algorithm>

# define SSTR(x)	dynamic_cast<std::ostringstream&>(std::ostringstream() << std::dec << x)).str()

# define	D_BUF	2048

class			File
{
private:
# ifdef __linux__
struct MatchPathSeparator
{
  bool operator()( char ch ) const
  {
    return ch == '/';
  }
};
# else
  struct MatchPathSeparator
  {
    bool operator()( char ch ) const
    {
      return ch == '\\' || ch == '/';
    }
  };
# endif

private:
  std::string		_filename;
  std::string		_fullpath;
  std::string		_path;
  int			_size;
  std::string		_extension;
  std::fstream		*_handle;

public:
  File(const std::string &fullpath) {
    this->_fullpath = fullpath;
    FILE		*file;

    if (!(file = fopen(fullpath.c_str(), "rb")))
      throw (std::logic_error("File :: Constructor : Error while openning \"" + fullpath + "\""));
    fseek(file, 0L, SEEK_END);
    this->_size = ftell(file);
    std::cout << "Size : " << _size << std::endl;
    fclose(file);
  };

  File() {

  }

  virtual		~File() {

  };

  std::string		IntToString(int a)
  {
    std::ostringstream	temp;
    temp << a;
    return (temp.str());
  }

  std::string		basename( std::string const& pathname )
  {
    return std::string(std::find_if( pathname.rbegin(), pathname.rend(),
				     MatchPathSeparator() ).base(),
		       pathname.end() );
  }

  void			sendMe(int port, void (*clb)(int, void *data), void *data) {
    Network		net;
    Socket		*s;
    ANetwork::t_frame	*frame;
    FILE		*file;
    char		buff[D_BUF];
    int			i = 0;
    int			local, size = D_BUF;


    file = fopen(this->_fullpath.c_str(), "rb");
    net.init(port, ANetwork::TCP_MODE);
    net.bind();
    net.listen(2);
    s = (Socket*) net.select();
    frame = (ANetwork::t_frame*) s->read(sizeof(Network::t_frame));
    s->write(CreateRequest::create(1, 2, 3, IntToString(_size), true), sizeof(ANetwork::t_frame));
    s->write(CreateRequest::create(1, 2, 3, basename(this->_fullpath), true), sizeof(ANetwork::t_frame));
    while (i < this->_size) {
      local = fread(&buff[0], 1, size, file);
      i += local;
      s->write(buff, local);
      size = (_size - i > D_BUF) ? D_BUF : _size - i;
      clb(i * 100 / _size, data);
    }
    net.close();
    fclose(file);
  };

  void			receiveMe(const std::string &ip, int port, const std::string &dir, void (*cb)(int, void*), void *data) {
    Network		net;
    FILE		*file;
    char		*buff;
    int			received;
    int			i = 0, odoSize;
    ANetwork::t_frame	frame;

    try {
      net.init(port, ANetwork::TCP_MODE);
      net.connect(ip);
      net.write(CreateRequest::create(1, 2, 3, "File"));
      frame = net.read();
      odoSize = atoi(frame.data);
      frame = net.read();
      file = fopen(std::string(dir + frame.data).c_str(), "wb");
      while ((buff = (char*) net.getSocket()->read(D_BUF, &received))) {
	i += fwrite(buff, 1, received, file);
	cb(i * 100 / odoSize, data);
      }
      fclose(file);
    } catch (const std::exception &e) {
      std::cout << e.what() << std::endl;
    }
  };
};

#endif
