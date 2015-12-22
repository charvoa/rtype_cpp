//
// Bot.hh for  in /home/jobertomeu/Work/rtype_cpp/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Fri Dec 11 16:14:33 2015 Joris Bertomeu
// Last update Tue Dec 22 03:23:54 2015 Serge Heitzler
//

#ifndef			_BOT_HH_
# define		_BOT_HH_

# include		<AEntity.hh>
# include		<Random.hpp>
# include		<E_Component.hh>

# define HEIGHT 855
# define WIDTH 1920

class			Bot : public AEntity
{
public:
  std::string _sprite;

private:
  int	_direction;
  int	_x;
  int	_y;
  int	_health;

  virtual void		generateY();
  virtual void		generateX();

public:
  explicit		Bot(int id);
  virtual		~Bot();
  virtual void		update();
};

#endif
