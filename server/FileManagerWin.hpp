#ifndef			_FILEMANAGERWIN_HPP_
# define		_FILEMANAGERWIN_HPP_

# include		<File.hpp>
# include		<string>
# include		<sys/types.h>
# include		<windows.h>
# include		<strsafe.h>
# include		<list>
# include		<stdexcept>
# include		<iostream>

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

	  StringCchLength(_dir.c_str(), MAX_PATH, &length);

	  if (length > (MAX_PATH - 3))
	  {
		  std::cerr << ("Directory path is too long.") << std::endl;
		  return;
	 }

	  StringCchCopy(szDir, MAX_PATH, _dir.c_str());
	  StringCchCat(szDir, MAX_PATH, TEXT("\\*"));

	  _handle = FindFirstFile(szDir, &ffd);

	  if (_handle == INVALID_HANDLE_VALUE)
	  {
		  std::cerr << "First file not found" << std::endl;
		  return;
	  }

	  while (FindNextFile(_handle, &ffd) != 0)
	  {
		  _fileList.push_back(new File(_dir + ffd.cFileName));
	  }
	  CloseHandle(_handle);
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
