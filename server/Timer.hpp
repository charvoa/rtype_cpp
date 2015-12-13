//
// Timer.hh for Timer in /home/antoinegarcia/rendu/rtype_cpp/server
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Sat Dec 12 12:52:59 2015 Antoine Garcia
// Last update Sun Dec 13 19:42:07 2015 Nicolas Charvoz
//

#ifndef _TIMER_HPP_
# define _TIMER_HPP_

#include <chrono>
#include <ostream>

class Timer {
  typedef std::chrono::high_resolution_clock high_resolution_clock;
  typedef std::chrono::seconds	    seconds;
typedef std::chrono::milliseconds	    milliseconds;
public:
  explicit Timer(bool run = false)
  {
    if (run)
      reset();
  }
  void reset()
  {
    _start = high_resolution_clock::now();
  }
  seconds elapsed() const
  {
    return std::chrono::duration_cast<seconds>(high_resolution_clock::now() - _start);
  }
  template <typename T, typename Traits>
  friend std::basic_ostream<T, Traits>& operator<<(std::basic_ostream<T, Traits>& out, const Timer& timer)
  {
    return out << timer.elapsed().count();
  }
private:
  high_resolution_clock::time_point _start;
};


#endif
