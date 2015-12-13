//
// DynLibLoaderWin.hpp for  in /home/jobertomeu/Work/rtype_cpp/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Fri Dec 11 18:37:48 2015 Joris Bertomeu
// Last update Fri Dec 11 18:49:33 2015 Joris Bertomeu
//

#ifndef			_DYNLIBLOADER_HPP_
# define		_DYNLIBLOADER_HPP_

# include		<stdexcept>
# include		<string>
# include		<windows.h>

class			DynLibLoader
{
private:
  HINSTANCE		_handle;

public:
  explicit		DynLibLoader() {
    this->_handle = NULL;
  };

  virtual		~DynLibLoader() {};
  void			open(const std::string &path) {
    if (!(this->_handle = LoadLibrary(TEXT(path.c_str()))))
      throw (std::logic_error("DynLibLoader :: Open : Error while openning " + path));
  };

  void			*getSymbol(const std::string &sym) {
    void		*ptr;

    if (!this->_handle)
      throw (std::logic_error("DynLibLoader :: getSymbol : You must call \"open\" method first !"));
    if (!(ptr = (void*) GetProcAddress(this->_handle, sym.c_str())))
      throw (std::logic_error(std::string("DynLibLoader :: getSymbol : Unable to get \"" + sym + "\"")));
    return (ptr);
  };

  void			close() {
    if (!this->_handle)
      throw (std::logic_error("DynLibLoader :: getSymbol : You must call \"open\" method first !"));
    FreeLibrary(this->_handle);
  }
};

#endif
