//
// Bot.hh for  in /home/jobertomeu/Work/rtype_cpp/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Fri Dec 11 16:14:33 2015 Joris Bertomeu
// Last update Fri Dec 11 17:32:02 2015 Joris Bertomeu
//

#ifndef			_BOT_HH_
# define		_BOT_HH_

# include		<AEntity.hh>

class			Bot : public AEntity
{
public:
  explicit		Bot(int id);
  virtual		~Bot();
  virtual void			update();
};

#endif
