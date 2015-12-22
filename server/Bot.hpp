//
// Bot.hh for  in /home/jobertomeu/Work/rtype_cpp/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Fri Dec 11 16:14:33 2015 Joris Bertomeu
<<<<<<< HEAD
// Last update Tue Dec 22 03:23:54 2015 Serge Heitzler
=======
// Last update Tue Dec 22 03:41:52 2015 Louis Audibert
>>>>>>> 49b093a12f7a3f18d08a428aed8ed12e80af0bcd
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
  bool  _isBoss = false;

private:
  int	_direction;
  int	_x;
  int	_y;
  int	_health;

  virtual void		generateY();
<<<<<<< HEAD
  virtual void		generateX();
=======
  virtual std::list<Case*> refreshHitbox();
>>>>>>> 49b093a12f7a3f18d08a428aed8ed12e80af0bcd

public:
  explicit		Bot(int id);
  virtual		~Bot();
  virtual void		update();
};

#endif
