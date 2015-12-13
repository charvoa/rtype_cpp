//
// Random.hpp for Random in /home/antoinegarcia/rendu/rtype_cpp/server
//
// Made by Antoine Garcia
// Login   <antoinegarcia@epitech.net>
//
// Started on  Sun Dec 13 01:19:38 2015 Antoine Garcia
// Last update Sun Dec 13 02:02:49 2015 Antoine Garcia
//

#ifndef _RANDOM_HH__
# define _RANDOM_HH__

#include <iostream>
#include <numeric>
#include <vector>
#include <string>
#include <random>
class	Random
{
  std::string	_str;
  std::vector<int> _vec;
public:
  Random(const std::string &str)
  {
    _str = str;
  }

  Random(int begin, int end)
  {
    std::vector<int> vec(end - begin);
    _vec = vec;
    std::iota(_vec.begin(),_vec.end(), begin);
  }
  template <typename T>
  T	generate()
  {
    std::random_device rd;
    std::mt19937 mt(rd());
    if (_str.size() > 0)
      {
	std::uniform_int_distribution<int> dist(0, _str.size() - 1);
	int	rand = dist(mt);
	char id = _str[rand];
	return id;
      }
    else
      {
	std::uniform_int_distribution<int> dist(0, _vec.size() - 1);
	int	rand = dist(mt);
	int id = _vec[rand];
	return id;
      }
  }
};

#endif
