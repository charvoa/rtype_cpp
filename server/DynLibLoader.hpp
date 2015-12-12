//
// DynLibLoader.hpp for  in /home/jobertomeu/Work/rtype_cpp/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Fri Dec 11 14:54:28 2015 Joris Bertomeu
// Last update Fri Dec 11 15:53:55 2015 Joris Bertomeu
//

#ifndef			_DYNLIBLOADER_HPP_
# define		_DYNLIBLOADER_HPP_

# include		<stdexcept>
# include		<string>
# include		<dlfcn.h>

class			DynLibLoader
{
private:
  void			*_handle;

public:
  explicit		DynLibLoader() {
    this->_handle = NULL;
  };

  virtual		~DynLibLoader() {};
  void			open(const std::string &path) {
    if (!(this->_handle = dlopen(path.c_str(), RTLD_LAZY)))
      throw (std::logic_error("DynLibLoader :: Open : Error while openning"));
  };

  void			*getSymbol(const std::string &sym) {
    void		*ptr;

    if (!this->_handle)
      throw (std::logic_error("DynLibLoader :: getSymbol : You must call \"open\" method first !"));
    if (!(ptr = dlsym(this->_handle, sym.c_str())))
      throw (std::logic_error(std::string("DynLibLoader :: getSymbol : Unable to get \"" + sym + "\"")));
    return (ptr);
  };

  void			close() {
    if (!this->_handle)
      throw (std::logic_error("DynLibLoader :: getSymbol : You must call \"open\" method first !"));
    dlclose(this->_handle);
  }
};

#endif
