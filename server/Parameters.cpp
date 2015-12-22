//
// Parameters.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Tue Dec  1 05:32:07 2015 Louis Audibert
// Last update Tue Dec 22 08:38:09 2015 Antoine Garcia
//

#include <Parameters.hh>

Parameters::Parameters()
{
  _difficulty = E_MEDIUM;
}

Parameters::~Parameters()
{

}

void	Parameters::setDifficulty(E_Difficulty difficulty)
{
  _difficulty = difficulty;
}

E_Difficulty	Parameters::getDifficulty() const
{
  return (_difficulty);
}
