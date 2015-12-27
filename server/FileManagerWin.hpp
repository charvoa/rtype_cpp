#ifndef			_FILEMANAGERWIN_HPP_
# define		_FILEMANAGERWIN_HPP_

# include		<File.hpp>
# include		<string>
# include		<sys/types.h>
# include		<windows.h>
//# include		<strsafe.h>
# include		<list>
# include		<stdexcept>
# include		<iostream>
# pragma comment(lib, "User32.lib")

class			FileManager
{
  std::string		_dir;
  HANDLE			_handle;
  std::list<File*>	_fileList;

public:
  explicit		FileManager(const std::string &dir) {
	  _handle = INVALID_HANDLE_VALUE;
	  WIN32_FIND_DATA ffd;
	  _dir = dir;
	  LARGE_INTEGER fileSize;
	  TCHAR		szDir[MAX_PATH];
	  DWORD		dwError = 0;
	  size_t	length;

	  strcpy(szDir, _dir.c_str());
	  strcat(szDir, "\\*");
	  _handle = FindFirstFile(szDir, &ffd);

	  if (_handle == INVALID_HANDLE_VALUE)
	  {
		  std::cout << "First file not found" << std::endl;
		  return;
	  }
	  std::cout << "Before loop" << std::endl;
	  while (FindNextFile(_handle, &ffd) != 0)
	  {
		  if (!std::string(ffd.cFileName).compare("..") || !std::string(ffd.cFileName).compare("."))
			  continue;
		  _fileList.push_back(new File(_dir + ffd.cFileName));
		  std::cout << ffd.cFileName << std::endl;
	  }
	  system("PAUSE");
	  //CloseHandle(_handle);
  };

  virtual		~FileManager(void) {
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
