//
// Bot.hh for  in /home/jobertomeu/Work/rtype_cpp/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Fri Dec 11 16:14:33 2015 Joris Bertomeu
// Last update Wed Dec 23 08:08:41 2015 Louis Audibert
//

#ifndef			_BOT_HH_
# define		_BOT_HH_

# include		<map>
# include		<AEntity.hh>
# include		<Random.hpp>
# include		<E_Component.hh>
# include		<Timer.hpp>

# define HEIGHT 855
# define WIDTH 1920

class Game;

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
  Timer *_timerShoot;
  Game *_currentGame;

  virtual void		generateY();
  virtual void		generateX();
  virtual std::list<Case*> refreshHitbox();

public:
  explicit		Bot(int id);
  virtual		~Bot();
  virtual void		update();
  void			addGame(Game *g) {
    _currentGame = g;
  }
};

#endif
