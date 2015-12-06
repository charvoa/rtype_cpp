//
// AMutex.hh for  in /home/nicolaschr/rendu/rtype_cpp/server
//
// Made by Nicolas Charvoz
// Login   <nicolaschr@epitech.net>
//
// Started on  Wed Dec  2 18:06:33 2015 Nicolas Charvoz
// Last update Wed Dec  2 21:17:21 2015 Nicolas Charvoz
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
  virtual void unlock() = 0;
};

#endif
