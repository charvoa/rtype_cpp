//
// AMutex.hh for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Dec  2 18:06:33 2015 Nicolas Charvoz
// Last update Tue Dec 15 16:34:49 2015 Nicolas Charvoz
//

#ifndef AMUTEX_HH_
# define AMUTEX_HH_

class AMutex {

protected:
  bool _isLocked;

public:

  AMutex() {
    _isLocked = false;
  };

  virtual void lock() = 0;
  virtual bool try_lock() = 0;
  virtual void unlock() = 0;
};

#endif
