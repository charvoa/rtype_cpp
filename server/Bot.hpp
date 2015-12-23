//
// Bot.hh for  in /home/jobertomeu/Work/rtype_cpp/server
//
// Made by Joris Bertomeu
// Login   <jobertomeu@epitech.net>
//
// Started on  Fri Dec 11 16:14:33 2015 Joris Bertomeu
// Last update Wed Dec 23 15:39:01 2015 Nicolas Charvoz
//

#ifndef			_BOT_HH_
# define		_BOT_HH_

# include		<AEntity.hh>
# include		<Random.hpp>
# include		<E_Component.hh>
# include		<map>

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
  Game *currentGame;

  virtual void		generateY();
  virtual void		generateX();
  virtual std::list<Case*> refreshHitbox();

public:
  explicit		Bot(int id);
  virtual		~Bot();
  virtual void		update();
  void			addGame(Game *g) {
    currentGame = g;
  }
};

#endif
