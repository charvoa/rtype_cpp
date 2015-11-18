//
// Parameters.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Tue Dec  1 05:32:07 2015 Louis Audibert
// Last update Tue Dec  1 05:39:43 2015 Louis Audibert
//

#include "Parameters.hh"

Parameters::Parameters()
{
  _difficulty = E_UNDEF;
}

Parameters::~Parameters()
{
  std::cout << "Parameters Destroyed" << std::endl;
}

void	Parameters::setDifficulty(E_DIFFICULTY difficulty)
{
  _difficulty = difficulty;
}

E_DIFFICULTY	Parameters::getDifficulty() const
{
  return (_difficulty);
}
