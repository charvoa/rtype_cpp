//
// FileManager.hpp for  in /home/jobertomeu/Work/rtype_cpp/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Fri Dec 11 18:19:25 2015 Joris Bertomeu
// Last update Tue Dec 15 15:28:17 2015 Nicolas Girardot
//

#ifndef			_FILEMANAGER_HPP_
# define		_FILEMANAGER_HPP_

# include		<File.hpp>
# include		<string>
# include		<sys/types.h>
# include		<dirent.h>
# include		<list>
# include		<stdexcept>

class			FileManager
{
  std::string		_dir;
  DIR			*_handle;
  std::list<File*>	_fileList;

public:
  explicit		FileManager(const std::string &dir) {
    struct dirent	*dp;

    this->_dir = dir;
    if (!(this->_handle = opendir(dir.c_str())))
      throw (std::logic_error(std::string("FileManager :: Error while openning \"" + dir + "\"")));
    while ((dp = readdir(this->_handle))) {
		try {
			this->_fileList.push_back(new File(std::string(this->_dir + dp->d_name)));
		}
		catch (const std::exception &e) {
			std::cout << "FileManager :: Exception :: " << e.what() << std::endl;
		}
    }
  };

  virtual		~FileManager(void) {
    closedir(this->_handle);
  };

  std::list<File*>	getFileListByExtension(const std::string &ext) {
    std::list<File*>	list;

    for (std::list<File*>::iterator it = this->_fileList.begin(); it != this->_fileList.end(); ++it) {
      if (!(*it)->getExtension().compare(ext))
	list.push_back((*it));
    }
    return (list);
  };
};

#endif
