//
// DLLoader.hpp for rtype in /home/garcia_t/rendu/cpp_nibbler
//
// Made by antoine garcia
// Login   <garcia_t@epitech.net>
//
// Started on  Tue Mar 24 13:36:59 2015 antoine garcia
// Last update Fri Dec 11 14:53:56 2015 Joris Bertomeu
//

#ifndef DLLoader_H_
# define DLLoader_H_

# include <cstdlib>
# include <string>
# include <iostream>
# include <dlfcn.h>
# include <exception>
# include <AEntity.hh>

class	DLLException: public std::exception
{
public:
  explicit DLLException(const char* message):
    msg_(message)
  {}
  explicit DLLException(const std::string& message):
    msg_(message)
  {}
  virtual ~DLLException() throw (){}
  virtual const char* what() const throw (){
    return msg_.c_str();
  }

protected:
  std::string msg_;
};

template<typename T>
class DLLoader
{
  void	*_handle;
  T	_func;
public:
  explicit DLLoader(const std::string &lib, int id)
  {
    T (*ptr)(int);
    char	*err;
    std::string lib_name = "./libs/";

    lib_name += lib;
    _handle = dlopen(lib_name.c_str(), RTLD_NOW);
    if (!_handle)
      throw DLLException(dlerror());
    ptr = reinterpret_cast<T (*)(int)>(dlsym(_handle, "create_object"));
    if ((err = dlerror()) != NULL)
      throw DLLException("Symbol wasn't found.\n");
    _func = ptr(id);
  }
  AEntity *getInstance() const
  {
    return (_func);
  }
  ~DLLoader()
  {
    dlclose(_handle);
  }
};

#endif
