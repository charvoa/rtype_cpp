//
// Parameters.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Tue Dec  1 05:32:11 2015 Louis Audibert
// Last update Tue Dec  1 05:35:34 2015 Louis Audibert
//

#ifndef _PARAMETERS_HH_
# define _PARAMETERS_HH_

# include <iostream>
# include "E_Difficulty.hh"

class Parameters
{
private:
  E_DIFFICULTY	_difficulty;

public:
  Parameters();
  ~Parameters();

  void	setDifficulty(E_DIFFICULTY difficulty);
  E_DIFFICULTY	getDifficulty() const;
};

#endif /* _PARAMETERS_HH_ */
