//
// Parameters.cpp for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Tue Dec  1 05:32:07 2015 Louis Audibert
// Last update Tue Dec  8 22:26:57 2015 Nicolas Charvoz
//

#include <Parameters.hh>

Parameters::Parameters()
{
  _difficulty = E_UNDEF;
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
