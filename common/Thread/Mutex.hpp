//
// MutexUnix.hpp for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Dec  2 18:06:01 2015 Nicolas Charvoz
// Last update Tue Dec 15 17:10:10 2015 Nicolas Charvoz
//

#ifndef MUTEX_HPP_
# define MUTEX_HPP_

# include <AMutex.hh>
# include <mutex>

class Mutex : public AMutex {

  std::mutex _mutex;

public:

  Mutex() {

  };

  void lock() {
    _mutex.lock();
    _isLocked = true;
  };
  bool try_lock() {
    if (_mutex.try_lock())
      {
	_isLocked = true;
	return true;
      }
    else {
      _isLocked = false;
      return false;
    }
  };
  void unlock() {
    _mutex.unlock();
    _isLocked = false;
  };
  std::mutex *getMutex() {
    return &_mutex;
  };

};

#endif
