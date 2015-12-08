//
// Parameters.hh for rtype in /home/audibel/rendu/rtype_cpp/server
//
// Made by Louis Audibert
// Login   <audibel@epitech.net>
//
// Started on  Tue Dec  1 05:32:11 2015 Louis Audibert
// Last update Tue Dec  8 22:26:43 2015 Nicolas Charvoz
//

#ifndef _PARAMETERS_HH_
# define _PARAMETERS_HH_

# include <iostream>
# include <E_Difficulty.hh>

class Parameters
{
private:
  E_Difficulty	_difficulty;

public:
  Parameters();
  ~Parameters();

  void	setDifficulty(E_Difficulty difficulty);
  E_Difficulty	getDifficulty() const;
};

#endif /* _PARAMETERS_HH_ */
