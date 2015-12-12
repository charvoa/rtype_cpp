//
// Bot.hh for  in /home/jobertomeu/Work/rtype_cpp/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Fri Dec 11 16:14:33 2015 Joris Bertomeu
// Last update Sat Dec 12 10:15:20 2015 Louis Audibert
//

#ifndef			_BOT_HH_
# define		_BOT_HH_

# include		<AEntity.hh>

class			Bot : public AEntity
{
private:
  int	_direction;
  int	_x;
  int	_y;
  int	_health;

  virtual void		generateY();

public:
  explicit		Bot(int id);
  virtual		~Bot();
  virtual void			update();
};

#endif
